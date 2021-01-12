//  ************************************************************************************************
//
//  BornAgain: simulate and fit reflection and scattering
//
//! @file      GUI/coregui/mainwindow/newprojectdialog.cpp
//! @brief     Implements class NewProjectDialog
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#include "GUI/coregui/mainwindow/newprojectdialog.h"
#include "GUI/coregui/mainwindow/projectdocument.h"
#include <QFileDialog>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

NewProjectDialog::NewProjectDialog(QWidget* parent, Mode mode, const QString& workingDirectory,
                                   const QString& projectName)
    : QDialog(parent)
    , m_projectNameEdit(0)
    , m_workDirEdit(0)
    , m_browseButton(0)
    , m_warningLabel(0)
    , m_cancelButton(0)
    , m_createButton(0)
    , m_valid_projectName(true)
    , m_valid_projectPath(true)

{
    setMinimumSize(480, 280);
    setWindowTitle(mode == CREATE ? "New project" : "Save project");

    QLabel* nameLabel = new QLabel("Project name:");
    m_projectNameEdit = new QLineEdit;
    m_projectNameEdit->setText("Untitled");
    connect(m_projectNameEdit, &QLineEdit::textEdited, this,
            &NewProjectDialog::checkIfProjectNameIsValid);
    nameLabel->setBuddy(m_projectNameEdit);

    QLabel* parentDirLabel = new QLabel(mode == CREATE ? "Create in:" : "Save in:");
    m_workDirEdit = new QLineEdit;
    m_workDirEdit->setText(QDir::toNativeSeparators(QDir::homePath()));
    connect(m_workDirEdit, &QLineEdit::textEdited, this,
            &NewProjectDialog::checkIfProjectPathIsValid);
    parentDirLabel->setBuddy(m_workDirEdit);

    m_browseButton = new QPushButton("Browse");
    connect(m_browseButton, &QPushButton::clicked, this, &NewProjectDialog::onBrowseDirectory);

    m_warningLabel = new QLabel();

    m_createButton = new QPushButton(mode == CREATE ? "Create" : "Save");
    connect(m_createButton, &QPushButton::clicked, this, &NewProjectDialog::createProjectDir);
    m_createButton->setDefault(true);
    m_cancelButton = new QPushButton("Cancel");
    connect(m_cancelButton, &QPushButton::clicked, this, &NewProjectDialog::reject);

    QGroupBox* projectGroup = new QGroupBox("Project name and location");

    QGridLayout* layout = new QGridLayout;
    layout->addWidget(nameLabel, 0, 0);
    layout->addWidget(m_projectNameEdit, 0, 1);
    layout->addWidget(parentDirLabel, 1, 0);
    layout->addWidget(m_workDirEdit, 1, 1);
    layout->addWidget(m_browseButton, 1, 2);

    projectGroup->setLayout(layout);

    QHBoxLayout* buttonsLayout = new QHBoxLayout;
    buttonsLayout->addStretch(1);
    buttonsLayout->addWidget(m_createButton);
    buttonsLayout->addWidget(m_cancelButton);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(projectGroup);
    mainLayout->addWidget(m_warningLabel);
    mainLayout->addStretch();
    mainLayout->addLayout(buttonsLayout);

    setLayout(mainLayout);

    setWorkingDirectory(workingDirectory);
    setProjectName(projectName);
}

QString NewProjectDialog::getWorkingDirectory() const
{
    return QDir::fromNativeSeparators(m_workDirEdit->text());
}

void NewProjectDialog::setWorkingDirectory(const QString& text)
{
    m_workDirEdit->setText(QDir::toNativeSeparators(text));
}

void NewProjectDialog::setProjectName(const QString& text)
{
    return m_projectNameEdit->setText(text);
}

QString NewProjectDialog::getProjectFileName() const
{
    QString projectDir = getWorkingDirectory() + QString("/") + getProjectName();
    QString projectFile = getProjectName() + ProjectDocument::projectFileExtension();
    QString result = projectDir + QString("/") + projectFile;
    return result;
}

//! calls directory selection dialog
void NewProjectDialog::onBrowseDirectory()
{
    QString dirname = QFileDialog::getExistingDirectory(
        this, "Select directory", getWorkingDirectory(),
        QFileDialog::DontResolveSymlinks | QFileDialog::ShowDirsOnly);

    if (!dirname.isEmpty()) {
        checkIfProjectPathIsValid(dirname);
        checkIfProjectNameIsValid(getProjectName());
    }
}

//! Checks whether ProjectPath is valid and sets warning state accordingly. Corresponding directory
//! should exists.
void NewProjectDialog::checkIfProjectPathIsValid(const QString& dirname)
{
    if (QFile::exists(dirname)) {
        setValidProjectPath(true);
        setWorkingDirectory(dirname);
    } else {
        setValidProjectPath(false);
    }
    updateWarningStatus();
}

//! Checks whether project name is valid and sets warning state accordingly. There should not be the
//! directory with such name in ProjectPath
void NewProjectDialog::checkIfProjectNameIsValid(const QString& projectName)
{
    const QDir projectDir = getWorkingDirectory() + "/" + projectName;
    setValidProjectName(!projectDir.exists());
    updateWarningStatus();
}

//! sets flags whether project name is valid and then updates color of LineEdit
//! and warning message
void NewProjectDialog::setValidProjectName(bool status)
{
    m_valid_projectName = status;
    QPalette palette;
    if (m_valid_projectName) {
        palette.setColor(QPalette::Text, Qt::black);
    } else {
        palette.setColor(QPalette::Text, Qt::darkRed);
    }
    m_projectNameEdit->setPalette(palette);
}

//! sets flags wether project path is valid and then updates color of LineEdit
//! and warning message
void NewProjectDialog::setValidProjectPath(bool status)
{
    m_valid_projectPath = status;
    QPalette palette;
    if (m_valid_projectPath) {
        palette.setColor(QPalette::Text, Qt::black);
    } else {
        palette.setColor(QPalette::Text, Qt::darkRed);
    }
    m_workDirEdit->setPalette(palette);
}

//! updates warning label depending on validity of project name and path
void NewProjectDialog::updateWarningStatus()
{
    if (m_valid_projectPath && m_valid_projectName) {
        m_createButton->setEnabled(true);
        m_warningLabel->setText("");
    } else if (!m_valid_projectPath) {
        m_createButton->setEnabled(false);
        m_warningLabel->setText("<font color='darkRed'> The path '"
                                + QDir::toNativeSeparators(getWorkingDirectory())
                                + "' does not exist. </font>");
    } else if (!m_valid_projectName) {
        m_createButton->setEnabled(false);
        if (getProjectName().isEmpty()) {
            m_warningLabel->setText("<font color='darkRed'> Please specify project name. </font>");
        } else {
            m_warningLabel->setText("<font color='darkRed'> The directory '" + getProjectName()
                                    + "' already exists. </font>");
        }
    }
}

//! creates directory with selected ProjectName in selected ProjectPath
void NewProjectDialog::createProjectDir()
{
    QDir parentDir = getWorkingDirectory();
    if (!parentDir.mkdir(getProjectName())) {
        m_warningLabel->setText("<font color='darkRed'> Can't make subdirectory' '"
                                + getProjectName() + "' in '"
                                + QDir::toNativeSeparators(getWorkingDirectory()) + "' </font>");
    } else {
        accept();
    }
}
