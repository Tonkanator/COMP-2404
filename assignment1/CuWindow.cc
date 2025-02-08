#include "CuWindow.h"
#include <iostream>
#include <unistd.h>

CuWindow::CuWindow(std::string name, int width, int height, RGB background){
    this->name = name;
    this->width = width;
    this->height = height;
    this->backgroundColor = background;

    display = XOpenDisplay(NULL);
    window = XCreateSimpleWindow(display, RootWindow(display, 0), 0, 0, width, height, 1, CuBlack, backgroundColor.getColour());
    XStoreName(display, window, name.c_str());
    gc = XCreateGC(display, window, 0, NULL);
    XMapWindow(display, window);
    XFlush(display);
}
CuWindow::CuWindow(std::string name, int width, int height, CuColour background)
    : CuWindow(name, width, height, RGB(background)) {}

bool CuWindow::addPanel(Panel &panel){
    if (numPanels >= MAX_COMPONENTS){
        return false;
    }

    for (int i=0; i<numPanels; i++){
        if (panels[i].overlaps(panel)){
            return false;
        }
    }

    if (panel.getX() + panel.getWidth() > width || panel.getY() + panel.getHeight() > height)
    {
        return false;
    }

    panels[numPanels++] = panel;

    return true;
}

bool CuWindow::removePanel(std::string id) {
    for (int i = 0; i < numPanels; i++) {
        if (panels[i].getID() == id) {
            // Shift the panels to the left
            for (int j = i; j < numPanels - 1; j++) {
                panels[j] = panels[j + 1];
            }
            numPanels--;
            return true;
        }
    }
    return false;
}

Panel* CuWindow::getPanel(std::string id){
    for (int i=0; i<numPanels; i++){
        if (panels[i].getID() == id){
            return &panels[i];
        }
    }

    return nullptr;
}

void CuWindow::draw(){
    usleep(100000);
    XSetForeground(display, gc, backgroundColor.getColour());
    XFillRectangle(display, window, gc, 0, 0, width, height);

    for (int i=0; i<numPanels; i++){
        panels[i].draw(display, window, gc);
    }

    XFlush(display);
}

void CuWindow::print(){
    std::cout << "CuWindow:     " << name << std::endl;
    std::cout << "Panel Count:  " << numPanels << std::endl;
}

void CuWindow::printPanels(){
    for (int i=0; i<numPanels; i++){
        panels[i].print();
    }
}
void CuWindow::printPanelButtons(){
    for (int i=0; i<numPanels; i++){
        panels[i].printButtons();
    }
}
CuWindow::~CuWindow(){
    XFreeGC(display, gc);
    XUnmapWindow(display, window);
    XDestroyWindow(display, window);
    XCloseDisplay(display);   
}