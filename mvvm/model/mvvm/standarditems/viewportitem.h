//  ************************************************************************************************
//
//  qt-mvvm: Model-view-view-model framework for large GUI applications
//
//! @file      mvvm/model/mvvm/standarditems/viewportitem.h
//! @brief     Defines class CLASS?
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2020
//! @authors   Gennady Pospelov et al, Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#ifndef BORNAGAIN_MVVM_MODEL_MVVM_STANDARDITEMS_VIEWPORTITEM_H
#define BORNAGAIN_MVVM_MODEL_MVVM_STANDARDITEMS_VIEWPORTITEM_H

#include "mvvm/model/compounditem.h"

namespace ModelView {

class ViewportAxisItem;

//! Base class to represent 2D viewport.
//! Contains x,y axis, indended to display graphs or 2d colormaps.

class MVVM_MODEL_EXPORT ViewportItem : public CompoundItem {
public:
    static inline const std::string P_XAXIS = "P_XAXIS";
    static inline const std::string P_YAXIS = "P_YAXIS";
    static inline const std::string T_ITEMS = "T_ITEMS";

    ViewportItem(const model_type& model);

    ViewportAxisItem* xAxis() const;

    ViewportAxisItem* yAxis() const;

    virtual void setViewportToContent(double left, double top, double right, double bottom);

    virtual void setViewportToContent();

protected:
    void register_xy_axes();

protected:
    virtual std::pair<double, double> data_xaxis_range() const = 0;
    virtual std::pair<double, double> data_yaxis_range() const = 0;
};

} // namespace ModelView

#endif // BORNAGAIN_MVVM_MODEL_MVVM_STANDARDITEMS_VIEWPORTITEM_H
