//  ************************************************************************************************
//
//  qt-mvvm: Model-view-view-model framework for large GUI applications
//
//! @file      mvvm/tests/testviewmodel/viewmodelcontrollerbuilder.test.cpp
//! @brief     Implements class CLASS?
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2020
//! @authors   Gennady Pospelov et al, Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#include "google_test.h"
#include "mvvm/factories/viewmodelcontrollerbuilder.h"
#include "mvvm/model/sessionmodel.h"
#include "mvvm/viewmodel/labeldatarowstrategy.h"
#include "mvvm/viewmodel/standardchildrenstrategies.h"
#include "mvvm/viewmodel/viewmodelbase.h"
#include "mvvm/viewmodel/viewmodelcontroller.h"

using namespace ModelView;

//! Tests of ViewModelController class.

class ViewModelControllerBuilderTest : public ::testing::Test {
public:
    ~ViewModelControllerBuilderTest();
};

ViewModelControllerBuilderTest::~ViewModelControllerBuilderTest() = default;

//! Initial state of the builder.
//! It can't build anything without configuration.

TEST_F(ViewModelControllerBuilderTest, initialState)
{
    EXPECT_THROW(std::unique_ptr<ViewModelController> controller = ViewModelControllerBuilder(),
                 std::runtime_error);
}

TEST_F(ViewModelControllerBuilderTest, allItemsControllerBuild)
{
    SessionModel session_model;
    ViewModelBase view_model;

    std::unique_ptr<ViewModelController> controller =
        ViewModelControllerBuilder()
            .model(&session_model)
            .viewModel(&view_model)
            .childrenStrategy(std::make_unique<AllChildrenStrategy>())
            .rowStrategy(std::make_unique<LabelDataRowStrategy>());
    controller->setRootSessionItem(session_model.rootItem());

    EXPECT_EQ(controller->sessionModel(), &session_model);
    EXPECT_EQ(controller->rootSessionItem(), session_model.rootItem());
    EXPECT_EQ(view_model.columnCount(), 0);
    EXPECT_EQ(view_model.rowCount(), 0);
}
