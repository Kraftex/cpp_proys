#include "Application.hpp"

#include <ctime>
#include <iostream>
#include <thread>

#include "Native/Native.h"
#include "ResourceManager/ResourceHolder.hpp"
#include "Utils/Config.hpp"

Application::Application(const Config &config)
    : window({config.windowsSize.x, config.windowsSize.y}, "Cellullar Autonom(Game of Life)", sf::Style::Close ),
      pConfig(&config) {
          //TODO
}

// update the game if the window is open
void Application::run() {
  sf::Clock deltaClock;
  unsigned year = 0;
  window.setKeyRepeatEnabled(false);
  while (window.isOpen()) {
    guiText.setString("Generation: " + std::to_string(year++));
    fpsCounter.update();
    input(deltaClock.restart().asSeconds());
    autonom->update();
    render();
    pollEvents();
  }
}

// return a reference to the actuall window
const sf::RenderWindow &Application::getWindow() const { return window; }

// control the envetns: window and keyboard
void Application::pollEvents() {
  sf::Event e;
  while (window.pollEvent(e)) {
    keyboard.update(e);
    switch (e.type) {
    case sf::Event::Closed:
      window.close();
      break;
    }
  }
}

// actions while press specific keys
void Application::input(float dt) {
          //TODO
}

// render text,game and display the rendered frame
void Application::render() {
          //TODO
}

// center the screen
void Application::resetView() {
  view = sf::View();
  view.setCenter(
      {(float)pConfig->windowsSize.x / 2, (float)pConfig->windowsSize.y / 2});
  view.setSize({(float)pConfig->windowsSize.x, (float)pConfig->windowsSize.y});
}
