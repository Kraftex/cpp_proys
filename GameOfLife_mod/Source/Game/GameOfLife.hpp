#ifndef GAME_OF_LIFE_HPP
#define GAME_OF_LIFE_HPP

#include "../CellularAutonom.hpp"
#include <vector>
class GameOfLife : public CellularAutonom {
  enum Cell { On, Off };

  // private:
  // matrix of pairs of Cell and bool, each one represent a point in the screen.
  // If the boolean value is true, the cell is "alive"
private:
  std::vector<Cell> cells;

public:
  GameOfLife(const Config &config, const Application &app);
  void update() override;
};
#endif