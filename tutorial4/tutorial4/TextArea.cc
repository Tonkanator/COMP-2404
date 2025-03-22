#include "TextArea.h"
#include <iostream>
#include <string>

TextArea::TextArea(): dimensions{0, 0, 0, 0}, id("N/A"), text("N/A"), fill(RGB(0,0,0)), border(RGB(0,0,0)){}
TextArea::TextArea(int x, int y, int width, int height, std::string id, std::string label): dimensions{x, y, width, height}, id(id), text(label), fill(RGB(0,0,0)), border(RGB(0,0,0)){}
TextArea::TextArea(Rectangle rect, std::string id, std::string label): dimensions(rect), id(id), text(label), fill(RGB(0,0,0)), border(RGB(0,0,0)){}
TextArea::TextArea(int x, int y, int width, int height, std::string id, std::string label, RGB fill, RGB border): dimensions{x, y, width, height}, id(id), text(label), fill(fill), border(border){}
TextArea::TextArea(Rectangle rectangle, std::string id, std::string label, RGB fill, RGB border): dimensions(rectangle), id(id), text(label), fill(fill), border(border){}

TextArea::TextArea(const TextArea& ta){
    dimensions = ta.dimensions;
    id = ta.id;
    text = "DUPLICATE";
    fill = ta.fill;
    border = ta.border;
}

void TextArea::draw(Display *display, Window win, GC gc, int x, int y) {
    // Set colors
    XSetForeground(display, gc, border.getColour());

    // Draw rectangle border
    XDrawRectangle(display, win, gc, x, y, dimensions.width, dimensions.height);

    // Fill the rectangle
    XSetForeground(display, gc, fill.getColour());
    XFillRectangle(display, win, gc, x + 1, y + 1, dimensions.width - 2, dimensions.height - 2);

    // Set text color (using black as default)
    XSetForeground(display, gc, 0x000000);
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