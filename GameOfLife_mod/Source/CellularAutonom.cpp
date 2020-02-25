#include "CellularAutonom.hpp"

// constructor in charge of generate the pix Vertex
CellularAutonom::CellularAutonom(const Config &config, const Application &app)
    : pConfig(&config), app(&app) {
  cellVertexPoints.reserve(config.simSize.x * config.simSize.y * 4);
  for (unsigned y = 0; y < config.simSize.y; y++) {
    for (unsigned x = 0; x < config.simSize.x; x++) {
      addQuad(x, y);
    }
  }
}

// render the vetexes
void CellularAutonom::render(sf::RenderWindow &window) {
  window.draw(cellVertexPoints.data(), cellVertexPoints.size(), sf::Quads);
}

// get the real index of the cell given it relative x, y position
unsigned CellularAutonom::getCellIndex(unsigned x, unsigned y) {
  return x + y * pConfig->simSize.x;
}

// set the color on the 4 corners of the cell
void CellularAutonom::setCellColor(int x, int y, sf::Color color) {
  auto index = getCellIndex(x, y) * 4;
  for (int i = 0; i < 4; i++) {
    cellVertexPoints[index + i].color = color;
  }
}

// create and store the corners of the cell
void CellularAutonom::addQuad(unsigned xIndex, unsigned yIndex) {
          //TODO
}
