#find_package(GTest REQUIRED)

enable_testing()

add_executable(
        main_test
        main_test.cpp
)
target_link_libraries(
        main_test
        gtest
        gtest_main
        pthread
)

#include(GoogleTest)
#gtest_discover_tests(main_test)