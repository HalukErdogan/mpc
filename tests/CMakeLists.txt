add_executable(
  test_system
  system/test_continuous_system.cc
)
target_link_libraries(
  test_system
  mpc
  GTest::gtest_main
)

add_executable(
  test_integration
  integration/test_stepper.cc
)
target_link_libraries(
  test_integration
  mpc
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_system)
gtest_discover_tests(test_integration)