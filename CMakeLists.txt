cmake_minimum_required(VERSION 3.0)
project(progProject)

set(CMAKE_CXX_FLAGS "-Wall -std=c++11 -pedantic")

set(SOURCE_FILES src/main.cpp src/filtrage.cpp src/errors.cpp src/seuillage.cpp)
add_executable(colorReduce ${SOURCE_FILES})  
