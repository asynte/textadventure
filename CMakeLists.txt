#textadventure

cmake_minimum_required(VERSION 2.8)

project(iteration1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

#Boost directories needed for Jason
#set(Boost_INCLUDE_DIR /usr/include/boost)
#find_package(Boost REQUIRED)
#include_directories(${Boost_INCLUDE_DIR})

include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(lib)
add_subdirectory(tools)

