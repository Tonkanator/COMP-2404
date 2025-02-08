#ifndef PANEL_H
#define PANEL_H

#include <string>
#include "defs.h"
#include "Button.h"

class Panel{
    private:
        int x, y, width, height, numButtons = 0;
        std::string id;
        Button buttons[MAX_COMPONENTS];
    public:
        Panel(int x, int y, int width, int height, std::string id);
        Panel();
        bool addButton(Button& newButton);
        bool removeButton(std::string id);
        void draw(Display *display, Window win, GC gc);
        bool overlaps(Panel& p);
        void print();
        int getX();
        int getY();
        int getWidth();
        int getHeight();
        std::string getID();
        void printButtons();
};
#endif