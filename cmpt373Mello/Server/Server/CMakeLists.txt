#/network root/Server/Server

cmake_minimum_required(VERSION 2.8.12)

add_library(Server TCPServer.cpp)

target_include_directories(Server PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

