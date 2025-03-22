#include "CuWindow.h"
#include <unistd.h>
#include <iostream>

CuWindow::CuWindow(const std::string& name, int width, int height, RGB background): name(name), width(width), height(height), background(background){
    display = XOpenDisplay(NULL);
    window = XCreateSimpleWindow(display, RootWindow(display, 0), 0, 0, width, height, 1, RGB::WHITE().getColour(), background.getColour());
    XStoreName(display, window, name.c_str());
    gc = XCreateGC(display, window, 0, NULL);
    XMapWindow(display, window);
    XFlush(display);
}

CuWindow::~CuWindow(){
    for (int i=0; i<panels.getSize(); i++)
    {
        delete panels.get(i);
    }

    XFreeGC(display, gc);
    XUnmapWindow(display, window);
    XDestroyWindow(display, window);
    XCloseDisplay(display);
}

bool CuWindow::addPanel(FlowPanel* panel) {

    if (panel->getDimensions().x + panel->getDimensions().width > width ||
        panel->getDimensions().y + panel->getDimensions().height > height) {
        return false;
    }

    for (int i = 0; i < panels.getSize(); ++i) {
        if (panels.get(i)->overlaps(*panel)) {
            return false;
        }
    }
    return panels.add(panel);
}

FlowPanel* CuWindow::removePanel(const std::string& id){
    return panels.remove(id);
}

FlowPanel* CuWindow::getPanel(const std::string& id) const{
    return panels.get(id);
}

void CuWindow::draw() const{
    usleep(100000);
    XSetForeground(display, gc, background.getColour());
    XFillRectangle(display, window, gc, 0, 0, width, height);

    for (int i = 0; i < panels.getSize(); ++i) {
        FlowPanel* panel = panels.get(i);
        if (panel) {
            panel->draw(display, window, gc);
        }
    }

    XFlush(display);
}

void CuWindow::printPanels() const{
    for (int i=0; i<panels.getSize(); i++){
        panels.get(i)->print();
    }
}

void CuWindow::printPanelTextAreas() const{
    for (int i=0; i<panels.getSize(); i++){
        panels.get(i)->printTextAreas();
    }
}

int CuWindow::getWidth() const{
    return width;
}

int CuWindow::getHeight() const{
    return height;
}