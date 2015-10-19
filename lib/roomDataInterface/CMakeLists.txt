set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

cmake_minimum_required(VERSION 2.8.9)

add_library(roomDataInterface roomDataInterface.cpp)

target_link_libraries(roomDataInterface ${CMAKE_SOURCE_DIR}/lib/yaml/libyaml-cpp.a)
