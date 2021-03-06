//  ************************************************************************************************
//
//  BornAgain: simulate and fit reflection and scattering
//
//! @file      GUI/coregui/Views/SpecularDataWidgets/SpecularDataImportWidget.h
//! @brief     Defines class SpecularDataImportWidget
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2021
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#ifndef BORNAGAIN_GUI_COREGUI_VIEWS_SPECULARDATAWIDGETS_SPECULARDATAIMPORTWIDGET_H
#define BORNAGAIN_GUI_COREGUI_VIEWS_SPECULARDATAWIDGETS_SPECULARDATAIMPORTWIDGET_H

#include "GUI/coregui/DataLoaders/AbstractDataLoader1D.h"
#include "GUI/coregui/Views/CommonWidgets/SessionItemWidget.h"
#include <memory>

class SpecularDataItem;
class AbstractDataLoader;
class RealDataItem;

namespace Ui {
class SpecularDataImportWidget;
}

//! Widget to define and show 1D (specular) imports by data loaders, e.g. CSV file import
//! Contains space for the loader-defined import properties, a table for the raw and the imported
//! data and a graph to show the plot of the imported data.
//! The UI is defined via QtDesigner (.ui file)

class SpecularDataImportWidget : public SessionItemWidget {
    Q_OBJECT

public:
    SpecularDataImportWidget(QWidget* parent = nullptr);

    void setItem(SessionItem* realDataItem);

    QList<QAction*> actionList();

private slots:
    void onContextMenuRequest(const QPoint& point);

private:
    SpecularDataItem* specularDataItem();
    const RealDataItem* realDataItem() const;
    RealDataItem* realDataItem();

    void fillLoaderCombo();
    void updatePropertiesEdits();
    AbstractDataLoader* selectedLoader();
    void onFormatSelectionChanged();
    void updatePreview();
    void onCreateNewFormatButton();
    void onPropertiesChanged();
    QString currentFileName() const;
    void applyProperties();

    Ui::SpecularDataImportWidget* m_ui;
    AbstractDataLoader1D* m_loader; // only borrowed from realDataItem. Do not delete!
};

#endif // BORNAGAIN_GUI_COREGUI_VIEWS_SPECULARDATAWIDGETS_SPECULARDATAIMPORTWIDGET_H
