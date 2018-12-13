cmake_minimum_required(VERSION 3.13)
project(first_step)

set(CMAKE_CXX_STANDARD 14)

add_executable(first_step main.cpp Command.h defineVarCommand.cpp defineVarCommand.h openServerCommand.cpp openServerCommand.h connectCommand.cpp connectCommand.h conditionParser.h loopCommand.cpp loopCommand.h ifComand.cpp ifComand.h Lexer.cpp Lexer.h)