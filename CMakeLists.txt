cmake_minimum_required(VERSION 3.15)
project(widget_project)

# Выбираем 20ый стандарт C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(widget_project sqlite3.h sqlite3.c database3.h main.cpp)