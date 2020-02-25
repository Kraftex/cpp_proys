#!/bin/bash

if [[ $# -eq 1 ]]; then
$1 Source/Main.cpp Source/Application.cpp Source/Application.hpp Source/CellularAutonom.cpp Source/CellularAutonom.hpp Source/Keyboard.cpp Source/Keyboard.hpp Source/Game/GameOfLife.cpp Source/Game/GameOfLife.hpp Source/ResourceManager/ResourceHolder.cpp Source/ResourceManager/ResourceHolder.hpp Source/ResourceManager/ResourceManager.hpp Source/Utils/Config.hpp Source/Utils/FPSCounter.cpp Source/Utils/FPSCounter.hpp
fi
