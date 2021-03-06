//  ************************************************************************************************
//
//  BornAgain: simulate and fit reflection and scattering
//
//! @file      GUI/coregui/Views/SpecularDataWidgets/SpecularDataImportWidget.cpp
//! @brief     Implements class SpecularDataImportWidget
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2021
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#include "GUI/coregui/Views/SpecularDataWidgets/SpecularDataImportWidget.h"
#include "GUI/coregui/DataLoaders/AbstractDataLoader.h"
#include "GUI/coregui/DataLoaders/AbstractDataLoader1D.h"
#include "GUI/coregui/DataLoaders/DataLoaders1D.h"
#include "GUI/coregui/DataLoaders/QREDataLoader.h"
#include "GUI/coregui/Models/DataItemUtils.h"
#include "GUI/coregui/Models/InstrumentItems.h"
#include "GUI/coregui/Models/RealDataItem.h"
#include "GUI/coregui/Models/SpecularDataItem.h"
#include "GUI/coregui/mainwindow/AppSvc.h"
#include "GUI/coregui/mainwindow/projectmanager.h"
#include "ui_SpecularDataImportWidget.h"
#include <QAction>
#include <QBoxLayout>
#include <QFileDialog>
#include <QMenu>
#include <QStringListModel>
#include <QTextStream>
#include <QTimer>

SpecularDataImportWidget::SpecularDataImportWidget(QWidget* parent)
    : SessionItemWidget(parent), m_ui(new Ui::SpecularDataImportWidget), m_loader(nullptr)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    m_ui->setupUi(this);
    m_ui->linkedInstrumentGroup->hide(); // #baimport - remove from UI if not used in the future

    m_ui->createNewFormatButton->hide(); // #baimport - show again when implementation is complete

    fillLoaderCombo();
    updatePropertiesEdits();

    connect(m_ui->formatSelectionComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &SpecularDataImportWidget::onFormatSelectionChanged);
    connect(m_ui->createNewFormatButton, &QPushButton::clicked, this,
            &SpecularDataImportWidget::onCreateNewFormatButton);

    connect(m_ui->originalRowCheckBox, &QCheckBox::stateChanged, this,
            &SpecularDataImportWidget::updatePreview);

    connect(m_ui->rawDataCheckBox, &QCheckBox::stateChanged, this,
            &SpecularDataImportWidget::updatePreview);

    connect(m_ui->calculatedDataCheckBox, &QCheckBox::stateChanged, this,
            &SpecularDataImportWidget::updatePreview);
}

void SpecularDataImportWidget::setItem(SessionItem* _realDataItem)
{
    SessionItemWidget::setItem(_realDataItem);

    m_loader = dynamic_cast<AbstractDataLoader1D*>(realDataItem()->dataLoader());

    // #baimport check whether file exists. If not, add hint of this
    m_ui->fileNameEdit->setText(QDir::toNativeSeparators(realDataItem()->nativeFileName()));

    QSignalBlocker b(m_ui->formatSelectionComboBox);
    m_ui->formatSelectionComboBox->setCurrentText(m_loader->name());

    updatePropertiesEdits();

    QStringList errors, warnings;
    m_loader->importFile(realDataItem()->nativeFileName(), realDataItem(), &errors, &warnings);

    updatePreview();
    connect(m_loader, &AbstractDataLoader::propertiesChanged, this,
            &SpecularDataImportWidget::onPropertiesChanged);
}

QList<QAction*> SpecularDataImportWidget::actionList()
{
    return {};
}

void SpecularDataImportWidget::onContextMenuRequest(const QPoint& point)
{
    QMenu menu;
    for (auto action : actionList())
        menu.addAction(action);
    menu.exec(point);
}

SpecularDataItem* SpecularDataImportWidget::specularDataItem()
{
    return DataItemUtils::specularDataItem(currentItem());
}

