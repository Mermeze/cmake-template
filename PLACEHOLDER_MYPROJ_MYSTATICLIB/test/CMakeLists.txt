cmake_minimum_required (VERSION 3.20)

enable_testing()

include(EnsureGTest)
ensure_gtest()

add_executable(
    PLACEHOLDER_TARGET_MYSTATICLIB_test
    test.cpp
)

target_link_libraries(
    PLACEHOLDER_TARGET_MYSTATICLIB_test
    PRIVATE GTest::gtest_main PLACEHOLDER_MYPROJ_MYSTATICLIB
)

include(GoogleTest)
gtest_discover_tests(PLACEHOLDER_TARGET_MYSTATICLIB_test)
