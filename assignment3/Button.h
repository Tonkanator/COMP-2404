#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include "defs.h"
#include "Component.h"
#include "RGB.h"

class Button: public Component {
    private:
        std::string label;
        RGB border;
        RGB fill;
    public:
        Button(const Rectangle& rect, const std::string& id, const std::string& label);
        Button(const Rectangle& rect, const std::string& id, const std::string& label, RGB border, RGB fill);
        Button(int x, int y, int width, int height, const std::string& id, const std::string& label, RGB border, RGB fill);
        void print() const override;
        void draw(Display *display, Window win, GC gc, const Rectangle& box) override;
        void setHeight(int newHeight);
};

#endif