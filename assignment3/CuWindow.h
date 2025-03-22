#ifndef CUWINDOW_H
#define CUWINDOW_H

#include "defs.h"
#include "AbsolutePanel.h"
#include "RGB.h"
#include <X11/Xlib.h>
#include <string>

class CuWindow {
    private:
        int width;
        int height;
        std::string name;
        Panel* root;
        RGB background;
        Display* display;
        Window window;
        GC gc;
    public:
        CuWindow(const std::string& name, int width, int height, const RGB& background);
        ~CuWindow();
        bool add(Component* comp);
        Component* remove(const std::string& id);
        Component* get(const std::string& id) const;
        void draw();
        void print() const;
        void printComponents() const;
};

#endif