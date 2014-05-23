#include "InstrumentEditorWidget.h"
#include "ParameterizedItem.h"
#include "BeamItem.h"
#include "DetectorItems.h"
#include "DetectorEditorWidget.h"
#include "PropertyVariantManager.h"
#include "PropertyVariantFactory.h"
#include <QBoxLayout>
#include <QGroupBox>
#include "qtvariantproperty.h"
#include "qttreepropertybrowser.h"
#include "qtbuttonpropertybrowser.h"
#include "qtgroupboxpropertybrowser.h"
#include <QDebug>


InstrumentEditorWidget::InstrumentEditorWidget(QWidget *parent)
    : QWidget(parent)
    , m_label(new QLabel)
    , m_variantManager(new QtVariantPropertyManager(this))
    , m_propertyBrowser(0)
    , m_detectorWidget(0)

{

    setMinimumSize(400, 400);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    //m_propertyBrowser = new QtTreePropertyBrowser(this);
    //m_propertyBrowser = new QtButtonPropertyBrowser(this);
    m_propertyBrowser = new QtGroupBoxPropertyBrowser();


    //m_variantManager = new QtVariantPropertyManager(this);
    m_variantManager = new PropertyVariantManager(this);

//    connect(m_variantManager, SIGNAL(valueChanged(QtProperty *, const QVariant &)),
//                this, SLOT(valueChanged(QtProperty *, const QVariant &)));

    //QtVariantEditorFactory *variantFactory = new QtVariantEditorFactory(this);
    QtVariantEditorFactory *variantFactory = new PropertyVariantFactory();

    m_propertyBrowser->setFactoryForManager(m_variantManager, variantFactory);


    QGroupBox *beamParamsGroup = new QGroupBox(tr("Instrument Parameters"));
    //beamParamsGroup->setCheckable(true);

    QVBoxLayout *beamParamsLayout = new QVBoxLayout;
    beamParamsLayout->addWidget(m_propertyBrowser);

    beamParamsGroup->setLayout(beamParamsLayout);

    m_detectorWidget = new DetectorEditorWidget(this);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(beamParamsGroup);
    mainLayout->addWidget(m_detectorWidget);
    mainLayout->addStretch();


    setLayout(mainLayout);


}


void InstrumentEditorWidget::updateExpandState()
{
//    QList<QtBrowserItem *> list = m_propertyBrowser->topLevelItems();
//    QListIterator<QtBrowserItem *> it(list);
//    while (it.hasNext()) {
//        QtBrowserItem *item = it.next();
//        QtProperty *prop = item->property();
//        idToExpanded[propertyToId[prop]] = m_propertyBrowser->isExpanded(item);
//    }
}



void InstrumentEditorWidget::setInstrumentItem(ParameterizedItem *instrument)
{
//    m_label->setText(instrument->itemName());

    updateExpandState();


//    QMap<QtProperty *, QString>::ConstIterator itProp = propertyToId.constBegin();
//    while (itProp != propertyToId.constEnd()) {
//        delete itProp.key();
//        itProp++;
//    }
//    propertyToId.clear();
//    idToProperty.clear();


//    QtVariantProperty *property;


//    property = m_variantManager->addProperty(QVariant::String, tr("Name"));
//    property->setValue(instrument->itemName());
//    addProperty(property, ParameterizedItem::P_NAME);

//    BeamItem *beamItem = instrument->getS

    BeamItem *beamItem(0);
    DetectorItem *detectorItem(0);
    foreach(ParameterizedItem *item, instrument->childItems()) {
        if(item->modelType() == QStringLiteral("Beam")) {
            beamItem = dynamic_cast<BeamItem *>(item);
        }
        else if(item->modelType() == QStringLiteral("Detector")) {
            detectorItem = dynamic_cast<DetectorItem *>(item);
        }
    }
    Q_ASSERT(beamItem);
    Q_ASSERT(detectorItem);

    m_detectorWidget->initFromItem(detectorItem);


    QtProperty *beamProperty = m_variantManager->addProperty(
                QtVariantPropertyManager::groupTypeId(), "Beam Parameters");
    addSubProperties(beamProperty, beamItem);
    m_propertyBrowser->addProperty(beamProperty);


    QtProperty *detectorProperty = m_variantManager->addProperty(
                QtVariantPropertyManager::groupTypeId(), "Detector Parameters");
    addSubProperties(detectorProperty, detectorItem);
    m_propertyBrowser->addProperty(detectorProperty);


}

void InstrumentEditorWidget::addProperty(QtVariantProperty *property, const QString &id)
{
//    propertyToId[property] = id;
//    idToProperty[id] = property;
//    QtBrowserItem *item = m_propertyBrowser->addProperty(property);
////    if (idToExpanded.contains(id))
////        m_propertyBrowser->setExpanded(item, idToExpanded[id]);
}



void InstrumentEditorWidget::addSubProperties(QtProperty *item_property, ParameterizedItem *item)
{
    qDebug() << " ";
    qDebug() << "   XXX InstrumentEditorWidget::addSubProperties()";
    Q_ASSERT(item_property);
    Q_ASSERT(item);

    QList<QByteArray> property_names = item->dynamicPropertyNames();
    for (int i = 0; i < property_names.length(); ++i) {
        QString prop_name = QString(property_names[i]);
        QVariant prop_value = item->property(prop_name.toUtf8().data());
        int type = prop_value.type();
        if (type == QVariant::UserType) {
            type = prop_value.userType();
        }
        QtVariantProperty *subProperty = 0;
        if (m_variantManager->isPropertyTypeSupported(type)) {
            subProperty = m_variantManager->addProperty(type, prop_name);
            subProperty->setValue(prop_value);
            if(type == QVariant::Double) {
                subProperty->setAttribute(QLatin1String("singleStep"), 0.1);
                subProperty->setAttribute(QLatin1String("decimals"), 5);
            }

            if (item->getSubItems().contains(prop_name)) {
                subProperty->setAttribute(QLatin1String("readOnly"), true);
                ParameterizedItem *subitem = item->getSubItems()[prop_name];
                if (subitem) {
                    addSubProperties(subProperty, subitem);
                }
            }
        }
//        else {
//            subProperty = m_readOnlyManager->addProperty(QVariant::String,
//                                                         prop_name);
//            subProperty->setValue(QLatin1String("< Unknown Type >"));
//            subProperty->setEnabled(false);
//        }
        item_property->addSubProperty(subProperty);
        SubItem subitem(item,prop_name);
        m_property_to_subitem[subProperty] = subitem;
        m_material_to_property[item][prop_name] = subProperty;
    }
}

