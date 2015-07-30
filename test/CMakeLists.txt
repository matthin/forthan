set(testSourceFiles
  ${CMAKE_CURRENT_SOURCE_DIR}/main.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/Compiler.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/Interpreter.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/Parser.cc
)

include_directories(.)

add_executable(forthanTest ${testSourceFiles})
target_link_libraries(
  forthanTest
  forthan
)

