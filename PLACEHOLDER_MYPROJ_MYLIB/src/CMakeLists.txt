cmake_minimum_required(VERSION 3.20)
include(GenerateExportHeader)

#
# Set LIB_TYPE according to the project option
#
set(LIB_TYPE STATIC)
if (MYPROJ_BUILD_SHARED_LIBS)
  set(LIB_TYPE SHARED)
endif()

add_library(
    PLACEHOLDER_MYPROJ_MYLIB
    ${LIB_TYPE}
    PLACEHOLDER_MYPROJ_MYLIB.cpp
)
target_include_directories(
    PLACEHOLDER_MYPROJ_MYLIB ${WARNING_GUARD}
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include_internal/>
)

#
# Generate the export header that defines the import/export macros
#
generate_export_header(PLACEHOLDER_MYPROJ_MYLIB
             BASE_NAME PLACEHOLDER_MYPROJ_MYLIB
             INCLUDE_GUARD_NAME __PLACEHOLDER_MYPROJ_MYLIB_H__
             EXPORT_MACRO_NAME PLACEHOLDER_MYPROJ_MYLIB_EXPORT
             EXPORT_FILE_NAME "${CMAKE_CURRENT_SOURCE_DIR}/include/PLACEHOLDER_MYPROJ_MYLIB_Export.h"
             STATIC_DEFINE MYLIB_BUILT_AS_STATIC
)

#
# We do not need import/export macros if statically built
#
if (NOT MYPROJ_BUILD_SHARED_LIBS)
    target_compile_definitions(PLACEHOLDER_MYPROJ_MYLIB PUBLIC MYLIB_BUILT_AS_STATIC)
endif()
