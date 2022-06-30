cmake_minimum_required(VERSION 3.7)

project(Snake)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(Snake
 Main.cpp
 Game.cpp
 SnakeGame.cpp
 Snake.cpp
 Food.cpp
 Rectangle.cpp
 Block.cpp
)

target_link_libraries(Snake ${SDL2_LIBRARIES})