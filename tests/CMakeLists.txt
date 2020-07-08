cmake_minimum_required(VERSION 2.6)

set (Boost_USE_STATIC_LIBS OFF)
find_package (Boost REQUIRED COMPONENTS unit_test_framework)

find_package(SFML CONFIG REQUIRED window graphics system audio network)
include_directories(Finestra2D_lib)

add_executable (tests_run unitTests/engineTests.cpp unitTests/rendererTests.cpp)
target_link_libraries (tests_run ${Boost_LIBRARIES})
target_link_libraries (tests_run FLAC OpenAL OpenGL Vorbis sfml-window sfml-graphics sfml-system sfml-audio sfml-network)