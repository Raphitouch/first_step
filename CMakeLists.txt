cmake_minimum_required(VERSION 3.13)
project(first_step)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(first_step main.cpp Command.h openServerCommand.cpp openServerCommand.h connectCommand.cpp connectCommand.h conditionParser.h Lexer.h Lexer.cpp Parser.cpp Parser.h printCommand.cpp printCommand.h varCommand.cpp varCommand.h conditionParser.cpp Expression.h  BinaryExpression.h Plus.cpp Plus.h Minus.cpp Minus.h Mul.cpp Mul.h Div.cpp Div.h SmallerThen.cpp SmallerThen.h BiggerThen.cpp BiggerThen.h SmallerAndEqualThen.cpp SmallerAndEqualThen.h BiggerAndEqualThen.cpp BiggerAndEqualThen.h EqualThen.cpp EqualThen.h NotEqualThen.cpp NotEqualThen.h Number.h Number.cpp ShuntingYard.cpp ShuntingYard.h BinaryExpression.cpp equalCommand.cpp equalCommand.h exitCommand.cpp exitCommand.h sleepCommand.cpp sleepCommand.h DataReaderServer.cpp DataReaderServer.h)
