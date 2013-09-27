# file to build installer

option(BUILD_DEBIAN "Build a debian package" OFF)

include(InstallRequiredSystemLibraries)

set(BORNAGAIN_MAJOR_VERSION "0")
set(BORNAGAIN_MINOR_VERSION "9")
set(BORNAGAIN_PATCH_VERSION "0")

set(BORNAGAIN_VERSION "${BORNAGAIN_MAJOR_VERSION}.${BORNAGAIN_MINOR_VERSION}.${BORNAGAIN_PATCH_VERSION}")

set(CPACK_PACKAGE_NAME "BornAgain")
set(CPACK_PACKAGE_DESCRIPTION "BornAgain: simulate and fit scattering at grazing incidence.")
set(CPACK_PACKAGE_VENDOR "Sceintific Computing at MLZ")
set(CPACK_PACKAGE_VERSION ${BORNAGAIN_VERSION})
set(CPACK_PACKAGE_VERSION_MAJOR ${BORNAGAIN_MAJOR_VERSION})
set(CPACK_PACKAGE_VERSION_MINOR ${BORNAGAIN_MINOR_VERSION})
set(CPACK_PACKAGE_VERSION_PATCH ${BORNAGAIN_PATCH_VERSION})

configure_file(COPYING LICENSE.txt COPYONLY)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_BINARY_DIR}/LICENSE.txt")


#set(CPACK_MONOLITHIC_INSTALL ON)

# binary package setup
set(CPACK_PACKAGE_RELOCATABLE True)


if(CMAKE_BUILD_TYPE STREQUAL Release)
    set(CPACK_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}-${BORNAGAIN_VERSION}-${BORNAGAIN_ARCHITECTURE}")
else()
    set(CPACK_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}-${BORNAGAIN_VERSION}-${BORNAGAIN_ARCHITECTURE}-${CMAKE_BUILD_TYPE}")
endif()

set(CPACK_PACKAGE_INSTALL_DIRECTORY "${CMAKE_PROJECT_NAME}-${BORNAGAIN_VERSION}")

if(WIN32)
  set(CPACK_GENERATOR "NSIS")  
elseif(APPLE)
  #set(CPACK_GENERATOR "PackageMaker;TGZ")
  set(CPACK_GENERATOR "STGZ;TGZ")
elseif(UNIX AND BUILD_DEBIAN) # one can build debian package only on UNIX system
  set(CPACK_GENERATOR "DEB")
else()
  set(CPACK_GENERATOR "STGZ;TGZ")
endif()

#configure_file(cmake/Templates/CMakeCPackOptions.cmake.in CMakeCPackOptions.cmake @ONLY)
#set(CPACK_PROJECT_CONFIG_FILE ${CMAKE_BINARY_DIR}/CMakeCPackOptions.cmake)

set(CPACK_NSIS_MODIFY_PATH ON)

# Generating the source package
set(CPACK_SOURCE_GENERATOR "TGZ")
set(CPACK_SOURCE_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH}")

# Specify which files do not include into the source package generated by make package_source
set(CPACK_SOURCE_IGNORE_FILES
    ${CPACK_SOURCE_IGNORE_FILES} # first take the default parameters
    "/Doc/UserManual/"
    "/dev-tools/edit-scripts/"
    "/dev-tools/packaging/"
    "/dev-tools/tmp-examples/"
    "/dev-tools/tmp-unsorted/"
    "/GUI/"
    "/XCode_BornAgain.xcodeproj/"
    "~$"
    "/.git/"
    "/\\\\.git/"
    "/\\\\\\\\.git/"  # more screeneng symbols is neccesary because of double file processing by cmake and cpack
    "\\\\\\\\.swp$"
    "\\\\.swp$"
    "/.metadata/"
    "/.settings/"
    "\\\\.cproject"
    "\\\\.project"
    "\\\\.lssrc"
    "\\\\.DS_Store"
    "\\\\.obj"
)


if(BUILD_DEBIAN)
# parameters to build a debian package
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Marina Ganeva <m.ganeva@fz-juelich.de>") 

# Architecture: (mandatory)
IF(NOT CPACK_DEBIAN_PACKAGE_ARCHITECTURE)
  # There is no such thing as i686 architecture on debian, you should use i386 instead
  # $ dpkg --print-architecture
  FIND_PROGRAM(DPKG_CMD dpkg)
  IF(NOT DPKG_CMD)
    MESSAGE(STATUS "Can not find dpkg in your path, default to i386.")
    SET(CPACK_DEBIAN_PACKAGE_ARCHITECTURE i386)
  ENDIF(NOT DPKG_CMD)
  EXECUTE_PROCESS(COMMAND "${DPKG_CMD}" --print-architecture
    OUTPUT_VARIABLE CPACK_DEBIAN_PACKAGE_ARCHITECTURE
    OUTPUT_STRIP_TRAILING_WHITESPACE
    )
