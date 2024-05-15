cmake_minimum_required(VERSION 3.20)

enable_testing()

include(EnsureGTest)
ensure_gtest()

add_executable(
    PLACEHOLDER_MYPROJ_MYLIB_test
    test.cpp
)

target_link_libraries(
    PLACEHOLDER_MYPROJ_MYLIB_test
    PRIVATE GTest::gtest_main PLACEHOLDER_MYPROJ_MYLIB
)

#
# If build as sharedlib/dll, then we need to copy it to the directory
# containing the unittest executable
#
if (MYPROJ_BUILD_SHARED_LIBS)
    add_custom_command(
        TARGET PLACEHOLDER_MYPROJ_MYLIB_test
        PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:PLACEHOLDER_MYPROJ_MYLIB_test> $<TARGET_FILE_DIR:PLACEHOLDER_MYPROJ_MYLIB_test>
        COMMAND_EXPAND_LISTS
    )
endif()

include(GoogleTest)
gtest_discover_tests(PLACEHOLDER_MYPROJ_MYLIB_test)
