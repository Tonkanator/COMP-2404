#include "Panel.h"
#include <iostream>

Panel::Panel(int x, int y, int width, int height, std::string id){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->id = id;
    numButtons = 0;
}

Panel::Panel(){
    x = 0;
    y = 0;
    width = 0;
    height = 0;
    numButtons = 0;
    id = "N/A";
}

bool Panel::addButton(Button& newButton){
    if (numButtons >= MAX_COMPONENTS){
        return false;
    }

    //loop through the button array to check if any buttons overlap with the new one
    for (int i=0; i<numButtons; ++i){
        if (buttons[i].overlaps(newButton)){
            return false;
        }
    }

    if (newButton.getX() + newButton.getWidth() > width || newButton.getY() + newButton.getHeight() > height){
        return false;
    }

    buttons[numButtons++] = newButton;

    return true;
}

bool Panel::removeButton(std::string id){
    for (int i=0; i<numButtons; i++){
        if (buttons[i].getLabel() == id){
            //shift buttons left which will remove the button and close the gap
            for (int j=i; j<numButtons; j++){
                buttons[j] = buttons[j+1];
            }
            numButtons--;
            return true;
        }
    }
    return false;
}

void Panel::draw(Display *display, Window win, GC gc){
    if (width == 0 || height == 0){
        return;
    }

    XSetForeground(display, gc, CuBlack);
    XDrawRectangle(display, win, gc, x, y, width, height);

    for (int i=0; i<numButtons; i++)
    {
        buttons[i].draw(display, win, gc, x, y);
    }
}

bool Panel::overlaps(Panel &p){
    return !(x + width <= p.x || p.x + p.width <= x || y + height <= p.y || p.y + p.height <= y);
}

void Panel::print(){
    std::cout << "Panel:    " << id << std::endl;
    std::cout << "Position: " << x << ", " << y << std::endl;
    std::cout << "Size:     " << width << ", " << height << std::endl;

    for (int i=0; i<numButtons; i++){
        buttons[i].print();
    }
}

int Panel::getX(){
    return x;
}

int Panel::getY(){
    return y;
}

int Panel::getWidth(){
    return width;
}

int Panel::getHeight(){
    return height;
}

std::string Panel::getID(){
    return id;
}

void Panel::printButtons(){
    for (int i=0; i<numButtons; i++){
        buttons[i].print();
    }
}