//  ************************************************************************************************
//
//  BornAgain: simulate and fit reflection and scattering
//
//! @file      GUI/coregui/Models/JobModel.h
//! @brief     Defines class JobModel
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************
#ifndef BORNAGAIN_GUI_COREGUI_MODELS_JOBMODEL_H
#define BORNAGAIN_GUI_COREGUI_MODELS_JOBMODEL_H

#include "GUI/coregui/Models/SessionModel.h"
class JobQueueData;
class JobItem;
class MultiLayerItem;
class InstrumentItem;
class RealDataItem;
class SimulationOptionsItem;

class JobModel : public SessionModel {
    Q_OBJECT

public:
    explicit JobModel(QObject* parent = 0);
    virtual ~JobModel();

    const JobItem* getJobItemForIndex(const QModelIndex& index) const;
    JobItem* getJobItemForIndex(const QModelIndex& index);

    JobItem* getJobItemForIdentifier(const QString& identifier);

    JobItem* addJob(const MultiLayerItem* multiLayerItem, const InstrumentItem* instrumentItem,
                    const RealDataItem* realDataItem, const SimulationOptionsItem* optionItem);

    QVector<JobItem*> jobItems() const;

    void restore(JobItem* jobItem);

    bool hasUnfinishedJobs();

    void clear() override;
    QVector<SessionItem*> nonXMLItems() const override;
    virtual void readFrom(QXmlStreamReader* reader, MessageService* messageService = 0) override;

signals:
    void aboutToDeleteJobItem(JobItem* item);
    void focusRequest(JobItem* item);
    void globalProgress(int);

public slots:
    void onCancelAllJobs();
    void runJob(const QModelIndex& index);
    void cancelJob(const QModelIndex& index);
    void removeJob(const QModelIndex& index);

private:
    QString generateJobName();
    void restoreItem(SessionItem* item);
    JobQueueData* m_queue_data;
};

#endif // BORNAGAIN_GUI_COREGUI_MODELS_JOBMODEL_H
