//  ************************************************************************************************
//
//  BornAgain: simulate and fit reflection and scattering
//
//! @file      gui2/quicksimeditor/materialprofile.cpp
//! @brief     Implements class CLASS?
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2020
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#include "gui2/quicksimeditor/materialprofile.h"
#include "gui2/quicksimeditor/profilehelper.h"
#include "gui2/quicksimeditor/quicksimutils.h"
#include <Sample/Slice/Slice.h>

namespace gui2 {

std::vector<complex_t> MaterialProfile::CalculateProfile(const multislice_t& multilayer,
                                                         int n_points, double z_min, double z_max)
{
    auto baSlices = Utils::createBornAgainSlices(multilayer);
    ProfileHelper helper(baSlices);
    std::vector<double> z_values = GenerateZValues(n_points, z_min, z_max);
    return helper.calculateProfile(z_values);
}

std::pair<double, double>
MaterialProfile::DefaultMaterialProfileLimits(const multislice_t& multilayer)
{
    auto baSlices = Utils::createBornAgainSlices(multilayer);
    ProfileHelper helper(baSlices);
    return helper.defaultLimits();
}

std::vector<double> MaterialProfile::GenerateZValues(int n_points, double z_min, double z_max)
{
    std::vector<double> result;
    if (n_points < 1)
        return result;
    double step = n_points > 1 ? (z_max - z_min) / (n_points - 1) : 0.0;
    for (int i = 0; i < n_points; ++i) {
        result.push_back(z_min + i * step);
    }
    return result;
}

} // namespace gui2
