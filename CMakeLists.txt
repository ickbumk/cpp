cmake_minimum_required(VERSION 3.28.3)
project(assignment1 CXX)

add_executable(polynomial_integrate polynomial_integrate.cpp)
add_executable(unittest unittest.cpp)


target_include_directories(polynomial_integrate PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}$)
target_include_directories(unittest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}$)