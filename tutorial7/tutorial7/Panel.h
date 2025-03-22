#ifndef PANEL_H
#define PANEL_H

#include "defs.h"
#include "Component.h"
#include "ComponentList.h"

class Panel: public Component, public ComponentList {
    public:
        Panel(Rectangle dimensions, const std::string& id);
        Panel(int x, int y, int width, int height, const std::string& id);
        virtual void draw(Display *display, Window win, GC gc, const Rectangle& box) = 0;
        void print() const override;
        void printComponents() const;
};

#endif