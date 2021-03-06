//  ************************************************************************************************
//
//  qt-mvvm: Model-view-view-model framework for large GUI applications
//
//! @file      mvvm/model/mvvm/signals/callback_types.h
//! @brief     Defines class CLASS?
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2020
//! @authors   Gennady Pospelov et al, Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#ifndef BORNAGAIN_MVVM_MODEL_MVVM_SIGNALS_CALLBACK_TYPES_H
#define BORNAGAIN_MVVM_MODEL_MVVM_SIGNALS_CALLBACK_TYPES_H

#include "mvvm/model/tagrow.h"
#include <functional>
#include <string>

namespace ModelView {

class SessionItem;
class SessionModel;

namespace Callbacks {
using slot_t = const void*;
using item_t = std::function<void(SessionItem*)>;
using item_int_t = std::function<void(SessionItem*, int)>;
using item_str_t = std::function<void(SessionItem*, std::string)>;
using item_tagrow_t = std::function<void(SessionItem*, TagRow)>;
using model_t = std::function<void(SessionModel*)>;
} // namespace Callbacks

} // namespace ModelView

#endif // BORNAGAIN_MVVM_MODEL_MVVM_SIGNALS_CALLBACK_TYPES_H
