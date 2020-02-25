cmake_minimum_required(VERSION 3.8.2)
project(GameOfLife)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2.4 REQUIRED graphics window system)

set(SOURCES 

    Source/Game/GameOfLife.cpp 

    Source/Native/Win32.cpp
    Source/Native/Unix.cpp
    Source/ResourceManager/ResourceHolder.cpp
    Source/Utils/FPSCounter.cpp 
    Source/Application.cpp 
    Source/CellularAutonom.cpp 

    Source/Keyboard.cpp
    Source/Main.cpp
)

add_executable(GameOfLife ${SOURCES})

set_property(TARGET GameOfLife PROPERTY CXX_STANDARD 17)

target_link_libraries(GameOfLife ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
