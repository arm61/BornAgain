#ifndef MULTILAYERVIEW_H
#define MULTILAYERVIEW_H

#include <QGraphicsItem>
#include <QGraphicsObject>
#include <QColor>
#include <QRectF>
#include <QRect>
#include <QGradient>
#include "ISampleView.h"
#include <QStringList>

class LayerView;
class DesignerMimeData;

class MultiLayerView : public ISampleView
{
    Q_OBJECT
public:

    MultiLayerView(QGraphicsItem *parent = 0);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QRect rect() const { return m_rect; }

    void addLayer(LayerView *layer, QPointF pos=QPointF());

    void setColor(const QColor &color) { m_color = color; }
    void setRectangle(const QRect &rect) { m_rect = rect; }

    //! allows droping of object of given type
    void allowDropType(const QString &name);

public slots:
    void updateHeight();

protected:
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *event);
    void dropEvent(QGraphicsSceneDragDropEvent *event);
    void dragMoveEvent(QGraphicsSceneDragDropEvent *event);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    const DesignerMimeData *checkDragEvent(QGraphicsSceneDragDropEvent * event);

    //! returns true if given point is in alowed areas of multilayer
    bool isInDropArea(QPointF pos);

    //! returns true if name of the object match whose the multi layer can handle
    bool isExpectedObject(const QString &name);

private:

    QColor m_color;
    QRect m_rect;
    QList<QRectF> m_drop_areas;
    QStringList m_expected_types;
    QStringList m_current_types;
};




#endif // MULTILAYERVIEW_H
