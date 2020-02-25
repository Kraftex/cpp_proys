#include "FPSCounter.hpp"
#include "../ResourceManager/ResourceHolder.hpp"

#include <iostream>

FPSCounter::FPSCounter() {
  // Set the possition of the text in the screan
  text.move(10, 20);
  // Set the size, color size and  of the text in the screan
  text.setFillColor(sf::Color::Yellow);
  text.setFont(ResourceHolder::get().fonts.get("arial"));
  text.setCharacterSize(15);
  text.setOutlineColor(sf::Color::Black);
  text.setOutlineThickness(2);
}

// increase the frameCounter and update the fps value and restart the counters
// if the delayTimer is less than 0.2
void FPSCounter::update() {
  frameCount++;
  if (delayTimer.getElapsedTime().asSeconds() > 0.2) {
    fps = frameCount / fpsTimer.restart().asSeconds();
    frameCount = 0;
    delayTimer.restart();
  }
}
// given a RenderTarget, it draw the text in screen
void FPSCounter::draw(sf::RenderTarget &renderer) {
  text.setString("FPS: " + std::to_string((int)fps));
  renderer.draw(text);
}