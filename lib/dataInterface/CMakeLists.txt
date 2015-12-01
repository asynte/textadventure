set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

cmake_minimum_required(VERSION 2.8.9)

add_library(npcDataInterface npcDataInterface.cpp)
add_library(objDataInterface objDataInterface.cpp)
add_library(roomDataInterface roomDataInterface.cpp)
add_library(resetDataInterface resetDataInterface.cpp)
add_library(dataEmitter dataEmitter.cpp)
add_library(spellDataInterface spellDataInterface.cpp)

target_link_libraries(npcDataInterface ${CMAKE_SOURCE_DIR}/lib/yaml/libyaml-cpp.a)
target_link_libraries(objDataInterface ${CMAKE_SOURCE_DIR}/lib/yaml/libyaml-cpp.a)
target_link_libraries(roomDataInterface ${CMAKE_SOURCE_DIR}/lib/yaml/libyaml-cpp.a)
target_link_libraries(resetDataInterface ${CMAKE_SOURCE_DIR}/lib/yaml/libyaml-cpp.a)
target_link_libraries(dataEmitter ${CMAKE_SOURCE_DIR}/lib/yaml/libyaml-cpp.a)
target_link_libraries(spellDataInterface ${CMAKE_SOURCE_DIR}/lib/yaml/libyaml-cpp.a)

