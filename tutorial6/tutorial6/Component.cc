#include "Component.h"

Component::Component(Rectangle dimensions, const std::string& id): dimensions(dimensions), id(id) {}

Component::Component(int x, int y, int width, int height, const std::string& id): dimensions({x, y, width, height}), id(id) {}

bool Component::overlaps(Component& component) const{
    return dimensions.overlaps(component.dimensions);
}
void Component::print() const{
    std::cout << "Component id:        " << id << std::endl;
    std::cout << "Preferred location: " << dimensions.x << ", " << dimensions.y << std::endl;
    std::cout << "Size:               " << dimensions.width << ", " << dimensions.height << std::endl;
}

std::string Component::getID(){
    return id;
}