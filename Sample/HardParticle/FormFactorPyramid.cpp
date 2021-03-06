//  ************************************************************************************************
//
//  BornAgain: simulate and fit reflection and scattering
//
//! @file      Sample/HardParticle/FormFactorPyramid.cpp
//! @brief     Implements class FormFactorPyramid.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#include "Sample/HardParticle/FormFactorPyramid.h"
#include "Base/Math/Constants.h"
#include "Base/Math/Functions.h"

const PolyhedralTopology FormFactorPyramid::topology = {{
                                                            {{3, 2, 1, 0}, true}, // TODO -> true
                                                            {{0, 1, 5, 4}, false},
                                                            {{1, 2, 6, 5}, false},
                                                            {{2, 3, 7, 6}, false},
                                                            {{3, 0, 4, 7}, false},
                                                            {{4, 5, 6, 7}, true} // TODO -> true
                                                        },
                                                        false};

FormFactorPyramid::FormFactorPyramid(const std::vector<double> P)
    : IFormFactorPolyhedron({"Pyramid",
                             "frustum with quadratic base",
                             {{"BaseEdge", "nm", "base edge length", 0, +INF, 0},
                              {"Height", "nm", "height", 0, +INF, 0},
                              {"Alpha", "rad", "angle between base and a side face", 0., M_PI, 0}}},
                            P)
    , m_base_edge(m_P[0])
    , m_height(m_P[1])
    , m_alpha(m_P[2])
{
    onChange();
}

FormFactorPyramid::FormFactorPyramid(double base_edge, double height, double alpha)
    : FormFactorPyramid(std::vector<double>{base_edge, height, alpha})
{
}

IFormFactor* FormFactorPyramid::sliceFormFactor(ZLimits limits, const IRotation& rot,
                                                kvector_t translation) const
{
    auto effects = computeSlicingEffects(limits, translation, m_height);
    double dbase_edge = 2 * effects.dz_bottom * Math::cot(m_alpha);
    FormFactorPyramid slicedff(m_base_edge - dbase_edge,
                               m_height - effects.dz_bottom - effects.dz_top, m_alpha);
    return createTransformedFormFactor(slicedff, rot, effects.position);
}

void FormFactorPyramid::onChange()
{
    double cot_alpha = Math::cot(m_alpha);
    if (!std::isfinite(cot_alpha))
        throw std::runtime_error("pyramid angle alpha out of bounds");
    double r = cot_alpha * 2 * m_height / m_base_edge; // [L(base)-L(top)]/L(base)
    if (r > 1) {
        std::ostringstream ostr;
        ostr << "FormFactorPyramid() -> Error in class initialization with parameters";
        ostr << " base_edge:" << m_base_edge;
        ostr << " height:" << m_height;
        ostr << " alpha[rad]:" << m_alpha << "\n\n";
        ostr << "Check for 'height <= base_edge*tan(alpha)' failed.";
        throw std::runtime_error(ostr.str());
    }

    double a = m_base_edge / 2;
    double b = a * (1 - r);

    double zcom = m_height * (.5 - 2 * r / 3 + r * r / 4) / (1 - r + r * r / 3); // center of mass

    setPolyhedron(topology, -zcom,
                  {// base:
                   {-a, -a, -zcom},
                   {a, -a, -zcom},
                   {a, a, -zcom},
                   {-a, a, -zcom},
                   // top:
                   {-b, -b, m_height - zcom},
                   {b, -b, m_height - zcom},
                   {b, b, m_height - zcom},
                   {-b, b, m_height - zcom}});
}
