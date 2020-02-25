// #ifndef FPS_COUNTER_HPP
// #define FPS_COUNTER_HPP

#include <SFML/Graphics.hpp>

class FPSCounter {
public:
  // crea el texto y lo posiciona
  FPSCounter();
  // actualiza el texto
  void update();
  // dibuja el texto en pantalla
  void draw(sf::RenderTarget &renderer);

private:
  // texto y fuente para el mismo
  sf::Text text;
  sf::Font font;

  // tiempo de delay y tiempo entre fotogramas
  sf::Clock delayTimer;
  sf::Clock fpsTimer;
  // fps medio;
  float fps = 0;
  // cuenta los frames en el tiempo
  int frameCount = 0;
};

// #endif