const RealDataItem* SpecularDataImportWidget::realDataItem() const
{
    return dynamic_cast<const RealDataItem*>(currentItem());
}

RealDataItem* SpecularDataImportWidget::realDataItem()
{
    return dynamic_cast<RealDataItem*>(currentItem());
}

void SpecularDataImportWidget::fillLoaderCombo()
{
    QSignalBlocker b(m_ui->formatSelectionComboBox);
    m_ui->formatSelectionComboBox->clear();
    for (auto loader : DataLoaders1D::instance().recentlyUsedLoaders()) {
        m_ui->formatSelectionComboBox->addItem(loader->name());
    }
    for (auto loader : DataLoaders1D::instance().loaders()) {
        m_ui->formatSelectionComboBox->addItem(loader->name());
    }
}

void SpecularDataImportWidget::updatePropertiesEdits()
{
    for (auto child : m_ui->propertiesWidget->children()) {
        delete child;
    }

    if (m_ui->propertiesWidget->layout())
        delete m_ui->propertiesWidget->layout();

    if (m_loader) {
        m_loader->populatePropertiesWidget(m_ui->propertiesWidget);
    }

    const bool hasChildren = !m_ui->propertiesWidget->children().empty();

    m_ui->propertiesWidget->setVisible(hasChildren);
}

AbstractDataLoader* SpecularDataImportWidget::selectedLoader()
{
    const QString name = m_ui->formatSelectionComboBox->currentText();

    for (auto loader : DataLoaders1D::instance().loaders())
        if (name == loader->name())
            return loader;

    return nullptr;
}

void SpecularDataImportWidget::onFormatSelectionChanged()
{
    if (m_loader)
        m_loader->disconnect(this);

    m_loader = dynamic_cast<AbstractDataLoader1D*>(selectedLoader()->clone());
    m_loader->initWithDefaultProperties();
    realDataItem()->setDataLoader(m_loader);
    updatePropertiesEdits();
    updatePreview();
    applyProperties();
    connect(m_loader, &AbstractDataLoader::propertiesChanged, this,
            &SpecularDataImportWidget::updatePreview);
}

void SpecularDataImportWidget::updatePreview()
{
    m_ui->plotWidget->clearGraphs();

    if (m_loader) {
        m_loader->previewOfGraph(m_ui->plotWidget);

        m_loader->fillImportDetailsTable(m_ui->dataTable, m_ui->originalRowCheckBox->isChecked(),
                                         m_ui->rawDataCheckBox->isChecked(),
                                         m_ui->calculatedDataCheckBox->isChecked());
    }

    m_ui->plotWidget->replot();
}

void SpecularDataImportWidget::onCreateNewFormatButton()
{
    bool ok;
    QString name = QInputDialog::getText(
        this, "New format", "Please enter a name for the new format", QLineEdit::Normal, "", &ok);
    if (!ok || name.isEmpty())
        return;

    DataLoaders1D::instance().cloneAsUserDefinedLoader(m_loader, name);

    fillLoaderCombo();
    m_ui->formatSelectionComboBox->setCurrentText(name);
    onFormatSelectionChanged();
}

void SpecularDataImportWidget::onPropertiesChanged()
{
    m_loader->applyProperties(); // #baTODO: may be duplicate
    applyProperties();
    QStringList errors, warnings;
    m_loader->importFile(realDataItem()->nativeFileName(), realDataItem(), &errors, &warnings);

    // If there is a linked instrument, any change in import settings can break the compatibility.
    // Therefore check the compatibility and break the link if necessary
    if (realDataItem()->linkedInstrument() != nullptr) {
        if (!realDataItem()->linkedInstrument()->alignedWith(realDataItem()))
            realDataItem()->clearInstrumentId();
    }

    updatePreview();
}

QString SpecularDataImportWidget::currentFileName() const
{
    return realDataItem()->nativeFileName();
}

void SpecularDataImportWidget::applyProperties()
{
    // #baimport seems obsolete
}
