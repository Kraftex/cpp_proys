#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <array>

class Keyboard {
private:
  // array with "KeyCount" number of elements
  std::array<bool, sf::Keyboard::KeyCount> keys;

public:
  Keyboard();
  void update(sf::Event e);
  bool isKeyDown(sf::Keyboard::Key key) const;
};
#endif