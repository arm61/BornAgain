// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Samples/src/InterferenceFunction2DLattice.cpp
//! @brief     Implements class InterferenceFunction2DLattice.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "InterferenceFunction2DLattice.h"
#include "BornAgainNamespace.h"

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter)
#include <boost/math/special_functions/round.hpp>
GCC_DIAG_ON(unused-parameter)

InterferenceFunction2DLattice::InterferenceFunction2DLattice(double length_1, double length_2,
                                                             double angle, double xi)
    : mp_pdf(0), m_prefactor(1.0), m_na(0), m_nb(0)
{
    m_lattice_params.m_length_1 = length_1;
    m_lattice_params.m_length_2 = length_2;
    m_lattice_params.m_angle = angle;
    m_lattice_params.m_xi = xi;
    setName(BornAgain::InterferenceFunction2DLatticeType);
    init_parameters();
    initialize_rec_vectors();
}

InterferenceFunction2DLattice::~InterferenceFunction2DLattice()
{
    delete mp_pdf;
}

InterferenceFunction2DLattice *InterferenceFunction2DLattice::clone() const
{
    InterferenceFunction2DLattice *result = new InterferenceFunction2DLattice(m_lattice_params);
    if (mp_pdf)
        result->setProbabilityDistribution(*mp_pdf);
    result->setName(getName());
    return result;
}

void InterferenceFunction2DLattice::accept(ISampleVisitor *visitor) const
{
    visitor->visit(this);
}

InterferenceFunction2DLattice *InterferenceFunction2DLattice::createSquare(double lattice_length,
                                                                           double xi)
{
    Lattice2DIFParameters lattice_params;
    lattice_params.m_length_1 = lattice_length;
    lattice_params.m_length_2 = lattice_length;
    lattice_params.m_angle = Units::PI / 2.0;
    lattice_params.m_xi = xi;
    return new InterferenceFunction2DLattice(lattice_params);
}

InterferenceFunction2DLattice *InterferenceFunction2DLattice::createHexagonal(double lattice_length,
                                                                              double xi)
{
    Lattice2DIFParameters lattice_params;
    lattice_params.m_length_1 = lattice_length;
    lattice_params.m_length_2 = lattice_length;
    lattice_params.m_angle = 2.0 * Units::PI / 3.0;
    lattice_params.m_xi = xi;
    return new InterferenceFunction2DLattice(lattice_params);
}

void InterferenceFunction2DLattice::setProbabilityDistribution(const IFTDistribution2D &pdf)
{
    if (mp_pdf != &pdf)
        delete mp_pdf;
    mp_pdf = pdf.clone();
    double coherence_length_x = mp_pdf->getCoherenceLengthX();
    double coherence_length_y = mp_pdf->getCoherenceLengthY();
    initialize_calc_factors(coherence_length_x, coherence_length_y);
}

const IFTDistribution2D *InterferenceFunction2DLattice::getProbabilityDistribution() const
{
    return mp_pdf;
}

double InterferenceFunction2DLattice::evaluate(const kvector_t &q) const
{
    if (!mp_pdf) {
        throw NullPointerException("InterferenceFunction2DLattice::evaluate"
                                   " -> Error! No probability distribution function defined.");
    }
    double result = 0.0;
    double qxr = q.x();
    double qyr = q.y();
    double qx_frac, qy_frac;
    calculateReciprocalVectorFraction(qxr, qyr, qx_frac, qy_frac);

    for (int i = -m_na - 1; i < m_na + 2; ++i) {
        for (int j = -m_nb - 1; j < m_nb + 2; ++j) {
            double qx = qx_frac + i * m_asx + j * m_bsx;
            double qy = qy_frac + i * m_asy + j * m_bsy;
            result += interferenceAtOneRecLatticePoint(qx, qy);
        }
    }
    return m_prefactor * result;
}

Lattice2DIFParameters InterferenceFunction2DLattice::getLatticeParameters() const
{
    return m_lattice_params;
}

