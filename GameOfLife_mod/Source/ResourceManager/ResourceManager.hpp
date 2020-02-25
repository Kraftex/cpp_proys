#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <string>
#include <unordered_map>

template <typename Resource> class ResourceManager {
  using String = std::string;

private:
  String folder;
  String extention;
  std::unordered_map<String, Resource> resources;

  String getFullName(const String &name) { return folder + name + extention; }

public:
  ResourceManager(const String &folder, const String &extention)
      : folder("Res/" + folder + "/"), extention("." + extention) {}

  // return a reasource with the parameter name
  const Resource &get(const String &name) {
    if (!exist(name)) {
      add(name);
    }
    return resources.at(name);
  }
  // if doesn't exist a file with the paraemeter name
  // inserte a fail, inserte ther resourse in others
  void add(const String &name) {
    Resource r;
    if (!r.loadFromFile(getFullName(name))) {
      Resource fail;
      fail.loadFromFile(folder + "_fail_" + extention);
      resources.insert(std::make_pair(name, fail));
    } else {
      resources.insert(std::make_pair(name, r));
    }
  }
  // given a name, if it exist in the map return true, false in others
  bool exist(const String &name) const {
    return resources.find(name) != resources.end();
  }
};

#endif