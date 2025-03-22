#ifndef FLOWPANEL_H
#define FLOWPANEL_H

#include "Panel.h"

class FlowPanel: public Panel {
    public:
        FlowPanel(const Rectangle& dimensions, const std::string& id);
        FlowPanel(int x, int y, int width, int height, const std::string& id);
        void print() const override;
        void draw(Display *display, Window win, GC gc, const Rectangle& box) override;
};

#endif