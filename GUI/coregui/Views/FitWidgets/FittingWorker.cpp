// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Views/FitWidgets/FittingWorker.cpp
//! @brief     Implements class FittingWorker
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "FittingWorker.h"
#include "FitSuite.h"

void FittingWorker::startFit()
{
    m_fitsuite->resetInterrupt();
    emit started();
    try {
        m_fitsuite->runFit();
    } catch(const std::exception& ex) {
        emit error(QString::fromLatin1(ex.what()));
    }
    emit finished();
}

void FittingWorker::interruptFitting()
{
    if (m_fitsuite) {
        m_fitsuite->interruptFitting();
    }
}

