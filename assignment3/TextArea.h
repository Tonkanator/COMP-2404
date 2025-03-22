#ifndef TEXTAREA_H
#define TEXTAREA_H

#include "Component.h"
#include "RGB.h"

class TextArea: public Component {
    private:
        std::string text;
        RGB border;
        RGB fill;
    public:
        TextArea(const Rectangle& rect, const std::string& id, const std::string& label);
        TextArea(int x, int y, int width, int height, const std::string& id, const std::string& label);
        void print() const override;
        void draw(Display *display, Window win, GC gc, const Rectangle& box) override;
        void setText(const std::string& newText);
};

#endif