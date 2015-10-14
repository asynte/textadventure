#/clientstuff/dataflow
cmake_minimum_required(VERSION 2.8.12)
add_library(DataflowClient TCPDataflow.cpp)
target_include_directories(DataflowClient PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
