#root/lib/networkingInterface

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

cmake_minimum_required(VERSION 2.8.9)

add_library(TCPClient TCPClient.cpp)
add_library(TCPDataflow TCPDataflow.cpp)
add_library(TCPServer TCPServer.cpp)



target_link_libraries(TCPDataflow ${CMAKE_SOURCE_DIR}/lib/networkinglibrary/libDataflow.a)
target_link_libraries(TCPClient ${CMAKE_SOURCE_DIR}/lib/networkinglibrary/libDataflow.a)
target_link_libraries(TCPServer ${CMAKE_SOURCE_DIR}/lib/networkinglibrary/libDataflow.a)