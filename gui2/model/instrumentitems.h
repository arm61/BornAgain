//  ************************************************************************************************
//
//  BornAgain: simulate and fit reflection and scattering
//
//! @file      gui2/model/instrumentitems.h
//! @brief     Defines class CLASS?
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2020
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#ifndef BORNAGAIN_GUI2_MODEL_INSTRUMENTITEMS_H
#define BORNAGAIN_GUI2_MODEL_INSTRUMENTITEMS_H

//! @file gui2/model/instrumentitems.h
//! Collection of items to construct specular instrument.

#include "darefl_export.h"
#include "mvvm/model/compounditem.h"
#include "mvvm/model/groupitem.h"

namespace ModelView {
class GraphItem;
}

namespace gui2 {

//! Represents base type for beam scan parameters.

class DAREFLCORE_EXPORT BasicSpecularScanItem : public ModelView::CompoundItem {
public:
    BasicSpecularScanItem(const std::string& model_type);
    virtual std::vector<double> qScanValues() const = 0;
};

//! Represents Q-space specular scan with fixed bin size.

class DAREFLCORE_EXPORT QSpecScanItem : public BasicSpecularScanItem {
public:
    static inline const std::string P_NBINS = "P_NBINS";
    static inline const std::string P_QMIN = "P_QMIN";
    static inline const std::string P_QMAX = "P_QMAX";
    QSpecScanItem();

    std::vector<double> qScanValues() const override;
};

//! Represents scan according to imported experimental data.

class DAREFLCORE_EXPORT ExperimentalScanItem : public BasicSpecularScanItem {
public:
    static inline const std::string P_IMPORTED_DATA = "P_IMPORTED_DATA";
    ExperimentalScanItem();

    void setGraphItem(ModelView::GraphItem* graph);

    ModelView::GraphItem* graphItem() const;

    std::vector<double> qScanValues() const override;
};

//! Represent selection of possible specular scans.

class DAREFLCORE_EXPORT SpecularScanGroupItem : public ModelView::GroupItem {
public:
    SpecularScanGroupItem();
};

//! Represents specular beam, contains settings of scan parameters.

class DAREFLCORE_EXPORT SpecularBeamItem : public ModelView::CompoundItem {
public:
    static inline const std::string P_INTENSITY = "P_INTENSITY";
    static inline const std::string P_SCAN_GROUP = "P_SCAN_GROUP";

    SpecularBeamItem();

    std::vector<double> qScanValues() const;

    double intensity() const;

    ModelView::GraphItem* experimentalGraphItem() const;
};

//! Represents specular instrument.

class DAREFLCORE_EXPORT SpecularInstrumentItem : public ModelView::CompoundItem {
public:
    static inline const std::string P_BEAM = "P_BEAM";

    SpecularInstrumentItem();

    SpecularBeamItem* beamItem() const;
};

} // namespace gui2

#endif // BORNAGAIN_GUI2_MODEL_INSTRUMENTITEMS_H
