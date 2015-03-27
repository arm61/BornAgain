// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Views/Components/JobQueueWidgets/JobRealTimeWidget.h
//! @brief     Defines class JobRealTimeWidget
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef JOBREALTIMEWIDGET_H
#define JOBREALTIMEWIDGET_H

#include "WinDllMacros.h"
#include <QWidget>
#include <QMap>

class JobQueueModel;
class QStackedWidget;
class QModelIndex;
class JobItem;
class ModelTuningWidget;
class JobRealTimeToolBar;

//! The JobRealTimeWidget provides tuning of sample parameters and run of the simulation in real time.
//! Located on the right side of JobView and is visible when realtime activity is selected.
class BA_CORE_API_ JobRealTimeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit JobRealTimeWidget(JobQueueModel *jobQueueModel, QWidget *parent = 0);

    void setJobQueueModel(JobQueueModel *jobQueueModel);

public slots:
    void itemClicked(JobItem *item);
    void onJobItemDelete(JobItem *item);
    void onJobItemFinished(const QString &identifier);
    void onResetParameters();
    void updateCurrentItem();

private:
    ModelTuningWidget *getCurrentModelTuningWidget();
    bool isValidJobItem(JobItem *item);

    JobQueueModel *m_jobQueueModel;
    JobItem *m_currentJobItem;
    QStackedWidget *m_stack;
    QMap<JobItem *, ModelTuningWidget *> m_jobItemToTuningWidget;
    JobRealTimeToolBar *m_toolBar;
};


#endif