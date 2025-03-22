#ifndef PANELARRAY_H
#define PANELARRAY_H

#include "defs.h"
#include "FlowPanel.h"

class PanelArray
{
private:
    FlowPanel **panels;
    int numFP;

public:
    PanelArray();
    ~PanelArray();
    bool add(FlowPanel *panel);
    FlowPanel *remove(const std::string &id);
    int getSize() const;
    FlowPanel *get(int index) const;
    FlowPanel *get(const std::string &id) const;
};

#endif