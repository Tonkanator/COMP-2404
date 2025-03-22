#include "TextArea.h"
#include <iostream>
#include <string>

TextArea::TextArea(): dimensions{0, 0, 0, 0}, id("N/A"), text("N/A"), fill(RGB(255,255,255)), border(RGB(255,255,255)) {}
TextArea::TextArea(int x, int y, int width, int height, const std::string& id, const std::string& label): dimensions{x, y, width, height}, id(id), text(label), fill(RGB(255,255,255)), border(RGB(0,0,0)){}
TextArea::TextArea(Rectangle rect, const std::string& id, const std::string& label): dimensions(rect), id(id), text(label), fill(RGB(255,255,255)), border(RGB(255,255,255)){}
TextArea::TextArea(int x, int y, int width, int height, const std::string& id, const std::string& label, RGB fill, RGB border): dimensions{x, y, width, height}, id(id), text(label), fill(fill), border(border){}
TextArea::TextArea(Rectangle rectangle, const std::string& id, const std::string& label, RGB fill, RGB border): dimensions(rectangle), id(id), text(label), fill(fill), border(border){}

void TextArea::draw(Display* display, Window win, GC gc, int x, int y) {
    XSetForeground(display, gc, fill.getColour());
    XFillRectangle(display, win, gc, x, y, dimensions.width, dimensions.height);

    XSetForeground(display, gc, border.getColour());
    XDrawRectangle(display, win, gc, x, y, dimensions.width, dimensions.height);

    XSetForeground(display, gc, RGB::BLACK().getColour());
    XDrawString(display, win, gc, x + 5, y + 15, text.c_str(), text.length());
}

bool TextArea::overlaps(const TextArea& ta) const{
    return dimensions.overlaps(ta.dimensions);
}

void TextArea::print() const{
    std::cout << "TextArea id:        " << id << std::endl;
    std::cout << "Preferred location: " << dimensions.x << ", " << dimensions.y << std::endl;
    std::cout << "Size:               " << dimensions.width << ", " << dimensions.height << std::endl;
    std::cout << "Text:               " << text << std::endl;
}

void TextArea::setBorder(RGB colour){
    border = colour;
}
void TextArea::setFill(RGB colour){
    fill = colour;
}

std::string TextArea::getID() const{
    return id;
}

Rectangle TextArea::getDimensions() const{
    return dimensions;
}

void TextArea::setText(const std::string& text){
    this->text = text;
}

void TextArea::setHeight(int height){
    dimensions.height = height;
}