#include "GameOfLife.hpp"
#include <iostream>
#include <random>
// constructor wich generate cells to simulate with random value(dead or alive)
GameOfLife::GameOfLife(const Config &config, const Application &app)
    : CellularAutonom(config, app),
      cells((config.simSize.x * config.simSize.y)) {
  std::mt19937 rng((unsigned)std::time(nullptr));
  // se crea una lambdaFuncion que recive los parametros x,y desde la llamada de
  // cellForEach de CellularAutonom por referencia
  cellForEach([&](unsigned x, unsigned y){}/*TODO: Lambda*/);
}
// Una celula muerta vive, si 3 a su alrededor estan vivas
// una celula viva, sigue viva si 2 o 3 celulas vivas estan a su alrededor, caso
// contrario la celula muere
void GameOfLife::update() {
  std::vector<std::pair<sf::Vector2i, Cell>> updates;
  cellForEach([&](unsigned x, unsigned y) {
    sf::Vector2i loc(x, y);
    unsigned count = 0;
    for (int nX = -1; nX <= 1; nX++) {
      for (int nY = -1; nY <= 1; nY++) {
        int newX = nX + x;
        int newY = nY + y;
        if (newX == -1 || newX == (int)pConfig->simSize.x || newY == -1 ||
            newY == (int)pConfig->simSize.y || // out of bounds
            (nX == 0 && nY == 0)) {            // cell itself
          continue;
        }
        auto cell = cells.at(getCellIndex(newX, newY));
        if (cell == Cell::On) {
          count++;
        }
      }
    }
    //TODO: Update
  });
  for (auto &update : updates) {
    int index = getCellIndex(update.first.x, update.first.y);
    cells.at(index) = update.second;
    CellularAutonom::setCellColor(update.first.x, update.first.y,
                                  update.second == Cell::On ? pConfig->bgColor
                                                            : pConfig->fgColor);
  }
}
