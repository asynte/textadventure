#root/lib/userInterface

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_library(Commands Commands.cpp)
add_library(ObserverList ObserverList.cpp)
add_library(UserInterface UserInterface.cpp)
#add_library(Cout Cout.cpp)

target_link_libraries(Commands UserInterface)
target_link_libraries(ObserverList UserInterface)

#target_link_libraries(UserInterface Cout)


