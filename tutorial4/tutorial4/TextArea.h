#ifndef TEXTAREA_H
#define TEXTAREA_H
#include "defs.h"
#include "RGB.h"
#include <X11/Xlib.h>
#include <string>

class TextArea {
    private:
        Rectangle dimensions;
        std::string text;
        std::string id;
        RGB fill, border;
    public:
        TextArea();
        TextArea(Rectangle rect, std::string id, std::string label);
        TextArea(int x, int y, int width, int height, std::string id, std::string label);
        TextArea(int x, int y, int width, int height, std::string id, std::string label, RGB fill, RGB border);
        TextArea(Rectangle rectangle, std::string id, std::string label, RGB fill, RGB border);
        TextArea(const TextArea& ta);
        void draw(Display *display, Window win, GC gc, int x, int y);
        bool overlaps(const TextArea& ta) const;
        void print() const;
        void setBorder(RGB colour);
        void setFill(RGB colour);
};

#endif