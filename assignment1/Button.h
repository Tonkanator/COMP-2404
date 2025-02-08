#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include "RGB.h"
#include <X11/Xlib.h>

class Button{
    private:
        int x, y, width, height;
        std::string label;
        RGB fill, border;
    public:
        Button(int x, int y, int width, int height, std::string label, RGB fill, RGB border);
        Button(int x, int y, int width, int height, std::string label, CuColour fill, CuColour border);
        Button();
        void draw(Display *display, Window win, GC gc, int parentX, int parentY);
        bool overlaps(Button& b);
        void print();
        int getX();
        int getY();
        int getWidth();
        int getHeight();
        std::string getLabel();
};

#endif