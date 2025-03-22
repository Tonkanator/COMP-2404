#ifndef FLOWPANEL_H
#define FLOWPANEL_H

#include "defs.h"
#include <string>
#include "TAArray.h"

class FlowPanel{
    private:
        std::string id;
        Rectangle dimensions;
        int xgap;
        int ygap;
        TAArray textAreas;
    public:
        FlowPanel(int x, int y, int width, int height, const std::string& id, int xgap=10, int ygap=10);
        FlowPanel(Rectangle& rectangle, const std::string& id, int xgap=10, int ygap=10);
        FlowPanel(const FlowPanel& panel);
        ~FlowPanel();
        bool addTextArea(TextArea* ta);
        bool addTextArea(TextArea* ta, int index);
        TextArea* getTextArea(const std::string& id) const;
        TextArea* getTextArea(int index) const;
        TextArea* removeTextArea(const std::string& id);
        TextArea* removeTextArea(int index);

        bool overlaps(FlowPanel& panel) const;
        void draw(Display *display, Window win, GC graphicsContext) const;
        void print() const;
        void printTextAreas() const;

        std::string getID() const;
        Rectangle getDimensions() const;
};

#endif