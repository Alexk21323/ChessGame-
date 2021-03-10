cmake_minimum_required(VERSION 2.8)
# The project name
project(MyProject)
# The C++ standard version. Can be 98 11 14 or 17
set(CMAKE_CXX_STANDARD 17)
set(SFML_INCLUDE_DIR "./SFML/include")
set(SFML_LIBRARY_DIR "./SFML/build/lib")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)
ADD_SUBDIRECTORY(googletest)
find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

add_executable(
    chess 
    main.cpp
    board.cpp
    grid.cpp
    )


    
add_executable(
    move
    test/move_test.cpp
    board.cpp
    grid.cpp

    )

    TARGET_LINK_LIBRARIES(move gtest sfml-graphics sfml-window sfml-system)
    TARGET_COMPILE_DEFINITIONS(move PRIVATE gtest_disable_pthreads=ON)

add_executable(
    piece
    test/piece_test.cpp
    board.cpp
    grid.cpp

    )
    

TARGET_LINK_LIBRARIES(piece gtest sfml-graphics sfml-window sfml-system)
TARGET_COMPILE_DEFINITIONS(piece PRIVATE gtest_disable_pthreads=ON)


add_executable(
    possible
    test/possibleMove_test.cpp
    board.cpp
    grid.cpp
    )
TARGET_LINK_LIBRARIES(possible gtest gmock sfml-graphics sfml-window sfml-system)
TARGET_COMPILE_DEFINITIONS(possible PRIVATE gtest_disable_pthreads=ON)

target_link_libraries (chess sfml-graphics sfml-window sfml-system)
    

