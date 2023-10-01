cmake_minimum_required(VERSION 3.26)
project(HW_3)

# Include Catch2
include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v2.13.0  # Replace with the desired version
)
FetchContent_MakeAvailable(Catch2)

set(CMAKE_CXX_STANDARD 17)

add_executable(HW_3 main.cpp
        tests/tests_main.cpp
        reversed.cpp)
