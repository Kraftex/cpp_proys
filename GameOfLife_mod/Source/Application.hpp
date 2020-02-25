#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "CellularAutonom.hpp"
#include "Keyboard.hpp"
#include "Utils/FPSCounter.hpp"
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

struct config;

class Application {
private:
  std::unique_ptr<CellularAutonom> autonom;
  sf::RenderWindow window;
  FPSCounter fpsCounter;
  Keyboard keyboard;
  sf::Text guiText;
  sf::View view;
  const Config *pConfig = nullptr;
  float zoom = 1;
  
  void pollEvents();
  void input(float dt);
  void render();
  void resetView();

public:
  Application(const Config &config);
  const sf::RenderWindow &getWindow() const;
  void run();

  // create a unique T Game
  template <typename T> void init() {
    autonom = std::make_unique<T>(*pConfig, *this);
  }
};
#endif
