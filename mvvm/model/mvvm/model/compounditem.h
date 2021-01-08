//  ************************************************************************************************
//
//  qt-mvvm: Model-view-view-model framework for large GUI applications
//
//! @file      mvvm/model/mvvm/model/compounditem.h
//! @brief     Defines class CLASS?
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2020
//! @authors   Gennady Pospelov et al, Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#ifndef BORNAGAIN_MVVM_MODEL_MVVM_MODEL_COMPOUNDITEM_H
#define BORNAGAIN_MVVM_MODEL_MVVM_MODEL_COMPOUNDITEM_H

#include "mvvm/model/customvariants.h"
#include "mvvm/model/propertyitem.h"
#include "mvvm/model/sessionitem.h"
#include "mvvm/model/taginfo.h"
#include "mvvm/utils/reallimits.h"

namespace ModelView {

//! Complex item holding mixed SessionItem types (single properties and other CompountItems).

class MVVM_MODEL_EXPORT CompoundItem : public SessionItem {
public:
    CompoundItem(const std::string& modelType = Constants::CompoundItemType);

    //! Adds property item of given type.
    template <typename T = PropertyItem> T* addProperty(const std::string& name);

    template <typename V> PropertyItem* addProperty(const std::string& name, const V& value);

    //! Register char property. Special case to turn it into std::string.
    PropertyItem* addProperty(const std::string& name, const char* value);

    std::string displayName() const override;
};

template <typename T> T* CompoundItem::addProperty(const std::string& name)
{
    T* property = new T;
    registerTag(TagInfo::propertyTag(name, property->modelType()));
    property->setDisplayName(name);
    insertItem(property, {name, 0});
    return property;
}

inline PropertyItem* CompoundItem::addProperty(const std::string& name, const char* value)
{
    return addProperty(name, std::string(value));
}

template <typename V>
PropertyItem* CompoundItem::addProperty(const std::string& name, const V& value)
{
    auto property = new PropertyItem;
    registerTag(TagInfo::propertyTag(name, property->modelType()));
    property->setDisplayName(name);
    property->setData(value);

    if constexpr (std::is_floating_point_v<V>)
        property->setData(RealLimits::limitless(), ItemDataRole::LIMITS);

    insertItem(property, {name, 0});
    return property;
}

} // namespace ModelView

#endif // BORNAGAIN_MVVM_MODEL_MVVM_MODEL_COMPOUNDITEM_H
