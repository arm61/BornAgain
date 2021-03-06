//  ************************************************************************************************
//
//  BornAgain: simulate and fit reflection and scattering
//
//! @file      GUI/coregui/Models/VectorItem.h
//! @brief     Defines class VectorItem
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#ifndef BORNAGAIN_GUI_COREGUI_MODELS_VECTORITEM_H
#define BORNAGAIN_GUI_COREGUI_MODELS_VECTORITEM_H

#include "Base/Vector/Vectors3D.h"
#include "GUI/coregui/Models/SessionItem.h"

class BA_CORE_API_ VectorItem : public SessionItem {

public:
    static const QString P_X;
    static const QString P_Y;
    static const QString P_Z;
    VectorItem();

    double x() const;
    void setX(double value);

    double y() const;
    void setY(double value);

    double z() const;
    void setZ(double value);

    void setXYZ(double x_value, double y_value, double z_value);

    kvector_t getVector() const;
    void setVector(const kvector_t& vec);

private:
    void updateLabel();
};

#endif // BORNAGAIN_GUI_COREGUI_MODELS_VECTORITEM_H
