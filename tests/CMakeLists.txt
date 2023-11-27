add_executable(
  test_system
  system/test_continuous_system.cc
)
target_link_libraries(
  test_system
  mpc
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_system)