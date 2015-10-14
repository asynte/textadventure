#/clientstuff/client
cmake_minimum_required(VERSION 2.8.12)
add_library(Client TCPClient.cpp)
target_include_directories(Client PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
