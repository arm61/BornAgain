//  ************************************************************************************************
//
//  qt-mvvm: Model-view-view-model framework for large GUI applications
//
//! @file      mvvm/model/mvvm/utils/ifactory.h
//! @brief     Defines class CLASS?
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2020
//! @authors   Gennady Pospelov et al, Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#ifndef BORNAGAIN_MVVM_MODEL_MVVM_UTILS_IFACTORY_H
#define BORNAGAIN_MVVM_MODEL_MVVM_UTILS_IFACTORY_H

#include <functional>
#include <map>
#include <memory>
#include <sstream>
#include <stdexcept>

namespace ModelView {

//! Base for factories.

template <class Key, class Value> class IFactory {
public:
    using function_t = std::function<std::unique_ptr<Value>()>;
    using map_t = std::map<Key, function_t>;

    bool contains(const Key& item_key) const { return m_data.find(item_key) != m_data.end(); }

    std::unique_ptr<Value> create(const Key& item_key) const
    {
        auto it = m_data.find(item_key);
        if (it == m_data.end()) {
            std::ostringstream message;
            message << "IFactory::createItem() -> Error. Unknown item key '" << item_key << "'";
            throw std::runtime_error(message.str());
        }
        return it->second();
    }

    bool add(const Key& key, function_t func)
    {
        if (m_data.find(key) != m_data.end()) {
            std::ostringstream message;
            message << "IFactory::createItem() -> Already registered item key '" << key << "'";
            throw std::runtime_error(message.str());
        }
        return m_data.insert(make_pair(key, func)).second;
    }

    size_t size() const { return m_data.size(); }

    typename map_t::iterator begin() { return m_data.begin(); }
    typename map_t::iterator end() { return m_data.end(); }

private:
    map_t m_data;
};

} // namespace ModelView

#endif // BORNAGAIN_MVVM_MODEL_MVVM_UTILS_IFACTORY_H
