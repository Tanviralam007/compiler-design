cmake_minimum_required(VERSION 3.10)
project(HTMLCompiler)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCES
    src/main.cpp
    src/lexer.cpp
    src/parser.cpp
    src/code_generator.cpp
    src/error_handler.cpp
    src/symbol_table.cpp
)

add_executable(HTMLCompiler ${SOURCES})

add_custom_target(run_all
    COMMAND $<TARGET_FILE:HTMLCompiler> ${CMAKE_SOURCE_DIR}/input.html
    COMMAND g++ -o output_program ${CMAKE_CURRENT_BINARY_DIR}/output.cpp
    COMMAND output_program
    DEPENDS HTMLCompiler
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)