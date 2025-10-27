cmake_minimum_required(VERSION 3.23)
project(RPG)

set(CMAKE_CXX_STANDARD 11)
set( CMAKE_CXX_STANDARD_REQUIRED True)


include_directories(include)

set(SOURCE_FILES
        src/main.cpp
        src/Character.cpp
        src/Player.cpp
        src/Enemy.cpp
        src/Inventory.cpp
        src/Item.cpp
        src/Map.cpp
        src/NPC.cpp
        src/Game.cpp
)
add_executable(RPG ${SOURCE_FILES})

