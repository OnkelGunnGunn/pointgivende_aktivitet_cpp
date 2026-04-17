cmake_minimum_required(VERSION 3.16)

project(svenske_nummerplader LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

find_package( REQUIRED)

add_executable(svenske_nummerplader src/main.cpp) 