set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

cmake_minimum_required(VERSION 2.8.9)

add_library(Character Character.cpp)
add_library(Door Door.cpp)
add_library(Monster Monster.cpp)
add_library(NPC NPC.cpp)
add_library(Object Object.cpp)
add_library(Room Room.cpp)
add_library(Widget Widget.cpp)
add_library(World World.cpp)


target_link_libraries(World ${CMAKE_SOURCE_DIR}/lib/yaml/libyaml-cpp.a)
target_link_libraries(Room Door)
target_link_libraries(Room World)
