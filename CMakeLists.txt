
cmake_minimum_required(VERSION 2.8)
# The project name
project(MyProject)
# The C++ standard version. Can be 98 11 14 or 17
set(CMAKE_CXX_STANDARD 17)
set(SFML_INCLUDE_DIR "./SFML/include")
set(SFML_LIBRARY_DIR "./SFML/build/lib")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

add_executable(
    chess 
    main.cpp
    board.cpp
    piece.cpp
    
    )
target_link_libraries (chess sfml-graphics sfml-window sfml-system)