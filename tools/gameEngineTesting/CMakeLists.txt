#/root/tools/mainProgram

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
cmake_minimum_required(VERSION 2.8.9)


set(EXECUTABLE_NAME testGameEngine)

add_executable(${EXECUTABLE_NAME} testGameEngine.cpp)
#yaml library
target_link_libraries(${EXECUTABLE_NAME} ${CMAKE_SOURCE_DIR}/lib/yaml/libyaml-cpp.a)
#networking library
target_link_libraries(${EXECUTABLE_NAME} ${CMAKE_SOURCE_DIR}/lib/networkinglibrary/libDataflow.a)

#add all the libraries

#dataInterace Libraries
target_link_libraries(${EXECUTABLE_NAME} npcDataInterface)
target_link_libraries(${EXECUTABLE_NAME} objDataInterface)
target_link_libraries(${EXECUTABLE_NAME} roomDataInterface)
target_link_libraries(${EXECUTABLE_NAME} resetDataInterface)

#gameEngine Libraries
target_link_libraries(${EXECUTABLE_NAME} GameEngine)
target_link_libraries(${EXECUTABLE_NAME} Character)
target_link_libraries(${EXECUTABLE_NAME} Door)
target_link_libraries(${EXECUTABLE_NAME} NPC)
target_link_libraries(${EXECUTABLE_NAME} Object)
target_link_libraries(${EXECUTABLE_NAME} Room)
target_link_libraries(${EXECUTABLE_NAME} Widget)
target_link_libraries(${EXECUTABLE_NAME} World)
target_link_libraries(${EXECUTABLE_NAME} Extended)

#userAccount Libraries
target_link_libraries(${EXECUTABLE_NAME} Login)

#networkingInterface Libraries
target_link_libraries(${EXECUTABLE_NAME} TCPClient)
target_link_libraries(${EXECUTABLE_NAME} TCPDataflow)
target_link_libraries(${EXECUTABLE_NAME} TCPServer)

#userInterface Libraries
target_link_libraries(${EXECUTABLE_NAME} UserInterface)
target_link_libraries(${EXECUTABLE_NAME} Commands)
target_link_libraries(${EXECUTABLE_NAME} ObserverList)

#Adding Threads
find_package(Threads REQUIRED)
if(THREADS_HAVE_PTHREAD_ARG)
  set_property(TARGET ${EXECUTABLE_NAME} PROPERTY COMPILE_OPTIONS "-pthread")
  set_property(TARGET ${EXECUTABLE_NAME} PROPERTY INTERFACE_COMPILE_OPTIONS "-pthread")
endif()
if(CMAKE_THREAD_LIBS_INIT)
  target_link_libraries(${EXECUTABLE_NAME} "${CMAKE_THREAD_LIBS_INIT}")
endif()

#Adding NCurses
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
target_link_libraries(${EXECUTABLE_NAME} ${CURSES_LIBRARIES})
