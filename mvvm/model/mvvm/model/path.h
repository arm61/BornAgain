//  ************************************************************************************************
//
//  qt-mvvm: Model-view-view-model framework for large GUI applications
//
//! @file      mvvm/model/mvvm/model/path.h
//! @brief     Defines class CLASS?
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2020
//! @authors   Gennady Pospelov et al, Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#ifndef BORNAGAIN_MVVM_MODEL_MVVM_MODEL_PATH_H
#define BORNAGAIN_MVVM_MODEL_MVVM_MODEL_PATH_H

#include "mvvm/model_export.h"
#include <string>
#include <vector>

namespace ModelView {

//! Supports navigation through SessionModel. Contains a chain of indexes that have to
//! be used to reach the desired SessionItem starting from the root item. Path class plays
//! a role of simplified QModelIndex for SessionModel. Used for undo/redo only.

//! Example of tree:
//! - root              path:""
//!   - child           path:"0"
//!     - grandchild    path:"0,0"
//!     - grandchild    path:"0,1"
//!   - child           path:"1"

class MVVM_MODEL_EXPORT Path {
public:
    using PathElement = int;
    using container_t = std::vector<PathElement>;
    using iterator = container_t::iterator;
    using const_iterator = container_t::const_iterator;

    Path() = default;

    static Path fromString(const std::string& str);

    static Path fromVector(const std::vector<int>& data);

    std::string str() const;

    void append(PathElement element);
    void prepend(PathElement element);

    iterator begin();
    const_iterator begin() const;

    iterator end();
    const_iterator end() const;

private:
    container_t m_data;
};

} // namespace ModelView

#endif // BORNAGAIN_MVVM_MODEL_MVVM_MODEL_PATH_H
