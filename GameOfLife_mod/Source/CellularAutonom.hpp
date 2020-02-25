#ifndef CELLULAR_AUTONOM_HPP
#define CELLULAR_AUTONOM_HPP

//#include "PixelGroup.hpp"

#include "Utils/Config.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class Application;

class CellularAutonom {

protected:
  const Application *const app;
  const Config *const pConfig;
  std::vector<sf::Vertex> cellVertexPoints;

  unsigned getCellIndex(unsigned x, unsigned y);
  void setCellColor(int x, int y, sf::Color color);
  // function with other function as parameter
  template <typename Func> void cellForEach(Func function);
  void addQuad(unsigned xIndex, unsigned yIndex);

public:
  CellularAutonom(const Config &config, const Application &app);
  virtual ~CellularAutonom() = default;
  // pure virtual function, make the class absstract
  virtual void update() = 0;
  virtual void onRenderGUI(sf::RenderWindow &window){};
  void render(sf::RenderWindow &window);
};

// call a function 1 time for each cells
template <typename Func> void CellularAutonom::cellForEach(Func function) {
  for (unsigned y = 0; y < pConfig->simSize.y; y++) {
    for (unsigned x = 0; x < pConfig->simSize.x; x++) {
      function(x, y);
    }
  }
}

#endif
