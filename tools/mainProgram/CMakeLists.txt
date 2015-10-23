#/root/tools/mainProgram

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
cmake_minimum_required(VERSION 2.8.9)

set(EXECUTABLE_NAME alphaversion)

add_executable(${EXECUTABLE_NAME} main.cpp)





#external libraries
	#yaml library
		target_link_libraries(${EXECUTABLE_NAME} ${CMAKE_SOURCE_DIR}/lib/yaml/libyaml-cpp.a)

	#networking library
		target_link_libraries(${EXECUTABLE_NAME} ${CMAKE_SOURCE_DIR}/lib/networkinglibrary/libDataflow.a)


#local libraries
	#dataInterace Libraries
		target_link_libraries(${EXECUTABLE_NAME} npcDataInterface)
		target_link_libraries(${EXECUTABLE_NAME} objDataInterface)

	#gameEngine Libraries
		target_link_libraries(${EXECUTABLE_NAME} Character)
		target_link_libraries(${EXECUTABLE_NAME} Door)
		target_link_libraries(${EXECUTABLE_NAME} Monster)
		target_link_libraries(${EXECUTABLE_NAME} NPC)
		target_link_libraries(${EXECUTABLE_NAME} Object)
		target_link_libraries(${EXECUTABLE_NAME} Room)
		target_link_libraries(${EXECUTABLE_NAME} Widget)
		target_link_libraries(${EXECUTABLE_NAME} World)

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

		#Pthread Library
		find_package(Threads REQUIRED)
		if(THREADS_HAVE_PTHREAD_ARG)
		  set_property(TARGET ${EXECUTABLE_NAME} PROPERTY COMPILE_OPTIONS "-pthread")
		  set_property(TARGET ${EXECUTABLE_NAME} PROPERTY INTERFACE_COMPILE_OPTIONS "-pthread")
		endif()
		if(CMAKE_THREAD_LIBS_INIT)
		  target_link_libraries(${EXECUTABLE_NAME} "${CMAKE_THREAD_LIBS_INIT}")
		endif()

		#NCurses Library
		find_package(Curses REQUIRED)
		include_directories(${CURSES_INCLUDE_DIR})
		target_link_libraries(${EXECUTABLE_NAME} ${CURSES_LIBRARIES})


