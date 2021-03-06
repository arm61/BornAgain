//  ************************************************************************************************
//
//  BornAgain: simulate and fit reflection and scattering
//
//! @file      GUI/coregui/mainwindow/actionmanager.cpp
//! @brief     Implements class ActionManager
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#include "GUI/coregui/mainwindow/actionmanager.h"
#include "Base/Utils/Assert.h"
#include "Base/Utils/SysUtils.h"
#include "GUI/coregui/Views/CommonWidgets/DocksController.h"
#include "GUI/coregui/mainwindow/PyImportAssistant.h"
#include "GUI/coregui/mainwindow/UpdateNotifier.h"
#include "GUI/coregui/mainwindow/aboutapplicationdialog.h"
#include "GUI/coregui/mainwindow/mainwindow.h"
#include "GUI/coregui/mainwindow/mainwindow_constants.h"
#include "GUI/coregui/mainwindow/projectmanager.h"
#include "GUI/coregui/utils/hostosinfo.h"
#include "GUI/coregui/utils/qstringutils.h"
#include "Views/JobView.h"
#include "Views/SampleView.h"
#include <QDir>
#include <QMenuBar>
#include <QSettings>
#include <QShortcut>

ActionManager::ActionManager(MainWindow* parent)
    : QObject(parent)
    , m_mainWindow(parent)
    , m_newAction(nullptr)
    , m_openAction(nullptr)
    , m_saveAction(nullptr)
    , m_saveAsAction(nullptr)
    , m_exitAction(nullptr)
    , m_aboutAction(nullptr)
    , m_menuBar(nullptr)
    , m_fileMenu(nullptr)
    , m_settingsMenu(nullptr)
    , m_viewMenu(nullptr)
    , m_recentProjectsMenu(nullptr)
    , m_helpMenu(nullptr)
    , m_importMenu(nullptr)
    , m_runSimulationShortcut(nullptr)
{
    createActions();
    createMenus();
    createGlobalShortcuts();

    connect(m_mainWindow, &MainWindow::currentViewChanged, this,
            &ActionManager::onCurrentViewChanged);
}

void ActionManager::createActions()
{
    ProjectManager* projectManager = m_mainWindow->projectManager();
    ASSERT(projectManager);

    // new project action
    m_newAction = new QAction("&New Project", m_mainWindow);
    m_newAction->setShortcuts(QKeySequence::New);
    m_newAction->setStatusTip("Create a new project");
    connect(m_newAction, &QAction::triggered, projectManager, &ProjectManager::newProject);

    // open project action
    m_openAction = new QAction("&Open Project", m_mainWindow);
    m_openAction->setShortcuts(QKeySequence::Open);
    m_openAction->setStatusTip("Open an existing project");
    connect(m_openAction, &QAction::triggered, projectManager,
            [projectManager]() { projectManager->openProject(); });

    // save project action
    m_saveAction = new QAction("&Save Project", m_mainWindow);
    m_saveAction->setShortcuts(QKeySequence::Save);
    m_saveAction->setStatusTip("Save project");
    m_saveAction->setShortcutContext(Qt::ApplicationShortcut);
    connect(m_saveAction, &QAction::triggered, projectManager,
            [projectManager]() { projectManager->saveProject(); });

    // save-as project action
    m_saveAsAction = new QAction("Save &As...", m_mainWindow);
    m_saveAsAction->setShortcuts(QKeySequence::SaveAs);
    m_saveAsAction->setStatusTip("Save project under different name");
    connect(m_saveAsAction, &QAction::triggered, projectManager, &ProjectManager::saveProjectAs);

    // exit application action
    m_exitAction = new QAction("E&xit Application", this);
    m_exitAction->setShortcuts(QKeySequence::Quit);
    m_exitAction->setStatusTip("Exit the application");
    connect(m_exitAction, &QAction::triggered, m_mainWindow, &MainWindow::close);

    // about application action
    m_aboutAction = new QAction("About &BornAgain", this);
    m_aboutAction->setStatusTip("About the application");
    connect(m_aboutAction, &QAction::triggered, this, &ActionManager::onAboutApplication);
}

void ActionManager::createMenus()
{
    m_menuBar = new QMenuBar(0); // No parent (System menu bar on Mac OS X)

    if (!GUI_OS_Utils::HostOsInfo::isMacHost())
        m_mainWindow->setMenuBar(m_menuBar);

    // File Menu
    m_fileMenu = m_menuBar->addMenu("&File");
    m_fileMenu->addAction(m_newAction);
    m_fileMenu->addAction(m_openAction);
    connect(m_fileMenu, &QMenu::aboutToShow, this, &ActionManager::onAboutToShowFileMenu);

    m_recentProjectsMenu = m_fileMenu->addMenu("&Recent Projects");

    m_fileMenu->addSeparator();
    m_fileMenu->addAction(m_saveAction);
    m_fileMenu->addAction(m_saveAsAction);

    // Import submenu
    m_fileMenu->addSeparator();
    m_importMenu = m_fileMenu->addMenu("&Import");
    m_importMenu->setToolTipsVisible(true);
    QAction* action = m_importMenu->addAction("&Import from Python script (experimental)");
    action->setToolTip("Import sample from Python script.\n The script should contain a function "
                       "returning a valid multi-layer.");

#ifdef BORNAGAIN_PYTHON
    connect(action, &QAction::triggered, this, &ActionManager::onImportFromPythonScript);
    if (GUI_OS_Utils::HostOsInfo::isMacHost())
        if (SysUtils::getenv("PYTHONHOME").empty())
            action->setEnabled(false);
#endif // BORNAGAIN_PYTHON

    m_fileMenu->addSeparator();
    m_fileMenu->addAction(m_exitAction);

    // Settings Menu
    m_settingsMenu = new QMenu("&Settings", m_mainWindow);
    onAboutToShowSettingsMenu(); // MacOS feature: action should exist already, otherwise menuBar
                                 // will not add menu
    connect(m_settingsMenu, &QMenu::aboutToShow, this, &ActionManager::onAboutToShowSettingsMenu);
    m_menuBar->addMenu(m_settingsMenu);

    // View menu
    m_viewMenu = new QMenu("&View", m_mainWindow);
    onAboutToShowViewMenu(); // MacOS feature: action should exist already, otherwise menuBar will
                             // not add menu
    connect(m_viewMenu, &QMenu::aboutToShow, this, &ActionManager::onAboutToShowViewMenu);
    m_menuBar->addMenu(m_viewMenu);

    // Help Menu
    m_helpMenu = m_menuBar->addMenu("&Help");
    m_helpMenu->addAction(m_aboutAction);

    onCurrentViewChanged();
}

