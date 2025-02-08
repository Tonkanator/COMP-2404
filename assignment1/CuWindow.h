#ifndef CUWINDOW_H
#define CUWINDOW_H

#include "defs.h"
#include <string>
#include "Panel.h"
#include <X11/Xlib.h>

class CuWindow{
    private:
        int width, height, numPanels = 0;
        std::string name;
        Panel panels[MAX_COMPONENTS];
        RGB backgroundColor;
        Display* display;
        Window window;
        GC gc;
    public:
        CuWindow(std::string name, int width, int height, RGB background);
        CuWindow(std::string name, int width, int height, CuColour background);
        bool addPanel(Panel& panel);
        bool removePanel(std::string id);
        Panel* getPanel(std::string id);
        void draw();
        void print();
        void printPanels();
        void printPanelButtons();
        ~CuWindow();
};

#endif