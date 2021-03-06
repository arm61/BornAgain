//  ************************************************************************************************
//
//  qt-mvvm: Model-view-view-model framework for large GUI applications
//
//! @file      mvvm/model/mvvm/project/projectmanager.h
//! @brief     Defines class CLASS?
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2020
//! @authors   Gennady Pospelov et al, Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#ifndef BORNAGAIN_MVVM_MODEL_MVVM_PROJECT_PROJECTMANAGER_H
#define BORNAGAIN_MVVM_MODEL_MVVM_PROJECT_PROJECTMANAGER_H

#include "mvvm/interfaces/projectmanagerinterface.h"
#include <memory>

namespace ModelView {

struct ProjectContext;

//! Responsible for handling new/save/save-as/close Project logic, where the Project represents
//! a collection of serialized application models in the project directory.

//! This ProjectManager requires certain prerequisites to function properly: for example,
//! the creation of a new project will be possible only if the old project is in a saved state. See
//! description to the class methods.

class MVVM_MODEL_EXPORT ProjectManager : public ModelView::ProjectManagerInterface {
public:
    ProjectManager(const ProjectContext& context);
    ~ProjectManager() override;

    ProjectManager(const ProjectManager& other) = delete;
    ProjectManager& operator=(const ProjectManager& other) = delete;

    bool createNewProject(const std::string& dirname) override;

    bool saveCurrentProject() override;

    bool saveProjectAs(const std::string& dirname) override;

    bool openExistingProject(const std::string& dirname) override;

    std::string currentProjectDir() const override;

    bool isModified() const override;

    bool closeCurrentProject() const override;

private:
    struct ProjectManagerImpl;
    std::unique_ptr<ProjectManagerImpl> p_impl;
};

} // namespace ModelView

#endif // BORNAGAIN_MVVM_MODEL_MVVM_PROJECT_PROJECTMANAGER_H
