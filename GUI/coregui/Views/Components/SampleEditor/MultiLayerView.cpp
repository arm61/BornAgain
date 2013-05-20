#include "MultiLayerView.h"

#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDrag>
#include <QCursor>
#include <QApplication>
#include <QMimeData>
#include <QBitmap>
#include <QWidget>
#include <QGradient>
#include <iostream>
#include <QDropEvent>
#include <QStyleOptionGraphicsItem>

#include "LayerView.h"
#include "DesignerHelper.h"
#include "DesignerMimeData.h"




MultiLayerView::MultiLayerView(QGraphicsItem *parent)
    : ISampleView(parent)
    , m_color(Qt::blue)
    , m_rect(0, 0, DesignerHelper::getMultiLayerWidth(), DesignerHelper::getMultiLayerHeight())
{
    setToolTip(QString("MultiLayer"));
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges);
    setAcceptDrops(true);
    //    setCursor(Qt::OpenHandCursor);
    //    setAcceptedMouseButtons(Qt::LeftButton);

    m_expected_types << QString("Layer") << QString("MultiLayer");
    allowDropType(QString("Layer"));

    connect(this, SIGNAL(childrenChanged()), this, SLOT(updateHeight()));
    updateHeight();
}


// allows droping of object of given type
void MultiLayerView::allowDropType(const QString &name) {
    if(m_current_types.contains(name)) {
        std::cout << "MultiLayerView::allowDropType -> Info. Name '" << name.toStdString() << "' is already in the list" << std::endl;
        return;
    }
    if(m_expected_types.contains(name)) {
        m_current_types.append(name);
    } else {
        std::cout << "MultiLayerView::allowDropType -> Warning. Can't handle the object with name' '" << name.toStdString() << "', expected names " << std::endl;
        foreach(QString s, m_expected_types) {
            std::cout << s.toStdString() << std::endl;
        }
    }
}



void MultiLayerView::addLayer(LayerView *layer, QPointF pos)
{
    // adjusting main rectangle othervise item->setPos will not work due to 'LayerView::itemChange'
    m_rect.setHeight(m_rect.height()+layer->boundingRect().height());

    int xpos = (DesignerHelper::getMultiLayerWidth() - DesignerHelper::getLayerWidth())/2.;
    layer->setPos(xpos, pos.y());
    layer->setFixedX();
    connect(layer, SIGNAL(LayerMoved()), this, SLOT(updateHeight()) );
    layer->setParentItem(this);
}


// adjusts positions of Layers inside MultiLayer, updates total MultiLayer height
// calculates drop areas for new layers
// called when one of Layer is changed
void MultiLayerView::updateHeight()
{
    std::cout << "MultiLayerView::updateHeight() " << std::endl;
    // drop areas are rectangles covering the area of layer interfaces
    m_drop_areas.clear();

    QList<QGraphicsItem *> list = childItems();
    qSort(list.begin(), list.end(), DesignerHelper::sort_layers);

    int total_height = 0;
    if( childItems().size() > 0) {
        foreach(QGraphicsItem *item, list) {
            item->setY(total_height);
            total_height += item->boundingRect().height();
            m_drop_areas.append(QRectF(0, item->y() - item->boundingRect().height()/4., boundingRect().width(), item->boundingRect().height()/2.));
        }
        m_drop_areas.append(QRectF(0, list.back()->y() +list.back()->boundingRect().height() - list.back()->boundingRect().height()/4., boundingRect().width(), list.back()->boundingRect().height()/2.));
    } else {
        total_height = DesignerHelper::getMultiLayerHeight();
        m_drop_areas.append(boundingRect());
    }

    m_rect.setHeight(total_height);
    update();
}


bool MultiLayerView::isInDropArea(QPointF pos)
{
    foreach(QRectF rect, m_drop_areas) {
        //std::cout << " drop areas " << rect.x() << " " << rect.y() << " " << rect.width() << " " << rect.height() << " point" << pos.x() << " " << pos.y() << std::endl;
        if (rect.contains(pos)) return true;
    }
    return false;
}

bool MultiLayerView::isExpectedObject(const QString &name)
{
    if(m_current_types.contains(name)) return true;
    return false;
}


QRectF MultiLayerView::boundingRect() const
{
    return rect();
}


void MultiLayerView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    painter->setPen(Qt::blue);
    if (option->state & (QStyle::State_Selected | QStyle::State_HasFocus)) {
        painter->setPen(Qt::DashLine);
    }
    painter->setBrush(DesignerHelper::getLayerGradient(m_color, rect() ) );
    painter->drawRect(rect());
}


void MultiLayerView::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    const DesignerMimeData *mimeData = checkDragEvent(event);
    if (mimeData) {
        std::cout << "MultiLayerView::dragEnterEvent() -> INSIDE " << std::endl;
    }
}


void MultiLayerView::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
    Q_UNUSED(event);
    std::cout << "MultiLayerView::dragLeaveEvent() -> " << std::endl;
}


void MultiLayerView::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    const DesignerMimeData *mimeData = checkDragEvent(event);
    if (mimeData) {
        addLayer(new LayerView(), event->pos());
        update();
    }
}


void MultiLayerView::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{
    const DesignerMimeData *mimeData = checkDragEvent(event);
    if (mimeData) {
        std::cout << "MultiLayerView::dragMoveEvent() -> pos:" << event->pos().x() << " " << event->pos().y() << std::endl;
        update();

    }
}


void MultiLayerView::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    std::cout << "MultiLayerView::mouseMoveEvent -> " << x() << " " << y() << std::endl;
    QGraphicsObject::mouseMoveEvent(event);
}


void MultiLayerView::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    std::cout << "MultiLayerView::mousePressEvent -> " << x() << " " << y() << std::endl;
    QGraphicsObject::mousePressEvent(event);
}

void MultiLayerView::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    std::cout << "MultiLayerView::mouseReleaseEvent -> " << x() << " " << y() << std::endl;
    QGraphicsObject::mouseReleaseEvent(event);
}


//const DesignerMimeData *MultiLayerView::checkDragEvent(QGraphicsSceneDragDropEvent * event)
//{
//    const DesignerMimeData *mimeData = qobject_cast<const DesignerMimeData *>(event->mimeData());
//    if (!mimeData) {
//        event->ignore();
//        return 0;
//    }

//    if(mimeData->hasFormat("widget/Layer")) {
//        event->setAccepted(true);
//    } else {
//        event->setAccepted(false);
//    }
//    return mimeData;
//}


const DesignerMimeData *MultiLayerView::checkDragEvent(QGraphicsSceneDragDropEvent * event)
{
    std::cout << "MultiLayerView::checkDragEvent -> "  << std::endl;
    const DesignerMimeData *mimeData = qobject_cast<const DesignerMimeData *>(event->mimeData());
    if (!mimeData) {
        event->ignore();
        return 0;
    }

    if(mimeData->hasFormat("bornagain/widget")
            && isExpectedObject(mimeData->getClassName())
            && isInDropArea(event->pos()) ) {
        std::cout << "LayerDockView::checkDragEvent -> yes"  << std::endl;
        event->setAccepted(true);
    } else {
        event->setAccepted(false);
    }
    return mimeData;
}

