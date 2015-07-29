add_subdirectory(src)
include_directories(include/cli_parser)

add_executable(forthanCLI ${cliParserSourceFiles})
target_link_libraries(forthanCLI forthan)