double InterferenceFunction2DLattice::interferenceAtOneRecLatticePoint(double qx, double qy) const
{
    if (!mp_pdf) {
        throw NullPointerException("InterferenceFunction2DLattice::interferenceAtOneRecLatticePoint"
                                   " -> Error! No probability distribution function defined.");
    }
    double qp1, qp2;
    double gamma = m_lattice_params.m_xi + mp_pdf->getGamma();
    double delta = mp_pdf->getDelta();
    transformToPrincipalAxes(qx, qy, gamma, delta, qp1, qp2);
    return mp_pdf->evaluateLattice(qp1, qp2);
}

void InterferenceFunction2DLattice::transformToPrincipalAxes(double qx, double qy, double gamma,
                                                             double delta, double &q_pa_1,
                                                             double &q_pa_2) const
{
    q_pa_1 = qx * std::cos(gamma) + qy * std::sin(gamma);
    q_pa_2 = qx * std::cos(gamma + delta) + qy * std::sin(gamma + delta);
}

void InterferenceFunction2DLattice::calculateReciprocalVectorFraction(double qx, double qy,
                                                                      double &qx_frac,
                                                                      double &qy_frac) const
{
    double a = m_lattice_params.m_length_1;
    double b = m_lattice_params.m_length_2;
    double xi = m_lattice_params.m_xi;
    double xialpha = xi + m_lattice_params.m_angle;
    int qa_int = boost::math::iround(a * (qx * std::cos(xi) + qy * std::sin(xi)) / Units::PI2);
    int qb_int
        = boost::math::iround(b * (qx * std::cos(xialpha) + qy * std::sin(xialpha)) / Units::PI2);
    qx_frac = qx - qa_int * m_asx - qb_int * m_bsx;
    qy_frac = qy - qa_int * m_asy - qb_int * m_bsy;
}

InterferenceFunction2DLattice::InterferenceFunction2DLattice(
    const Lattice2DIFParameters &lattice_params)
    : m_lattice_params(lattice_params), mp_pdf(0), m_prefactor(1.0), m_na(0), m_nb(0)
{
    setName(BornAgain::InterferenceFunction2DLatticeType);
    init_parameters();
    initialize_rec_vectors();
}

void InterferenceFunction2DLattice::init_parameters()
{
    clearParameterPool();
    registerParameter("length_1", &m_lattice_params.m_length_1);
    registerParameter("length_2", &m_lattice_params.m_length_2);
    registerParameter("angle", &m_lattice_params.m_angle);
    registerParameter("xi", &m_lattice_params.m_xi);
}

void InterferenceFunction2DLattice::initialize_rec_vectors()
{
    if (m_lattice_params.m_length_1 == 0 || m_lattice_params.m_length_2 == 0) {
        throw DivisionByZeroException("InterferenceFunction2DLattice::"
                                      "initialize_rec_vectors() -> Error! Zero parameters"
                                      " m_lattice_params.m_length1 or m_lattice_params.m_length_2");
    }
    double sinalpha = std::sin(m_lattice_params.m_angle);
    double ainv = Units::PI2 / m_lattice_params.m_length_1 / sinalpha;
    double binv = Units::PI2 / m_lattice_params.m_length_2 / sinalpha;
    double xi = m_lattice_params.m_xi;
    double xialpha = xi + m_lattice_params.m_angle;
    m_asx = ainv * std::sin(xialpha);
    m_asy = -ainv * std::cos(xialpha);
    m_bsx = -binv * std::sin(xi);
    m_bsy = binv * std::cos(xi);
}

void InterferenceFunction2DLattice::initialize_calc_factors(double coherence_length_x,
                                                            double coherence_length_y)
{
    if (!mp_pdf) {
        throw NullPointerException("InterferenceFunction2DLattice::initialize_calc_factors"
                                   " -> Error! No probability distribution function defined.");
    }

    // constant prefactor
    // TODO: for non 2D distributions: check if this still applies
    m_prefactor = Units::PI2 * coherence_length_x * coherence_length_y;

    // number of reciprocal lattice points to use
    double qa_max, qb_max;
    mp_pdf->transformToStarBasis(nmax / coherence_length_x, nmax / coherence_length_y,
                                 m_lattice_params.m_angle, m_lattice_params.m_length_1,
                                 m_lattice_params.m_length_2, qa_max, qb_max);
    m_na = boost::math::iround(std::abs(qa_max));
    m_nb = boost::math::iround(std::abs(qb_max));
}