ENDIF(NOT CPACK_DEBIAN_PACKAGE_ARCHITECTURE)

if(${CPACK_DEBIAN_PACKAGE_ARCHITECTURE} MATCHES "i686")
	SET(CPACK_DEBIAN_PACKAGE_ARCHITECTURE i386)
endif()


set(CPACK_DEBIAN_PACKAGE_NAME "${CPACK_PACKAGE_NAME}")
set(CPACK_DEBIAN_PACKAGE_PRIORITY "optional")
set(CPACK_DEBIAN_PACKAGE_SECTION "devel")
set(CPACK_STRIP_FILES "TRUE")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libgsl, libboost, libfftw3, libpython") # [TODO:] set versions
set(CPACK_DEBIAN_PACKAGE_DESCRIPTION	"${CPACK_PACKAGE_DESCRIPTION}")
set(CPACK_DEBIAN_PACKAGE_VERSION 1)
set(CPACK_PACKAGE_FILE_NAME "${CPACK_DEBIAN_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}-${CPACK_DEBIAN_PACKAGE_VERSION}_${CMAKE_SYSTEM_PROCESSOR}")

# write changelog file

# write copyrite file [TODO:] fix the text of copyright
file(WRITE "${CMAKE_BINARY_DIR}/copyright"
     "Copyright (C) 2013 Sceintific Computing at MLZ

   This software is licensed under the terms of the
   GNU General Public License Version 3.

   Software distributed under the License is distributed
   on an ``AS IS'' basis, WITHOUT WARRANTY OF ANY KIND, either
   express or implied. See the GPL for the specific language
   governing rights and limitations.

   You should have received a copy of the GPL along with this
   program. If not, go to http://www.gnu.org/licenses/gpl.html
   or write to the Free Software Foundation, Inc.,
   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.

On Debian systems, the complete text of the GNU General Public
License can be found in `/usr/share/common-licenses/GPL-3'.")

install(FILES "${CMAKE_BINARY_DIR}/copyright"
        DESTINATION "share/doc/${CPACK_DEBIAN_PACKAGE_NAME}")


    FIND_PROGRAM(GIT_EXECUTABLE git)
    FIND_PROGRAM(GIT2CL_EXECUTABLE git2cl)

    if(GIT_EXECUTABLE AND GIT2CL_EXECUTABLE)
	set(GIT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/.git")
	execute_process(COMMAND ${GIT_EXECUTABLE} --git-dir=${GIT_DIR} log 
            COMMAND ${GIT2CL_EXECUTABLE}
            COMMAND gzip -9
            OUTPUT_FILE "${CMAKE_BINARY_DIR}/changelog.gz")
    install(FILES "${CMAKE_BINARY_DIR}/changelog.gz"
        DESTINATION "share/doc/${CPACK_DEBIAN_PACKAGE_NAME}")
    else()
        MESSAGE(STATUS "W: git or git2cl not found. Can't create the debian changelog file.")
    endif(GIT_EXECUTABLE AND GIT2CL_EXECUTABLE)
endif()


# check if such commands are exist

include(CPack)

set(CPACK_COMPONENTS_ALL Libraries Headers Examples)

#cpack_add_install_type(full      DISPLAY_NAME "Full Installation")
#cpack_add_install_type(runtime   DISPLAY_NAME "Runtime Installation")
#cpack_add_install_type(developer DISPLAY_NAME "Developer Installation")

# - Components for Development
#cpack_add_component(Headers
#    DISPLAY_NAME "Development Components (headers)" 
#    DESCRIPTION "Install all files needed for developing BornAgain applications"
#    INSTALL_TYPES developer full
#)

# - Components for Runtime
#cpack_add_component(Libraries
#    DISPLAY_NAME "BornAgain runtime Libraries" 
#    DESCRIPTION "Install all BornAgain libraries"
#    INSTALL_TYPES runtime developer full
#)

# - Components for Examples
#cpack_add_component(Examples 
#    DISPLAY_NAME "Usage Examples"
#    DESCRIPTION "Install all BornAgain examples"
#    INSTALL_TYPES full developer
#)

#cpack_add_component(Applications
#    DISPLAY_NAME "Applications"
#    DESCRIPTION "Install all BornAgain executables"
##    INSTALL_TYPES full developer
#)


# - Components for Data
#cpack_add_component(Data 
#    DISPLAY_NAME "Geant4 Data Files" 
#    DESCRIPTION "Install all Geant4 data files"
#    INSTALL_TYPES full
#)


