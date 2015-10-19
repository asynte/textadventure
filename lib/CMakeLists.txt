#root/lib

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

cmake_minimum_required(VERSION 2.8.9)

add_subdirectory(npcDataInterface)
add_subdirectory(objDataInterface)
add_subdirectory(roomDataInterface)
add_subdirectory(gameEngine)
add_subdirectory(userAccount)
add_subdirectory(networkingInterface)
add_subdirectory(userInterface)
