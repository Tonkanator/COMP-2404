#ifndef CUWINDOW_H
#define CUWINDOW_H

#include "defs.h"
#include <string>
#include "PanelArray.h"
#include "RGB.h"
#include <X11/Xlib.h>
#include "FlowPanel.h"

class CuWindow{
    private:
        int width;
        int height;
        std::string name;
        PanelArray panels;
        RGB background;
        Display* display;
        Window window;
        GC gc;
    public:
        CuWindow(const std::string& name, int width, int height, RGB background);
        ~CuWindow();
        bool addPanel(FlowPanel* fp);
        FlowPanel* removePanel(const std::string& id);
        FlowPanel* getPanel(const std::string& id) const;
        void draw() const;
        void printPanels() const;
        void printPanelTextAreas() const;
        int getWidth() const;
        int getHeight() const;
};

#endif