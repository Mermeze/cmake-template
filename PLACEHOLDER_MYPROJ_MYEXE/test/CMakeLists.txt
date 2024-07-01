cmake_minimum_required (VERSION 3.20)

include(EnsureGTest)
ensure_gtest()

add_executable(
    PLACEHOLDER_TARGET_MYEXE_test
    test.cpp
)

target_link_libraries(
    PLACEHOLDER_TARGET_MYEXE_test
    PRIVATE GTest::gtest_main PLACEHOLDER_MYPROJ_MYEXE_lib
)

include(GoogleTest)
gtest_discover_tests(PLACEHOLDER_TARGET_MYEXE_test)
