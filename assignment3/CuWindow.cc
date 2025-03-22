#include "CuWindow.h"
#include <unistd.h>
#include <iostream>

CuWindow::CuWindow(const std::string& name, int width, int height, const RGB& background): name(name), width(width), height(height), background(background) {
    root = new AbsolutePanel(0, 0, width, height, "root");
    
    display = XOpenDisplay(NULL);
    window = XCreateSimpleWindow(display,  RootWindow(display, 0), 0, 0, width, height, 0, 0x000000, background.getColour());
    XStoreName(display, window, name.c_str());
    gc = XCreateGC(display, window, 0, NULL);
    XMapWindow(display, window);
    XFlush(display);
}

CuWindow::~CuWindow() {
    XFreeGC(display, gc);
    XDestroyWindow(display, window);
    XCloseDisplay(display);
    
    delete root;
}

bool CuWindow::add(Component* comp) {
    return root->add(comp);
}
Component* CuWindow::remove(const std::string& id) {
    return root->remove(id);
}

Component* CuWindow::get(const std::string& id) const {
    return root->get(id);
}

void CuWindow::draw() {
    usleep(100000);

    XSetForeground(display, gc, background.getColour());
    XFillRectangle(display, window, gc, 0, 0, width, height);

    root->draw(display, window, gc, root->getPreferredRectangle());

    XFlush(display);
}

void CuWindow::print() const {
    std::cout << "Name:       " << name << std::endl;
    std::cout << "Components: " << root->getSize() << std::endl;
}

void CuWindow::printComponents() const {
    root->printComponents();
}