#ifndef ISAMPLEVIEW_H
#define ISAMPLEVIEW_H

#include <QGraphicsObject>

class QPainter;
class QStyleOptionGraphicsItem;
class QWidget;
class ISampleViewVisitor;


#include "ISampleViewVisitor.h"
#include "NodeEditorPort.h"

//! parent class for graphic representation of all ISample's
class ISampleView : public QGraphicsObject
{
public:
    enum { Type = DesignerHelper::ISampleType };
    ISampleView(QGraphicsItem *parent = 0) : QGraphicsObject(parent) {}
    virtual ~ISampleView(){}

    //! сalls the ISampleViewVisitor's visit method
    virtual void accept(ISampleViewVisitor *visitor) const = 0;

    int type() const { return Type; }
};



//! view of ISample's with rectangular shape and node functionality
class ISampleRectView : public ISampleView
{
public:
    enum { Type = DesignerHelper::ISampleRectType };
    ISampleRectView(QGraphicsItem *parent = 0, QRect rect = QRect(0,0,50,50) );
    virtual ~ISampleRectView(){}

    //! сalls the ISampleViewVisitor's visit method
    virtual void accept(ISampleViewVisitor *visitor) const { visitor->visit(this); }

    int type() const { return Type; }

    virtual QRectF boundingRect() const { return getRectangle(); }
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    virtual NodeEditorPort* addPort(const QString &name, NodeEditorPort::PortDirection direction, NodeEditorPort::PortType port_type);

    //! connect input port of given view with appropriate output port(s) of other item
    virtual void connectInputPort(ISampleRectView *other);

    virtual QString getName() const { return m_name; }
    virtual QColor getColor() const { return m_color; }
    virtual QRect getRectangle() const { return m_rect;}
    virtual void setRectangle(QRect rect) { m_rect = rect; }
    virtual QString getLabel() const { return m_label; }
    virtual void setLabel(const QString &name);

public slots:
    virtual void setName(const QString &name) { m_name = name; }
    virtual void setColor(const QColor &color) { m_color = color; }

protected:
    virtual void setPortCoordinates();
    virtual int getNumberOfPorts();
    virtual int getNumberOfOutputPorts();
    virtual int getNumberOfInputPorts();

    QString m_name;
    QColor m_color;
    QRect m_rect;
    int m_roundpar;
    double m_label_vspace; // vertical space occupied by the label
    QString m_label;
};


//! default view of unimplemented ISample's
class ISampleDefaultView : public ISampleRectView
{
public:
    ISampleDefaultView(QGraphicsItem *parent = 0) : ISampleRectView(parent){}
    //! сalls the ISampleViewVisitor's visit method
    virtual void accept(ISampleViewVisitor *visitor) const { visitor->visit(this); }
};



#endif //  ISAMPLEVIEW_H