// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Tests/Functional/Core/CoreSpecial/CoreIOPathTest.h
//! @brief     Defines CoreIOTest class
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef BORNAGAIN_TESTS_FUNCTIONAL_CORE_CORESPECIAL_COREIOPATHTEST_H
#define BORNAGAIN_TESTS_FUNCTIONAL_CORE_CORESPECIAL_COREIOPATHTEST_H

#include "Tests/Functional/TestMachinery/IFunctionalTest.h"

//! Functional test to validate read/write to files containing non-ascii characters in a path.

class CoreIOPathTest : public IFunctionalTest
{
public:
    CoreIOPathTest();

    bool runTest();
};

#endif // BORNAGAIN_TESTS_FUNCTIONAL_CORE_CORESPECIAL_COREIOPATHTEST_H