cmake_minimum_required(VERSION 3.29)
project(PROYECTO)

set(CMAKE_CXX_STANDARD 20)

add_executable(PROYECTO main.cpp
        Game.cpp
        Game.h
        Board.cpp
        Board.h
        Player.cpp
        Player.h)
