#include "Keyboard.hpp"

// Start all keys to false
Keyboard::Keyboard() { std::fill(keys.begin(), keys.end(), false); }

// Given an event. If a key is pressed, it associated in the array is change:
// into true and false if it's released.
void Keyboard::update(sf::Event e) {
    //TODO
}

// return the current state of the parameter key
bool Keyboard::isKeyDown(sf::Keyboard::Key key) const { return keys.at(key); }
