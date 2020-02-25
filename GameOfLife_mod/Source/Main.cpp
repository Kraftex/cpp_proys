#include "Application.hpp"
#include "Game/GameOfLife.hpp"
#include "Native/Native.h"
#include <fstream>
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

namespace {
    void setConsolePosition() {
#ifdef _WIN32
        HWND consoleWindow = GetConsoleWindow();
        SetWindowPos(consoleWindow, 0, 0, 0, 500, 500, SWP_NOSIZE | SWP_NOZORDER);
#endif
    }

    Config config;

    void loadConfig() {
        std::ifstream inFile("config.txt");
        if (!inFile.is_open()) {
            std::cout << "Unable to load config, making default settings\n";
            config = {{1280, 720}, 4};
            return;
        }
        std::string line;
        while (std::getline(inFile, line)) {
            if (line == "fps")
                inFile >> config.fps;
            else if (line == "winx")
                inFile >> config.windowsSize.x;
            else if (line == "winy")
                inFile >> config.windowsSize.y;
            else if (line == "cellsize")
                inFile >> config.cellSize; 
        }
        config.init();
        std::cout << "detalles de config: " << std::endl;
        std::cout << "fps:       " << config.fps << std::endl;
        std::cout << "winSize:   " << std::endl;
        std::cout << "        x: " << config.windowsSize.x << std::endl;
        std::cout << "        y: " << config.windowsSize.y << std::endl;
        std::cout << "simSize:   " << std::endl;
        std::cout << "        x: " << config.simSize.x << std::endl;
        std::cout << "        y: " << config.simSize.y << std::endl;
    }

    template <typename T> void run() {
        std::cout << TextColour::Green << "Controls: \n" << TextColour::Default;
        std::cout << "Up - Zoom in\nDown - Zoom out\nWASD - Move Around\n";
        std::cout << "R - Reset the view\n";
        Application app(config);
        app.init<T>();
        app.run();
        std::cout << '\n';
    }

} // namespace

int main() {
    setConsolePosition();
    loadConfig();
    run<GameOfLife>();
    return EXIT_SUCCESS;
}
