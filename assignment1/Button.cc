#include "Button.h"
#include <iostream>

Button::Button(int x, int y, int width, int height, std::string label, RGB fill, RGB border){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->label = label;
    this->fill = fill;
    this-> border = border;
}

Button::Button(int x, int y, int width, int height, std::string label, CuColour fill, CuColour border){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->label = label;
    this->fill = fill;
    this-> border = border;
}

Button::Button(){
    x = 0;
    y = 0;
    width = 0;
    height = 0;
    label = "NA";
    fill = RGB(255, 0, 127);
    border = RGB(255, 0, 127);
}

void Button::draw(Display *display, Window win, GC gc, int parentX, int parentY){
    int buttonX = x + parentX;
    int buttonY = y + parentY;

    XSetForeground(display, gc, fill.getColour());
    XFillRectangle(display, win, gc, buttonX, buttonY, width, height);

    XSetForeground(display, gc, border.getColour());
    XDrawRectangle(display, win, gc, buttonX, buttonY, width, height);

    XSetForeground(display, gc, CuWhite);
    
    XDrawString(display, win, gc, buttonX+(width - label.length()*6)/2, buttonY+height/2, label.c_str(), label.size());
}

bool Button::overlaps(Button& b){
    return !(x + width <= b.x || b.x + b.width <= x || y + height <= b.y || b.y + b.height <= y);
}

void Button::print(){
    std::cout << "Button:   " << label << std::endl;
    std::cout << "Position: " << x << ", " << y << std::endl;
    std::cout << "Size:     " << width << ", " << height << std::endl;
}

int Button::getX(){
    return x;
}

int Button::getY(){
    return y;
}

int Button::getWidth(){
    return width;
}

int Button::getHeight(){
    return height;
}

std::string Button::getLabel(){
    return label;
}