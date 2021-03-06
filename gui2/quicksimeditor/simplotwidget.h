//  ************************************************************************************************
//
//  BornAgain: simulate and fit reflection and scattering
//
//! @file      gui2/quicksimeditor/simplotwidget.h
//! @brief     Defines class CLASS?
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2020
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#ifndef BORNAGAIN_GUI2_QUICKSIMEDITOR_SIMPLOTWIDGET_H
#define BORNAGAIN_GUI2_QUICKSIMEDITOR_SIMPLOTWIDGET_H

#include "darefl_export.h"
#include <QWidget>

namespace ModelView {
class GraphCanvas;
} // namespace ModelView

namespace gui2 {

class ApplicationModels;

//! Presents simulation results together with reference experimental data on two canvas.
//! The top canvas contains graphs itself, bottom canvas their relative difference.

class DAREFLCORE_EXPORT SimPlotWidget : public QWidget {
    Q_OBJECT

public:
    SimPlotWidget(QWidget* parent = nullptr);
    ~SimPlotWidget();

    void setModels(ApplicationModels* models);

    void updateViewport();

    void updateDiffPlot();

private:
    ApplicationModels* m_models{nullptr};
    ModelView::GraphCanvas* m_specularCanvas{nullptr};
    ModelView::GraphCanvas* m_diffCanvas{nullptr};
};

} // namespace gui2

#endif // BORNAGAIN_GUI2_QUICKSIMEDITOR_SIMPLOTWIDGET_H
