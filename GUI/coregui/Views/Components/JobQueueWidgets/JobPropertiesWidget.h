// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Views/Components/JobQueueWidgets/JobPropertiesWidget.h
//! @brief     Defines class JobPropertiesWidget
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef JOBPROPERTIESWIDGET_H
#define JOBPROPERTIESWIDGET_H

#include "WinDllMacros.h"
#include <QWidget>
#include <QMap>

class NJobModel;
class NJobItem;
class QtProperty;
class QtVariantProperty;
class QTextEdit;
class QTabWidget;
class ParameterizedItem;
class UniversalPropertyEditor;
class QItemSelectionModel;

//! Widget to show and change properties of currently selected JobItem
//! Left buttom corner of JobQueueView
class BA_CORE_API_ JobPropertiesWidget : public QWidget
{
    Q_OBJECT
public:
    enum ETabId { JOB_PROPERTIES, JOB_COMMENTS };
    explicit JobPropertiesWidget(QWidget *parent = 0);

    void setModel(NJobModel *model);

    QSize sizeHint() const { return QSize(64, 256); }
    QSize minimumSizeHint() const { return QSize(64, 64); }

//    void setSelectionModel(QItemSelectionModel *selectionModel);

public slots:    
    void setItem(NJobItem *item);

private:
    NJobModel *m_jobModel;
//    QItemSelectionModel *m_selectionModel;
    NJobItem *m_currentItem;
    QTabWidget *m_tabWidget;
    UniversalPropertyEditor *m_propertyEditor;
    QTextEdit *m_commentsEditor;
};

#endif
