set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

cmake_minimum_required(VERSION 2.8.9)

add_library(Character Character.cpp)
add_library(Reset Reset.cpp)
add_library(Door Door.cpp)
add_library(NPC NPC.cpp)
add_library(Object Object.cpp)
add_library(Room Room.cpp)
add_library(Widget Widget.cpp)
add_library(World World.cpp)
add_library(Extended Extended.cpp)
add_library(GameEngine GameEngine.cpp)
add_library(Spell Spell.cpp)
add_library(OffSpell OffSpell.cpp)
add_library(DefSpell DefSpell.cpp)
add_library(SpellShop SpellShop.cpp)



target_link_libraries(World ${CMAKE_SOURCE_DIR}/lib/yaml/libyaml-cpp.a)
target_link_libraries(World Widget)
target_link_libraries(World Character)

target_link_libraries(Room Door)
target_link_libraries(Room World)
target_link_libraries(Room Extended)

target_link_libraries(Door Extended)

target_link_libraries(Widget NPC)
target_link_libraries(Widget Object)
target_link_libraries(Widget Character)


target_link_libraries(OffSpell Spell)
target_link_libraries(DefSpell Spell)


target_link_libraries(SpellShop Spell)
target_link_libraries(SpellShop OffSpell)
target_link_libraries(SpellShop DefSpell)
target_link_libraries(SpellShop spellDataInterface)




#target_link_libraries(Character Widget)
#target_link_libraries(Character NPC)
#target_link_libraries(Character Object)
#target_link_libraries(Character Room)

target_link_libraries(GameEngine World)
