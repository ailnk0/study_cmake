add_executable(hchat-test
    test.cpp
)

target_link_libraries(hchat-test
    GTest::gtest_main
    hchat
)

include(GoogleTest)
gtest_discover_tests(hchat-test)
