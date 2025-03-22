#ifndef ABSOLUTEPANEL_H
#define ABSOLUTEPANEL_H

#include "Panel.h"

class AbsolutePanel: public Panel {
    public:
        AbsolutePanel(Rectangle dimensions, const std::string& id);
        AbsolutePanel(int x, int y, int width, int height, const std::string& id);
        void print() const override;
        void draw(Display *display, Window win, GC gc, const Rectangle& box) override;
};

#endif