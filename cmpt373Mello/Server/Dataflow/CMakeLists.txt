#/network root/Server/Dataflow

cmake_minimum_required(VERSION 2.8.12)

add_library(DataflowServer TCPDataflow.cpp)

target_include_directories(DataflowServer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

