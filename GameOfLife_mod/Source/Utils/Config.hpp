#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

struct Config {
  Config() = default;
  Config(const sf::Vector2u windowsSize, unsigned cellSize)
      : windowsSize(windowsSize), cellSize(cellSize) {
    init();
  }

  void init() {
    windowsSize.x -= windowsSize.x % cellSize;
    windowsSize.y -= windowsSize.y % cellSize;
    simSize.x = windowsSize.x / cellSize;
    simSize.y = windowsSize.y / cellSize;
  }
  sf::Vector2u windowsSize = {1280, 720};
  sf::Vector2u simSize;

  sf::Color bgColor = {150, 150, 150};
  sf::Color fgColor = {25, 25, 25};

  unsigned cellSize = 5;
  unsigned fps = 30;
};

#endif
