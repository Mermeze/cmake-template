cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_COMPILER_WORKS ON)
set(CMAKE_C_COMPILER_WORKS ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/FindWDK/cmake")
find_package(WDK REQUIRED)

project(PLACEHOLDER_MYPROJ)

#
# Generate compile_commands.json for LSP
#
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#
# Copy the latest compile_commands.json to the root directory
#
add_custom_target(
    copy-compile-commands ALL
    ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_BINARY_DIR}/compile_commands.json
        ${CMAKE_CURRENT_LIST_DIR}
    )

#
# We always want to generate tests
#
enable_testing()

#
# Allow the developer to select if Dynamic or Static libraries are built
#
OPTION (MYPROJ_BUILD_SHARED_LIBS "Build Shared Libraries" OFF)

#
# Add the "cmake" folder to the module path so all subprojects can load
# helper modules
#
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

#
# Add all projects here.
#

#
# First we add the kernel-mode projects as they do not need any special include or lib directories config.
# These should be build only on Windows. 
#
if (MSVC)
    add_subdirectory(PLACEHOLDER_MYPROJ_MYWINKMLIB)
    add_subdirectory(PLACEHOLDER_MYPROJ_MYWINKMDRIVER)
endif()

#
# Add the include and library directories from the EWDK, mandatory for UM projects
#
include_directories(
    "$ENV{WindowsSdkDir}\\Include\\$ENV{Version_Number}\\ucrt"
    "$ENV{WindowsSdkDir}\\Include\\$ENV{Version_Number}\\shared"
    "$ENV{WindowsSdkDir}\\Include\\$ENV{Version_Number}\\um"
    "$ENV{VCToolsInstallDir}\\include\\"
)
link_directories(
    "$ENV{WindowsSdkDir}\\Lib\\$ENV{Version_Number}\\um\\$ENV{Platform}\\"
    "$ENV{WindowsSdkDir}\\Lib\\$ENV{Version_Number}\\ucrt\\$ENV{Platform}\\"
    "$ENV{VCToolsInstallDir}\\lib\\spectre\\$ENV{Platform}\\"
)

#
# Now add all user-mode projects
#
add_subdirectory(PLACEHOLDER_MYPROJ_MYEXE)
add_subdirectory(PLACEHOLDER_MYPROJ_MYLIB)
add_subdirectory(PLACEHOLDER_MYPROJ_MYSTATICLIB)
