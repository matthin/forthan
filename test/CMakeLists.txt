set(testSourceFiles
  ${CMAKE_CURRENT_SOURCE_DIR}/main.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/Compiler.cc
)

include_directories(.)

add_executable(forthanTest ${testSourceFiles})
target_link_libraries(
  forthanTest
  forthan
)

