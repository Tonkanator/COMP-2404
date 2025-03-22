#include "PanelArray.h"

PanelArray::PanelArray(): numFP(0) {
    panels = new FlowPanel*[MAX_COMPONENTS];
}

PanelArray::~PanelArray() {
    delete [] panels;
}

bool PanelArray::add(FlowPanel* panel){
    if (numFP >= MAX_COMPONENTS){
        return false;
    }

    if (panel->getDimensions().x < 0 || panel->getDimensions().y < 0) {
        return false;
    }

    for (int i=0; i<numFP; i++) {
        if (panels[i]->overlaps(*panel)) {
            return false;
        }
    }

    panels[numFP] = panel;
    numFP++;
    return true;
}

FlowPanel* PanelArray::remove(const std::string& id) {
    FlowPanel* temp;

    for (int i=0; i<numFP; i++){
        if (panels[i]->getID() == id){
            temp = panels[i];

            for (int j=i; j<numFP-1; j++){
                panels[j] = panels[j+1];
            }

            numFP--;
            return temp;
        }
    }

    return nullptr;
}

int PanelArray::getSize() const{
    return numFP;
}

FlowPanel* PanelArray::get(int index) const {
    if (index < 0 || index >= numFP) return nullptr;
    return panels[index];
}

FlowPanel* PanelArray::get(const std::string& id) const{
    for (int i=0; i<numFP; i++){
        if (panels[i]->getID() == id){
            return panels[i];
        }
    }
    return nullptr;
}