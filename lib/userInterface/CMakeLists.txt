#root/lib/userInterface

add_library(Commands Commands.cpp)
add_library(ObserverList ObserverList.cpp)
add_library(UserInterface UserInterface.cpp)

target_link_libraries(Commands UserInterface)
target_link_libraries(ObserverList UserInterface)
#target_link_libraries(UserInterface UserInterface)
