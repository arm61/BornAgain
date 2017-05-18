// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Aggregate/FTDistributions2D.cpp
//! @brief     Implements interface class IFTDistribution2D and children thereof.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "FTDistributions2D.h"
#include "BornAgainNamespace.h"
#include "IntegratorReal.h"
#include "MathFunctions.h"
#include "ParameterPool.h"
#include "MathConstants.h"
#include "RealParameter.h"
#include <limits>

IFTDistribution2D::IFTDistribution2D(double omega_x, double omega_y, double gamma)
    : m_omega_x(omega_x)
    , m_omega_y(omega_y)
    , m_gamma(gamma)
    , m_delta(M_PI_2)
{}

double IFTDistribution2D::sumsq(double qx, double qy) const
{
    return qx*qx*m_omega_x*m_omega_x + qy*qy*m_omega_y*m_omega_y;
}

void IFTDistribution2D::register_omega()
{
    registerParameter(BornAgain::OmegaX, &m_omega_x).setUnit("nm").setNonnegative();
    registerParameter(BornAgain::OmegaY, &m_omega_y).setUnit("nm").setNonnegative();
}

void IFTDistribution2D::register_gamma()
{
    registerParameter(BornAgain::Gamma, &m_gamma).setUnit("rad").setLimited(-M_PI_2, M_PI_2);
}

void IFTDistribution2D::init_parameters()
{
    register_omega();
    register_gamma();
}

void IFTDistribution2D::print(std::ostream& ostr) const
{
    ostr << getName() << " " << *parameterPool();
}


FTDistribution2DCauchy::FTDistribution2DCauchy(double omega_x, double omega_y, double gamma)
    : IFTDistribution2D(omega_x, omega_y, gamma)
{
    setName(BornAgain::FTDistribution2DCauchyType);
    init_parameters();
}

FTDistribution2DCauchy* FTDistribution2DCauchy::clone() const
{
    return new FTDistribution2DCauchy(m_omega_x, m_omega_y, m_gamma);
}

double FTDistribution2DCauchy::evaluate(double qx, double qy) const
{
    return std::pow(1.0 + sumsq(qx,qy), -1.5);
}


FTDistribution2DGauss::FTDistribution2DGauss(double omega_x, double omega_y, double gamma)
    : IFTDistribution2D(omega_x, omega_y, gamma)
{
    setName(BornAgain::FTDistribution2DGaussType);
    init_parameters();
}

FTDistribution2DGauss* FTDistribution2DGauss::clone() const
{
    return new FTDistribution2DGauss(m_omega_x, m_omega_y, m_gamma);
}

double FTDistribution2DGauss::evaluate(double qx, double qy) const
{
    return std::exp(-sumsq(qx,qy)/2);
}


FTDistribution2DGate::FTDistribution2DGate(double omega_x, double omega_y, double gamma)
    : IFTDistribution2D(omega_x, omega_y, gamma)
{
    setName(BornAgain::FTDistribution2DGateType);
    init_parameters();
}

FTDistribution2DGate* FTDistribution2DGate::clone() const
{
    return new FTDistribution2DGate(m_omega_x, m_omega_y, m_gamma);
}

double FTDistribution2DGate::evaluate(double qx, double qy) const
{
    double scaled_q = std::sqrt(sumsq(qx,qy));
    return MathFunctions::Bessel_J1c(scaled_q)*2.0;
}


FTDistribution2DCone::FTDistribution2DCone(double omega_x, double omega_y, double gamma)
    : IFTDistribution2D(omega_x, omega_y, gamma)
{
    setName(BornAgain::FTDistribution2DConeType);
    init_parameters();
}

FTDistribution2DCone* FTDistribution2DCone::clone() const
{
    return new FTDistribution2DCone(m_omega_x, m_omega_y, m_gamma);
}

double FTDistribution2DCone::evaluate(double qx, double qy) const
{
    double scaled_q = std::sqrt(sumsq(qx,qy));
    if (scaled_q<std::numeric_limits<double>::epsilon())
        return 1.0 - 3.0*scaled_q*scaled_q/40.0;
    auto integrator = make_integrator_real(this, &FTDistribution2DCone::coneIntegrand2);
    double integral = integrator->integrate(0.0, scaled_q);
    return 6.0*(MathFunctions::Bessel_J1c(scaled_q) - integral/scaled_q/scaled_q/scaled_q);
}

double FTDistribution2DCone::coneIntegrand2(double value) const
{
    return value*value*MathFunctions::Bessel_J0(value);
}


FTDistribution2DVoigt::FTDistribution2DVoigt(double omega_x, double omega_y,
                                             double eta, double gamma)
    : IFTDistribution2D(omega_x, omega_y, gamma), m_eta(eta)
{
    setName(BornAgain::FTDistribution2DVoigtType);
    register_omega();
    registerParameter(BornAgain::Eta, &m_eta);
    register_gamma();
}

FTDistribution2DVoigt* FTDistribution2DVoigt::clone() const
{
    return new FTDistribution2DVoigt(m_omega_x, m_omega_y, m_eta, m_gamma);
}

double FTDistribution2DVoigt::evaluate(double qx, double qy) const
{
    double sum_sq = sumsq(qx,qy);
    return m_eta*std::exp(-sum_sq/2) + (1.0 - m_eta)*std::pow(1.0 + sum_sq, -1.5);
}
