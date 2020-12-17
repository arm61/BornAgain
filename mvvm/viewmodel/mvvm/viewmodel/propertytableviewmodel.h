//  ************************************************************************************************
//
//  qt-mvvm: Model-view-view-model framework for large GUI applications
//
//! @file      mvvm/viewmodel/mvvm/viewmodel/propertytableviewmodel.h
//! @brief     Defines class CLASS?
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2020
//! @authors   Gennady Pospelov et al, Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#ifndef BORNAGAIN_MVVM_VIEWMODEL_MVVM_VIEWMODEL_PROPERTYTABLEVIEWMODEL_H
#define BORNAGAIN_MVVM_VIEWMODEL_MVVM_VIEWMODEL_PROPERTYTABLEVIEWMODEL_H

#include "mvvm/viewmodel/viewmodel.h"

namespace ModelView {

//! View model to show content of SessionModel in Qt widgets: all item properties as a table row.

//! Intended to show registered properties of items in table-like view.
//! Registered properties will form columns of the table, top level items will form table rows.

class MVVM_VIEWMODEL_EXPORT PropertyTableViewModel : public ViewModel {
    Q_OBJECT
public:
    PropertyTableViewModel(SessionModel* model, QObject* parent = nullptr);
};

} // namespace ModelView

#endif // BORNAGAIN_MVVM_VIEWMODEL_MVVM_VIEWMODEL_PROPERTYTABLEVIEWMODEL_H
