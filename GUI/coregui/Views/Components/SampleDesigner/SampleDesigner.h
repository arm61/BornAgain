#ifndef SAMPLEEDITOR_H
#define SAMPLEEDITOR_H

#include <QObject>
#include <QStackedWidget>

class DesignerScene;
class DesignerView;
class SamplePropertyEditor;
class DesignerWidgetFactory;


//! sample designer interface
class SampleDesignerInterface : public QObject
{
    Q_OBJECT

public:
    SampleDesignerInterface(QObject *parent = 0) : QObject(parent){}
    virtual ~SampleDesignerInterface() { }

    virtual DesignerScene *getScene() const = 0;
    virtual DesignerView *getView() const = 0;

};


//! sample designer provide central window with graphic scene to drag and drop
class SampleDesigner: public SampleDesignerInterface
{
    Q_OBJECT

public:
    SampleDesigner(QWidget *parent = 0);
    virtual ~SampleDesigner();

    DesignerScene *getScene() const { return m_designerScene; }
    DesignerView *getView() const { return m_designerView; }

    QWidget *getCentralWidget() { return m_editorStack; }

private:
    DesignerWidgetFactory *m_widgetFactory; //! factory to make views of ISample objects
    DesignerScene *m_designerScene; //! scene which holds all objects
    DesignerView *m_designerView;   //! graphical representation of scene with object
    QStackedWidget *m_editorStack;    //! stack for varaiety of DesignerView's
};



#endif // SAMPLEEDITOR_H
