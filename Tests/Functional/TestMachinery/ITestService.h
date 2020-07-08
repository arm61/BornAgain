// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Tests/Functional/TestMachinery/ITestService.h
//! @brief     Defines class ITestService.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef BORNAGAIN_TESTS_FUNCTIONAL_TESTMACHINERY_ITESTSERVICE_H
#define BORNAGAIN_TESTS_FUNCTIONAL_TESTMACHINERY_ITESTSERVICE_H

#include "Wrap/WinDllMacros.h"

//! @class ITestService
//! @ingroup standard_samples
//! @brief Interface class to run groups of functional tests via standalone executable steered
//! using command line parameters.

class BA_CORE_API_ ITestService
{
public:
    ITestService() {}
    virtual ~ITestService();
    virtual bool execute(int argc, char** argv) = 0;
};

#endif // BORNAGAIN_TESTS_FUNCTIONAL_TESTMACHINERY_ITESTSERVICE_H