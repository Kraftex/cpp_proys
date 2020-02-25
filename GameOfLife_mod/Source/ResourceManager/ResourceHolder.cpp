#include "ResourceHolder.hpp"

ResourceHolder::ResourceHolder()
    : fonts("Fonts", "ttf"), textures("Textures", "png") {}

// return a unique holder
ResourceHolder &ResourceHolder::get() {
  static ResourceHolder holder;
  return holder;
}