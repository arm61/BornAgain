// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Views/MaskWidgets/MaskEditorToolPanel.h
//! @brief     Defines class MaskEditor
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef MASKEDITORTOOLPANEL_H
#define MASKEDITORTOOLPANEL_H

#include <QWidget>

class QListView;
class SessionModel;
class QModelIndex;
class AwesomePropertyEditor;
class QItemSelection;
class QItemSelectionModel;
class QButtonGroup;

//! Tool widget for MaskEditor

class MaskEditorToolPanel : public QWidget
{
    Q_OBJECT
public:
    enum EActivityMode {SELECTION_MODE, PAN_ZOOM_MODE, RECTANGLE_MODE, POLYGON_MODE};

    MaskEditorToolPanel(QWidget *parent = 0);

    QSize sizeHint() const { return QSize(128, 128); }
    QSize minimumSizeHint() const { return QSize(128, 128); }

    void setModel(SessionModel *model, const QModelIndex &root_index);
    QItemSelectionModel* selectionModel();

signals:
    void activityModeChanged(int);

public slots:
    void onSelectionChanged(const QItemSelection &selected, const QItemSelection &);

private:
    QWidget *create_selection_group();
    QWidget *create_drawing_group();

    QListView *m_listView;
    AwesomePropertyEditor *m_propertyEditor;
    SessionModel *m_model;
    QButtonGroup *m_activityButtonGroup;
};


#endif
