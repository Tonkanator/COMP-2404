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
        TextArea(Rectangle rect, const std::string& id, const std::string& label);
        TextArea(int x, int y, int width, int height, const std::string& id, const std::string& label);
        TextArea(int x, int y, int width, int height, const std::string& id, const std::string& label, RGB fill, RGB border);
        TextArea(Rectangle rectangle, const std::string& id, const std::string& label, RGB fill, RGB border);
        void draw(Display *display, Window win, GC gc, int x, int y);
        bool overlaps(const TextArea& ta) const;
        void print() const;
        void setBorder(RGB colour);
        void setFill(RGB colour);
        std::string getID() const;
        Rectangle getDimensions() const;
        void setText(const std::string& text);
        void setHeight(int height);
};

#endif