cmake_minimum_required(VERSION 2.8)
project(forthan CXX)

add_subdirectory(src)
include_directories(include/forthan)
include_directories(opt/catch/include)

add_library(
  forthan
  STATIC
  ${forthanSourceFiles}
)

ADD_DEFINITIONS(-std=c++11)
SET(CMAKE_EXE_LINKER_FLAGS "-pthread")

add_subdirectory(test)
enable_testing()
add_test(NAME forthanTest COMMAND forthanTest)

# Additional optional tools
add_subdirectory(tools/cli_parser)

