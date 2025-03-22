#include "Panel.h"

Panel::Panel(Rectangle dimensions, const std::string& id): Component(dimensions, id) {}

Panel::Panel(int x, int y, int width, int height, const std::string& id): Component(x, y, width, height, id) {}

void Panel::print() const {
    std::cout << "Panel id:                 " << id << std::endl;
    std::cout << "Preferred dimensions:     " << dimensions.width << ", " << dimensions.height << std::endl;
    std::cout << "Contained components:     " << getSize() << std::endl;
}
void Panel::printComponents() const {
    for (int i=0; i<getSize(); i++){
        get(i)->print();
    }
}