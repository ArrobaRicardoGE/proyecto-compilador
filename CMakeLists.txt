cmake_minimum_required(VERSION 3.14)
project(proyecto-compilador)

set(CMAKE_CXX_STANDARD 14)


add_library(util util.cpp)
add_library(lexicalAnalyzer lexicalAnalyzer.cpp util)
add_library(expressionEvaluator expressionEvaluator.cpp)
add_library(sintacticAnalyzer asignar.cpp expresion.cpp declarar.cpp util read.cpp expresionMatematica.cpp print.cpp ciclo.cpp ifElse.cpp sintacticAnalyzer.cpp cicloFor.cpp)


add_executable(main main.cpp util lexicalAnalyzer expressionEvaluator sintacticAnalyzer asignar.cpp expresion.cpp declarar.cpp util read.cpp expresionMatematica.cpp print.cpp ciclo.cpp ifElse.cpp sintacticAnalyzer.cpp cicloFor.cpp)