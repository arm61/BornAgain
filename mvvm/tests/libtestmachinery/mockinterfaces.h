//  ************************************************************************************************
//
//  qt-mvvm: Model-view-view-model framework for large GUI applications
//
//! @file      mvvm/tests/libtestmachinery/mockinterfaces.h
//! @brief     Defines class CLASS?
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2020
//! @authors   Gennady Pospelov et al, Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#ifndef BORNAGAIN_MVVM_TESTS_LIBTESTMACHINERY_MOCKINTERFACES_H
#define BORNAGAIN_MVVM_TESTS_LIBTESTMACHINERY_MOCKINTERFACES_H

#include "mvvm/model/tagrow.h"
#include <string>

//! Various common utils for unit tests.

namespace ModelView {
class SessionItem;
class SessionModel;
} // namespace ModelView

//! Interface for testing callbacks comming from SessionItem within gmock framework.

class ItemTestWidgetInterface {
public:
    virtual ~ItemTestWidgetInterface() = default;

    virtual void onItemDestroy(ModelView::SessionItem* item) = 0;
    virtual void onDataChange(ModelView::SessionItem* item, int role) = 0;
    virtual void onPropertyChange(ModelView::SessionItem* item, std::string name) = 0;
    virtual void onItemInserted(ModelView::SessionItem* item, ModelView::TagRow) = 0;
    virtual void onAboutToRemoveItem(ModelView::SessionItem* item, ModelView::TagRow) = 0;
};

//! Interface for testing callbacks comming from SessionModel within gmock framework.

class ModelTestWidgetInterface {
public:
    virtual ~ModelTestWidgetInterface() = default;

    virtual void onModelDestroyed(ModelView::SessionModel*) = 0;
    virtual void onModelAboutToBeReset(ModelView::SessionModel*) = 0;
    virtual void onModelReset(ModelView::SessionModel*) = 0;
    virtual void onDataChange(ModelView::SessionItem*, int) = 0;
    virtual void onItemInserted(ModelView::SessionItem*, ModelView::TagRow) = 0;
    virtual void onItemRemoved(ModelView::SessionItem*, ModelView::TagRow) = 0;
    virtual void onAboutToRemoveItem(ModelView::SessionItem*, ModelView::TagRow) = 0;
};

#endif // BORNAGAIN_MVVM_TESTS_LIBTESTMACHINERY_MOCKINTERFACES_H
