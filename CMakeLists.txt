cmake_minimum_required(VERSION 3.10)
project(HTMLCompiler)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    src/main.cpp
    src/lexer.cpp
    src/parser.cpp
    src/code_generator.cpp
    src/error_handler.cpp
    src/symbol_table.cpp
)

add_executable(HTMLCompiler ${SOURCES})