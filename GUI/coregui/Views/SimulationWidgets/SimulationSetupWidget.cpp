// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Views/SimulationWidgets/SimulationSetupWidget.cpp
//! @brief     Implements class SimulationSetupWidget
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#include "SimulationSetupWidget.h"
#include "JobModel.h"
#include "JobItem.h"
#include "SampleValidator.h"
#include "PythonScriptWidget.h"
#include "projectmanager.h"
#include "SimulationOptionsWidget.h"
#include "ApplicationModels.h"
#include "DocumentModel.h"
#include "SimulationDataSelectorWidget.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>

SimulationSetupWidget::SimulationSetupWidget(QWidget *parent)
    : QWidget(parent)
    , m_applicationModels(0)
    , m_projectManager(0)
    , runSimulationButton(0)
    , exportToPyScriptButton(0)
    , m_simDataSelectorWidget(new SimulationDataSelectorWidget(this))
    , m_simOptionsWidget(new SimulationOptionsWidget(this))
{
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(m_simDataSelectorWidget);
    mainLayout->addWidget(m_simOptionsWidget);
    mainLayout->addWidget(createButtonWidget());
    mainLayout->addStretch(10);
    setLayout(mainLayout);

    // signal and slots
    connect(runSimulationButton, SIGNAL(clicked()), this, SLOT(onRunSimulation()));
    connect(exportToPyScriptButton, SIGNAL(clicked()), this, SLOT(onExportToPythonScript()));
}

void SimulationSetupWidget::setApplicationModels(ApplicationModels *model)
{
    Q_ASSERT(model);
    if(model != m_applicationModels) {
        m_applicationModels = model;
        m_simDataSelectorWidget->setApplicationModels(model);
        updateViewElements();
    }
}

void SimulationSetupWidget::setProjectManager(ProjectManager *projectManager)
{
    m_projectManager = projectManager;
}

void SimulationSetupWidget::updateViewElements()
{
    m_simDataSelectorWidget->updateViewElements();
    m_simOptionsWidget->setItem(m_applicationModels->documentModel()->getSimulationOptionsItem());
}

void SimulationSetupWidget::onRunSimulation()
{
    const MultiLayerItem *jobMultiLayerItem = m_simDataSelectorWidget->getSelectedMultiLayerItem();
    const InstrumentItem *jobInstrumentItem = m_simDataSelectorWidget->getSelectedInstrumentItem();

    if(!isValidSetup(jobMultiLayerItem, jobInstrumentItem))
        return;

    JobItem *jobItem = m_applicationModels->jobModel()->addJob(
                jobMultiLayerItem,
                jobInstrumentItem,
                m_applicationModels->documentModel()->getSimulationOptionsItem());

    // load real data
//    if (!pathLabel->text().isEmpty()) {
//        try {
//            IHistogram *data = IntensityDataIOFactory::readIntensityData(pathLabel->text().toStdString());
//            dynamic_cast<IntensityDataItem*>(jobItem->getItem(JobItem::T_REALDATA))
//                    ->setOutputData(data->createOutputData());
//            jobItem->setItemValue(JobItem::P_WITH_FITTING, true);
//        } catch (...) {
//            QMessageBox::warning(this, "IO Problem", "Real data can not be loaded.");
//        }
//    }

    if (jobItem->runImmediately() || jobItem->runInBackground())
        m_applicationModels->jobModel()->runJob(jobItem->index());
}

void SimulationSetupWidget::onExportToPythonScript()
{
    const MultiLayerItem *jobMultiLayerItem = m_simDataSelectorWidget->getSelectedMultiLayerItem();
    const InstrumentItem *jobInstrumentItem = m_simDataSelectorWidget->getSelectedInstrumentItem();

    if(!isValidSetup(jobMultiLayerItem, jobInstrumentItem))
        return;

    PythonScriptWidget *pythonWidget = new PythonScriptWidget(this);
    pythonWidget->show();
    pythonWidget->raise();
    pythonWidget->generatePythonScript(jobMultiLayerItem, jobInstrumentItem,
            m_applicationModels->documentModel()->getSimulationOptionsItem(),
                                       m_projectManager->getProjectDir());
}

//! Returns true, if sample and instrument are suitable for the simulation.

bool SimulationSetupWidget::isValidSetup(const MultiLayerItem *multiLayerItem,
                                         const InstrumentItem *instrumentItem)
{
    if (!multiLayerItem) {
        QMessageBox::warning(this, tr("No Sample Selected"), tr("You must select a sample first."));
        return false;
    }

    SampleValidator sampleValidator;
    if (!sampleValidator.isValidMultiLayer(multiLayerItem)) {
        QMessageBox::warning(this, tr("Not suitable MultiLayer"),
                             sampleValidator.getValidationMessage());
        return false;
    }

    if (!instrumentItem) {
        QMessageBox::warning(this, tr("No Instrument Selected"),
                             tr("You must select an instrument first."));
        return false;
    }

    return true;
}

QWidget *SimulationSetupWidget::createButtonWidget()
{
    QWidget *result = new QWidget;

    QHBoxLayout *simButtonLayout = new QHBoxLayout;
    // run simulation button
    runSimulationButton = new QPushButton(tr("Run Simulation"));
    runSimulationButton->setIcon(QIcon(":/images/main_simulation.png"));
    runSimulationButton->setMinimumWidth(100);
    runSimulationButton->setMinimumHeight(50);
    runSimulationButton->setToolTip("Run the simulation using settings above.\n"
                                    " Global shortcut ctrl-r can be used to run from sample view.");
//    QPalette palette = runSimulationButton->palette();
//    palette.setColor(QPalette::Button, QColor(Constants::BUTTON_COLOR));
//    palette.setColor(QPalette::ButtonText, QColor(Constants::BUTTON_TEXT_COLOR));
//    runSimulationButton->setPalette(palette);

    // export simulation to a python script
    exportToPyScriptButton = new QPushButton(tr("Export to Python Script"));
    exportToPyScriptButton->setIcon(QIcon(":/images/mode_script.png"));
    exportToPyScriptButton->setMinimumWidth(100);
    exportToPyScriptButton->setMinimumHeight(50);
    exportToPyScriptButton->setToolTip("Export the simulation using settings above to "
                                       "a python script.\n");
//    exportToPyScriptButton->setPalette(palette);

    simButtonLayout->addStretch();
    simButtonLayout->addWidget(runSimulationButton);
    simButtonLayout->addWidget(exportToPyScriptButton);
    simButtonLayout->addStretch();

    result->setLayout(simButtonLayout);

    return result;
}
