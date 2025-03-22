#include "Button.h"
#include <iostream>

Button::Button(const Rectangle& rect, const std::string& id, const std::string& label): Component(rect, id), label(label), border(RGB::BLACK()), fill(RGB::WHITE()) {}

Button::Button(const Rectangle& rect, const std::string& id, const std::string& label, RGB border, RGB fill): Component(rect, id), label(label), border(border), fill(fill) {}

Button::Button(int x, int y, int width, int height, const std::string& id, const std::string& label, RGB border, RGB fill): Component(x, y, width, height, id), label(label), border(border), fill(fill) {}

void Button::print() const {
    std::cout << "Label:          " << label << std::endl;
    std::cout << "ID:             " << id << std::endl;
    std::cout << "Preferred size: " << dimensions.width << ", " << dimensions.height << std::endl;
}

void Button::draw(Display *display, Window win, GC gc, const Rectangle& box) {
    XSetForeground(display, gc, fill.getColour());
    XFillRectangle(display, win, gc, box.x, box.y, box.width, box.height);

    XSetForeground(display, gc, border.getColour());
    XDrawRectangle(display, win, gc, box.x, box.y, box.width, box.height);

    XSetForeground(display, gc, RGB::BLACK().getColour());
    XDrawString(display, win, gc, box.x+(box.width - label.length()*6)/2, box.y+box.height/2, label.c_str(), label.size());
}

void Button::setHeight(int newHeight) {
    dimensions.height = newHeight;
}