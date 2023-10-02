cmake_minimum_required(VERSION 3.26)
project(A_)

set(CMAKE_CXX_STANDARD 17)

add_executable(A_ main.cpp
        piece.cpp
        piece.h
        face.cpp
        face.h
        dodecahedron.cpp
        dodecahedron.h
        state_node.cpp
        state_node.h
        advanced_node.cpp
        advanced_node.h)