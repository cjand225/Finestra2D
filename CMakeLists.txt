#Change this if you need to target a specific CMake version
cmake_minimum_required(VERSION 2.6)

set(PROJECT_NAME Finestra2D)
set(EXECUTABLE_NAME "${PROJECT_NAME}")
project("${PROJECT_NAME}")

include_directories("${PROJECT_BINARY_DIR}")
include_directories(inc)

#find SFML
find_package(SFML CONFIG REQUIRED window graphics system audio network)


# Define sources and executable
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE FLAC OpenAL OpenGL Vorbis sfml-window sfml-graphics sfml-system sfml-audio sfml-network)

