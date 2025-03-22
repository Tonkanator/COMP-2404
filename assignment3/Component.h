#ifndef COMPONENT_H
#define COMPONENT_H

#include "defs.h"
#include <string>
#include <X11/Xlib.h>

class Component{
    protected:
        Rectangle dimensions;
        std::string id;
    public:
        Component(const Rectangle& dimensions, const std::string& id);
        Component(int x, int y, int width, int height, const std::string& id);
        bool overlaps(Component& component) const;
        virtual void print() const;
        virtual void draw(Display *display, Window win, GC gc, const Rectangle& box) = 0;
        virtual ~Component() {}
        std::string getID() const;
        Rectangle getPreferredRectangle() const;
};

#endif