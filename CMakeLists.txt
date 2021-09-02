cmake_minimum_required(VERSION 3.20)

project(ascii_roguelike)

set(CMAKE_CXX_STANDARD 11)

find_package(Curses)

file(COPY level1.txt DESTINATION ${CMAKE_BINARY_DIR})

add_executable(ascii_roguelike main.cpp Game.cpp Game.h Player.cpp Player.h Level.cpp Level.h Enemy.cpp Enemy.h)

target_link_libraries(ascii_roguelike Curses)