void ActionManager::createGlobalShortcuts()
{
    m_runSimulationShortcut = new QShortcut(QKeySequence("Ctrl+r"), m_mainWindow);
    m_runSimulationShortcut->setContext((Qt::ApplicationShortcut));
    connect(m_runSimulationShortcut, &QShortcut::activated, m_mainWindow,
            &MainWindow::onRunSimulationShortcut);
}

void ActionManager::onAboutToShowFileMenu()
{
    m_recentProjectsMenu->clear();

    bool hasRecentProjects = false;
    int orderNr = 1;
    for (QString file : m_mainWindow->projectManager()->recentProjects()) {
        hasRecentProjects = true;
        QString actionText = GUI_StringUtils::withTildeHomePath(QDir::toNativeSeparators(file));
        if (orderNr < 10)
            actionText = QString("&%1 ").arg(orderNr) + actionText;
        QAction* action = m_recentProjectsMenu->addAction(actionText);
        action->setData(QVariant::fromValue(file));
        connect(action, &QAction::triggered, m_mainWindow, &MainWindow::openRecentProject);
        orderNr++;
    }
    m_recentProjectsMenu->setEnabled(hasRecentProjects);

    if (hasRecentProjects) {
        m_recentProjectsMenu->addSeparator();
        QAction* action = m_recentProjectsMenu->addAction("&Clear Menu");
        connect(action, &QAction::triggered, m_mainWindow->projectManager(),
                &ProjectManager::clearRecentProjects);
    }
}

void ActionManager::onAboutToShowSettingsMenu()
{
    m_settingsMenu->clear();
    QSettings settings;

    settings.beginGroup(Constants::S_UPDATES);
    QAction* action = m_settingsMenu->addAction("&Check for Updates");
    action->setToolTip("Checks for updates available on GUI startup.");
    action->setCheckable(true);
    action->setChecked(settings.value(Constants::S_CHECKFORUPDATES, false).toBool());
    connect(action, &QAction::toggled, this, &ActionManager::toggleCheckForUpdates);
    settings.endGroup();

    settings.beginGroup(Constants::S_SESSIONMODELVIEW);
    action = m_settingsMenu->addAction("&Model tech view");
    action->setToolTip("Additional developer's view will appear in left control tab bar");
    action->setCheckable(true);
    action->setChecked(settings.value(Constants::S_VIEWISACTIVE, false).toBool());
    connect(action, &QAction::toggled, this, &ActionManager::setSessionModelViewActive);
    settings.endGroup();

    action = m_settingsMenu->addAction("&Enable autosave");
    action->setToolTip("Project will be saved periodically in project's autosave directory.\n"
                       "When opening project, recover option will be suggested, if possible.");
    action->setCheckable(true);
    action->setChecked(m_mainWindow->projectManager()->isAutosaveEnabled());
    connect(action, &QAction::toggled, m_mainWindow->projectManager(),
            &ProjectManager::setAutosaveEnabled);

    m_settingsMenu->setToolTipsVisible(true);
}

void ActionManager::onAboutToShowViewMenu()
{
    m_viewMenu->clear();

    auto view = m_mainWindow->currentView();
    if (auto sampleView = dynamic_cast<SampleView*>(view); sampleView != nullptr)
        sampleView->fillViewMenu(m_viewMenu);
    if (auto jobView = dynamic_cast<JobView*>(view); jobView != nullptr)
        jobView->fillViewMenu(m_viewMenu);
}

void ActionManager::toggleCheckForUpdates(bool status)
{
    m_mainWindow->updateNotifier()->setCheckUpdatesFlag(status);
    m_mainWindow->updateNotifier()->checkForUpdates();
}

void ActionManager::setSessionModelViewActive(bool status)
{
    QSettings settings;
    settings.beginGroup(Constants::S_SESSIONMODELVIEW);
    settings.setValue(Constants::S_VIEWISACTIVE, status);
    settings.endGroup();
    m_mainWindow->onSessionModelViewActive(status);
}

void ActionManager::onAboutApplication()
{
    AboutApplicationDialog dialog(m_mainWindow);
    dialog.exec();
}

void ActionManager::onCurrentViewChanged()
{
    // not every view support view menu entries -> hide it, if empty
    onAboutToShowViewMenu();
    m_viewMenu->menuAction()->setVisible(!m_viewMenu->actions().isEmpty());
}

#ifdef BORNAGAIN_PYTHON
void ActionManager::onImportFromPythonScript()
{
    PyImportAssistant assistant(m_mainWindow);
    assistant.exec();
}
#endif // BORNAGAIN_PYTHON
