//  ************************************************************************************************
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Fit/Adapter/Report.h
//! @brief     Declares report namespace.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#ifndef BORNAGAIN_FIT_ADAPTER_REPORT_H
#define BORNAGAIN_FIT_ADAPTER_REPORT_H

#include <string>

class MinimizerAdapter;

//! Utility functions to generate reports

namespace report
{

//! Reports results of minimization in the form of multi-line string
std::string reportToString(const MinimizerAdapter& minimizer);

}; // namespace report

#endif // BORNAGAIN_FIT_ADAPTER_REPORT_H
