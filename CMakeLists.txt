cmake_minimum_required(VERSION 3.5)
project(clc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp src/CliOptions.cpp src/CliOptions.h src/lexer/ClcLexer.cpp src/lexer/ClcLexer.h src/lexer/Token.cpp src/lexer/Token.h)
add_executable(clc ${SOURCE_FILES})