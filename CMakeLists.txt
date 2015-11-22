cmake_minimum_required(VERSION 3.3)
project(IMS_projekt)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lGLU -lGL -lglut")

set(SOURCE_FILES main.cpp areaCells.cpp areaCells.h cell.cpp cell.h)
add_executable(IMS_projekt ${SOURCE_FILES})