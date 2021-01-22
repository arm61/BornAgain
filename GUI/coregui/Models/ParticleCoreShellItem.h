//  ************************************************************************************************
//
//  BornAgain: simulate and fit reflection and scattering
//
//! @file      GUI/coregui/Models/ParticleCoreShellItem.h
//! @brief     Defines class ParticleCoreShellItem
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#ifndef BORNAGAIN_GUI_COREGUI_MODELS_PARTICLECORESHELLITEM_H
#define BORNAGAIN_GUI_COREGUI_MODELS_PARTICLECORESHELLITEM_H

#include "GUI/coregui/Models/SessionGraphicsItem.h"

class ParticleCoreShell;
class VectorItem;

class BA_CORE_API_ ParticleCoreShellItem : public SessionGraphicsItem {
public:
    static const QString T_CORE;
    static const QString T_SHELL;

    ParticleCoreShellItem();

    VectorItem* positionItem() const;

    std::unique_ptr<ParticleCoreShell> createParticleCoreShell() const;
    QVector<SessionItem*> materialPropertyItems();
};

#endif // BORNAGAIN_GUI_COREGUI_MODELS_PARTICLECORESHELLITEM_H
