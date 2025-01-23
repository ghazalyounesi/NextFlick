cmake_minimum_required(VERSION 3.30)
project(NextFlick)

set(CMAKE_CXX_STANDARD 20)

add_executable(NextFlick main.cpp
        users.cpp
        users.h
        user.h
        admin.cpp
        admin.h
        Media.h
        Film.h
        Series.h
        splayTree.cpp
        splayTree.h
        Globals.h)
