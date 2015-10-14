#/network root/clientStuff

cmake_minimum_required(VERSION 2.8.12)
#project(networking)

#include in sub folders
#add_library(tcpClient TCPClient.cpp)
#target_include_directories(tcpClient PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


#include in sub folders
#add_library(tcpDataflow TCPDataflow.cpp)
#target_include_directories(tcpDataflow PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(Client)
add_subdirectory(Dataflow)

#include in main folder
add_executable(tcpCodeClient TCPCodeClient.cpp)
target_link_libraries(tcpCodeClient LINK_PUBLIC DataflowClient)
target_link_libraries(tcpCodeClient LINK_PUBLIC Client)
#add subfolders for each library



