#ifndef RESOURCE_HOLDER_HPP
#define RESOURCE_HOLDER_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "ResourceManager.hpp"

class ResourceHolder {
private:
  ResourceHolder();
  // not generete the move and copy constructor and assignament
  ResourceHolder &operator=(const ResourceHolder &) = delete;
  ResourceHolder &operator=(ResourceHolder &&) = delete;
  ResourceHolder(ResourceHolder &) = delete;
  ResourceHolder(ResourceHolder &&) = delete;

public:
  static ResourceHolder &get();
  ResourceManager<sf::Font> fonts;
  ResourceManager<sf::Texture> textures;
};
#endif