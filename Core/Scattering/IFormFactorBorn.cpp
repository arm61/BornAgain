// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Scattering/IFormFactorBorn.cpp
//! @brief     Implements interface class IFormFactorBorn.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "Core/Scattering/IFormFactorBorn.h"
#include "Core/Basics/Algorithms.h"
#include "Core/Basics/Exceptions.h"
#include "Core/Scattering/Rotations.h"
#include "Core/Vector/WavevectorInfo.h"

complex_t IFormFactorBorn::evaluate(const WavevectorInfo& wavevectors) const
{
    return evaluate_for_q(wavevectors.getQ());
}

Eigen::Matrix2cd IFormFactorBorn::evaluatePol(const WavevectorInfo& wavevectors) const
{
    return evaluate_for_q_pol(wavevectors.getQ());
}

double IFormFactorBorn::bottomZ(const IRotation& rotation) const
{
    if (!mP_shape)
        return 0;
    return BottomZ(mP_shape->vertices(), rotation.getTransform3D());
}

double IFormFactorBorn::topZ(const IRotation& rotation) const
{
    if (!mP_shape)
        return 0;
    return TopZ(mP_shape->vertices(), rotation.getTransform3D());
}

bool IFormFactorBorn::canSliceAnalytically(const IRotation& rot) const
{
    if (IsZRotation(rot))
        return true;
    return false;
}

Eigen::Matrix2cd IFormFactorBorn::evaluate_for_q_pol(cvector_t q) const
{
    return evaluate_for_q(q) * Eigen::Matrix2cd::Identity();
}

SlicingEffects IFormFactorBorn::computeSlicingEffects(ZLimits limits, const kvector_t& position,
                                                      double height) const
{
    kvector_t new_position(position);
    double z_bottom = position.z();
    double z_top = position.z() + height;
    OneSidedLimit lower_limit = limits.lowerLimit();
    OneSidedLimit upper_limit = limits.upperLimit();
    if (!upper_limit.m_limitless && !lower_limit.m_limitless
        && lower_limit.m_value > upper_limit.m_value)
        throw std::runtime_error(getName()
                                 + "::sliceFormFactor error: "
                                   "upperlimit < lowerlimit.");
    double dz_top = upper_limit.m_limitless ? -1 : z_top - upper_limit.m_value;
    double dz_bottom = lower_limit.m_limitless ? -1 : lower_limit.m_value - z_bottom;
    if (dz_top < 0 && dz_bottom < 0)
        throw std::runtime_error(getName()
                                 + "::sliceFormFactor error: "
                                   "shape didn't need to be sliced.");
    if (dz_bottom > height)
        throw std::runtime_error(getName()
                                 + "::sliceFormFactor error: "
                                   "interface outside shape.");
    if (dz_top > height)
        throw std::runtime_error(getName()
                                 + "::sliceFormFactor error: "
                                   "interface outside shape.");
    if (dz_bottom < 0)
        dz_bottom = 0;
    if (dz_top < 0)
        dz_top = 0;
    if (dz_bottom > 0)
        new_position.setZ(lower_limit.m_value);
    return {new_position, dz_bottom, dz_top};
}



double IFormFactorBorn::BottomZ(const std::vector<kvector_t>& vertices, const Transform3D& rotation)
{
    if (vertices.size() == 0)
        throw std::runtime_error("BottomZ() error: no vertices passed!");
    return algo::min_value(vertices.begin(), vertices.end(),
                           [&](const kvector_t& vertex) -> double
                               { return rotation.transformed(vertex).z(); });
}

double IFormFactorBorn::TopZ(const std::vector<kvector_t>& vertices, const Transform3D& rotation)
{
    if (vertices.size() == 0)
        throw std::runtime_error("TopZ() error: no vertices passed!");
    return algo::max_value(vertices.begin(), vertices.end(),
                           [&](const kvector_t& vertex) -> double
                               { return rotation.transformed(vertex).z(); });
}
