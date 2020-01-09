cmake_minimum_required(VERSION 3.15)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

add_executable(untitled main.cpp Lexer.cpp Lexer.h OpenServerCommand.cpp OpenServerCommand.h ConditionParser.cpp ConditionParser.h Command.cpp Command.h ConnectCommand.cpp ConnectCommand.h Parser.cpp Parser.h PrintCommand.cpp PrintCommand.h CommandDataBase.cpp CommandDataBase.h ExpressionFactory.cpp ExpressionFactory.h BoolExpression.cpp BoolExpression.h ExpressionReader.cpp ExpressionReader.h)