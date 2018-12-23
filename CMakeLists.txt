cmake_minimum_required(VERSION 3.13)
project(first_step)

set(CMAKE_CXX_STANDARD 14)

add_executable(first_step main.cpp Command.h openServerCommand.cpp openServerCommand.h connectCommand.cpp connectCommand.h conditionParser.h Lexer.h Lexer.cpp Parser.cpp Parser.h equalCommand.cpp equalCommand.h printCommand.cpp printCommand.h varCommand.cpp varCommand.h conditionParser.cpp)