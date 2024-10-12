cmake_minimum_required(VERSION 3.30)
project(cbq_fw VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_definitions(-DENABLE_LOGGING)

add_subdirectory(cbq_fw)
add_subdirectory(game)
