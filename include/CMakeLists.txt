#/root/include

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

cmake_minimum_required(VERSION 2.8.9)

add_subdirectory(dataInterfaceHeaders)
add_subdirectory(gameEngineHeaders)
add_subdirectory(userAccountHeaders)
add_subdirectory(networkingHeaders)
add_subdirectory(userInterfaceHeaders)



