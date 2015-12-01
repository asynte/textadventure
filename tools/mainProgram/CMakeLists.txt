#/root/tools/mainProgram

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
cmake_minimum_required(VERSION 2.8.9)


set(EXECUTABLE_NAME alphaversion)

add_executable(alphaversion main.cpp)
#add_executable(alphaversion gameEngineTest.cpp)

#yaml library
target_link_libraries(alphaversion ${CMAKE_SOURCE_DIR}/lib/yaml/libyaml-cpp.a)
#networking library
target_link_libraries(alphaversion ${CMAKE_SOURCE_DIR}/lib/networkinglibrary/libDataflow.a)

#add all the libraries

#dataInterace Libraries
target_link_libraries(alphaversion npcDataInterface)
target_link_libraries(alphaversion objDataInterface)
target_link_libraries(alphaversion roomDataInterface)
target_link_libraries(alphaversion resetDataInterface)
target_link_libraries(alphaversion dataEmitter)
target_link_libraries(alphaversion spellDataInterface)

#gameEngine Libraries
target_link_libraries(alphaversion GameEngine)
target_link_libraries(alphaversion Character)
target_link_libraries(alphaversion Door)
target_link_libraries(alphaversion Reset)
target_link_libraries(alphaversion NPC)
target_link_libraries(alphaversion Object)
target_link_libraries(alphaversion Room)
target_link_libraries(alphaversion Widget)
target_link_libraries(alphaversion World)
target_link_libraries(alphaversion Extended)
target_link_libraries(alphaversion Spell)
target_link_libraries(alphaversion OffSpell)
target_link_libraries(alphaversion DefSpell)
target_link_libraries(alphaversion SpellShop)

#userAccount Libraries
target_link_libraries(alphaversion Login)

#networkingInterface Libraries
target_link_libraries(alphaversion TCPClient)
target_link_libraries(alphaversion TCPDataflow)
target_link_libraries(alphaversion TCPServer)

#userInterface Libraries
target_link_libraries(alphaversion UserInterface)
target_link_libraries(alphaversion Commands)
target_link_libraries(alphaversion ObserverList)

#Adding Threads
find_package(Threads REQUIRED)
if(THREADS_HAVE_PTHREAD_ARG)
  set_property(TARGET alphaversion PROPERTY COMPILE_OPTIONS "-pthread")
  set_property(TARGET alphaversion PROPERTY INTERFACE_COMPILE_OPTIONS "-pthread")
endif()
if(CMAKE_THREAD_LIBS_INIT)
  target_link_libraries(alphaversion "${CMAKE_THREAD_LIBS_INIT}")
endif()

#Adding NCurses
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
target_link_libraries(alphaversion ${CURSES_LIBRARIES})
