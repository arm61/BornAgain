//  ************************************************************************************************
//
//  BornAgain: simulate and fit reflection and scattering
//
//! @file      GUI/coregui/Views/JobWidgets/JobProgressAssistant.cpp
//! @brief     Implements class JobProgressAssistant
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#include "GUI/coregui/Views/JobWidgets/JobProgressAssistant.h"
#include "GUI/coregui/Models/JobModel.h"
#include "GUI/coregui/Models/JobQueueData.h"
#include "GUI/coregui/mainwindow/mainwindow.h"
#include <QProgressBar>

JobProgressAssistant::JobProgressAssistant(MainWindow* mainWindow)
    : QObject(mainWindow), m_mainWindow(mainWindow)
{
    connect(m_mainWindow->jobModel(), &JobModel::globalProgress, this,
            &JobProgressAssistant::onGlobalProgress);
}

void JobProgressAssistant::onGlobalProgress(int progress)
{
    ASSERT(m_mainWindow->progressBar());
    if (progress < 0 || progress >= 100)
        m_mainWindow->progressBar()->hide();
    else {
        m_mainWindow->progressBar()->show();
        m_mainWindow->progressBar()->setValue(progress);
    }
}
