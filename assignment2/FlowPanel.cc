#include "FlowPanel.h"
#include <iostream>
#include <X11/Xlib.h>

FlowPanel::FlowPanel(int x, int y, int width, int height, const std::string& id, int xgap, int ygap): dimensions({x, y, width, height}), id(id), xgap(xgap), ygap(ygap) {}

FlowPanel::FlowPanel(Rectangle& rectangle, const std::string& id, int xgap, int ygap): dimensions(rectangle), id(id), xgap(xgap), ygap(ygap) {}

FlowPanel::FlowPanel(const FlowPanel& panel): id(panel.id), dimensions(panel.dimensions), xgap(panel.xgap), ygap(panel.ygap) {
    //deep copy of textAreas
    for (int i=0; i<panel.textAreas.getSize(); i++){
        TextArea* ta = new TextArea(*panel.textAreas.get(i));
        textAreas.add(ta);
    }
}

FlowPanel::~FlowPanel()
{
    for (int i=0; i<textAreas.getSize(); i++)
    {
        if (textAreas.get(i)){
            delete textAreas.get(i);
        }
    }
}

bool FlowPanel::addTextArea(TextArea* ta){
    return textAreas.add(ta);
}

bool FlowPanel::addTextArea(TextArea* ta, int index){
    return textAreas.add(ta, index);
}

TextArea* FlowPanel::getTextArea(const std::string& id) const{
    for (int i=0; i<textAreas.getSize(); i++){
        if (textAreas.get(i)->getID() == id){
            return textAreas.get(i);
        }
    }
    return nullptr;
}

TextArea* FlowPanel::getTextArea(int index) const{
    return textAreas.get(index);
}

TextArea* FlowPanel::removeTextArea(const std::string& id){
    return textAreas.remove(id);
}

TextArea* FlowPanel::removeTextArea(int index){
    return textAreas.remove(index);
}

bool FlowPanel::overlaps(FlowPanel& panel) const{
    return dimensions.overlaps(panel.dimensions);
}

void FlowPanel::draw(Display* display, Window win, GC graphicsContext) const{
    XSetForeground(display, graphicsContext, RGB::BLACK().getColour());
    XDrawRectangle(display, win, graphicsContext, dimensions.x, dimensions.y, dimensions.width, dimensions.height);

    int x = dimensions.x + xgap;
    int y = dimensions.y + ygap;
    int rowHeight = 0;

    for (int i = 0; i < textAreas.getSize(); ++i) {
        TextArea* ta = textAreas.get(i);
        if (!ta) continue;

        if (x + ta->getDimensions().width > dimensions.x + dimensions.width) {
            x = dimensions.x + xgap;
            y += rowHeight + ygap;
            rowHeight = 0;
        }

        if (y + ta->getDimensions().height > dimensions.y + dimensions.height) break;

        ta->draw(display, win, graphicsContext, x, y);

        x += ta->getDimensions().width + xgap;
        if (ta->getDimensions().height > rowHeight) {
            rowHeight = ta->getDimensions().height;
        }
    }
}

void FlowPanel::print() const{
    std::cout << "FlowPanel:    " << id << std::endl;
    std::cout << "Position:     " << dimensions.x << ", " << dimensions.y << std::endl;
    std::cout << "Size:         " << dimensions.width << ", " << dimensions.height << std::endl;
}

void FlowPanel::printTextAreas() const{
    for (int i=0; i<textAreas.getSize(); i++){
        textAreas.get(i)->print();
    }
}

std::string FlowPanel::getID() const{
    return id;
}

Rectangle FlowPanel::getDimensions() const{
    return dimensions;
}