cmake_minimum_required(VERSION 3.20)

#
# Build a static library with all sources except *_main.cpp. We do
# this in order to ease testing by having gtest link with the lib
#
add_library(
    PLACEHOLDER_MYPROJ_MYEXE_lib
    STATIC
    PLACEHOLDER_MYPROJ_MYEXE.cpp
)
target_include_directories(
    PLACEHOLDER_MYPROJ_MYEXE_lib ${WARNING_GUARD}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>
)

#
# main executable target should only contain _main.cpp source
#
add_executable(
    PLACEHOLDER_MYPROJ_MYEXE
    PLACEHOLDER_MYPROJ_MYEXE_main.cpp
)
#
# now link with the lib contianing the actual applicatoin code
#
target_link_libraries(
    PLACEHOLDER_MYPROJ_MYEXE
    PRIVATE
    PLACEHOLDER_MYPROJ_MYEXE_lib
)
