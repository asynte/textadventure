#/root/tools/mainProgram

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

cmake_minimum_required(VERSION 2.8.9)

add_executable(testWidget jasonWidgets.cpp)
#set_target_properties(testWidget PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")
#yaml library
target_link_libraries(testWidget ${CMAKE_SOURCE_DIR}/lib/yaml/libyaml-cpp.a)
#networking library
target_link_libraries(testWidget ${CMAKE_SOURCE_DIR}/lib/networkinglibrary/libDataflow.a)

#add all the libraries

#dataInterace Libraries
target_link_libraries(testWidget npcDataInterface)
target_link_libraries(testWidget objDataInterface)

#gameEngine Libraries
target_link_libraries(testWidget Character)
target_link_libraries(testWidget Door)
target_link_libraries(testWidget NPC)
target_link_libraries(testWidget Object)
target_link_libraries(testWidget Room)
target_link_libraries(testWidget Widget)
target_link_libraries(testWidget World)

#userAccount Libraries
target_link_libraries(testWidget Login)

#networkingInterface Libraries
target_link_libraries(testWidget TCPClient)
target_link_libraries(testWidget TCPDataflow)
target_link_libraries(testWidget TCPServer)

#userInterface Libraries
target_link_libraries(testWidget UserInterface)
target_link_libraries(testWidget Commands)
target_link_libraries(testWidget ObserverList)

find_package(Threads REQUIRED)
if(THREADS_HAVE_PTHREAD_ARG)
  set_property(TARGET testWidget PROPERTY COMPILE_OPTIONS "-pthread")
  set_property(TARGET testWidget PROPERTY INTERFACE_COMPILE_OPTIONS "-pthread")
endif()
if(CMAKE_THREAD_LIBS_INIT)
  target_link_libraries(testWidget "${CMAKE_THREAD_LIBS_INIT}")
endif()




