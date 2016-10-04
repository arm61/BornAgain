// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/MaskWidgets/MaskGraphicsScene.h
//! @brief     Defines class MaskGraphicsScene
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#ifndef MASKGRAPHICSSCENE_H
#define MASKGRAPHICSSCENE_H

#include "MaskDrawingContext.h"
#include "MaskEditorHelper.h"
#include <QGraphicsScene>
#include <QMap>
#include <QModelIndex>
#include <QSharedPointer>

class SessionModel;
class SessionItem;
class IMaskView;
class ISceneAdaptor;
class MaskGraphicsProxy;
class QItemSelectionModel;
class QItemSelection;
class PolygonView;
class MaskEditorAction;
class IntensityDataItem;
class QGraphicsSceneMouseEvent;
class QPainter;

//! Graphics scene for MaskEditorCanvas to draw masks on top of intensity data widgets.

class BA_CORE_API_ MaskGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    MaskGraphicsScene(QObject *parent = 0);

    void setMaskContext(SessionModel *model, const QModelIndex &maskContainerIndex,
                        IntensityDataItem *intensityItem);

    void setSelectionModel(QItemSelectionModel *model);

signals:
    void itemContextMenuRequest(const QPoint &point);

public slots:
    void onActivityModeChanged(MaskEditorFlags::Activity value);
    void onMaskValueChanged(MaskEditorFlags::MaskValue value);
    void onResetViewRequest();
    void onRowsInserted(const QModelIndex &, int, int);
    void onRowsAboutToBeRemoved(const QModelIndex &parent, int first, int last);
    void onRowsRemoved(const QModelIndex &, int, int);
    void cancelCurrentDrawing();
    void resetScene();
    void updateScene();
    void onPresentationTypeRequest(MaskEditorFlags::PresentationType presentationType);

private slots:
    void onSessionSelectionChanged(const QItemSelection & /* selected */,
                                   const QItemSelection & /* deselected */);
    void onSceneSelectionChanged();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void drawForeground(QPainter *painter, const QRectF &rect);
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);

private:
    void updateProxyWidget();
    void updateViews(const QModelIndex &parentIndex = QModelIndex(), IMaskView *parentView = 0);
    IMaskView* addViewForItem(SessionItem *item);
    void deleteViews(const QModelIndex & itemIndex);
    void removeItemViewFromScene(SessionItem *item);

    bool isValidMouseClick(QGraphicsSceneMouseEvent *event);    
    bool isValidForRectangleShapeDrawing(QGraphicsSceneMouseEvent *event);
    bool isValidForPolygonDrawing(QGraphicsSceneMouseEvent *event);
    bool isValidForLineDrawing(QGraphicsSceneMouseEvent *event);
    bool isValidForMaskAllDrawing(QGraphicsSceneMouseEvent *event);

    bool isAreaContains(QGraphicsSceneMouseEvent *event, MaskEditorHelper::EViewTypes viewType);
    bool isDrawingInProgress() const;
    void setDrawingInProgress(bool value);
    void setInPanAndZoomMode(bool value);

    void makeViewAtMousePosSelected(QGraphicsSceneMouseEvent *event);

    void processRectangleShapeItem(QGraphicsSceneMouseEvent *event);
    void processPolygonItem(QGraphicsSceneMouseEvent *event);
    void processLineItem(QGraphicsSceneMouseEvent *event);
    void processVerticalLineItem(const QPointF &pos);
    void processHorizontalLineItem(const QPointF &pos);
    void processMaskAllItem(QGraphicsSceneMouseEvent *event);

    void setZValues();
    PolygonView *currentPolygon() const;
    void setItemName(SessionItem *itemToChange);

    SessionModel *m_maskModel;
    QItemSelectionModel *m_selectionModel;
    QSharedPointer<ISceneAdaptor> m_adaptor;
    QMap<SessionItem *, IMaskView *> m_ItemToView;
    MaskGraphicsProxy *m_proxy;
    bool m_block_selection;
    QModelIndex m_maskContainerIndex;
    IntensityDataItem *m_intensityItem;
    SessionItem *m_currentItem;
    QPointF m_currentMousePosition;
    MaskDrawingContext m_context;
};

#endif // MASKGRAPHICSSCENE_H
