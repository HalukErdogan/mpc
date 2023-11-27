# cmake version
cmake_minimum_required(VERSION 3.20)

# project name
project(mpc)

# add exteral libraries
add_subdirectory(external)

# find required libraries
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

# mpc library
add_library(mpc INTERFACE)
target_include_directories(mpc INTERFACE .)
target_link_libraries(mpc INTERFACE Eigen3::Eigen)

# test
enable_testing()
add_subdirectory(tests)