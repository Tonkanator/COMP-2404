#include "AbsolutePanel.h"
#include <iostream>
#include <vector>
#include "RGB.h"

AbsolutePanel::AbsolutePanel(const Rectangle& dimensions, const std::string& id): Panel(dimensions, id) {}

AbsolutePanel::AbsolutePanel(int x, int y, int width, int height, const std::string& id): Panel(x, y, width, height, id) {}

void AbsolutePanel::print() const {
    std::cout << "Absolute layout" << std::endl;
    std::cout << "AbsolutePanel id:     " << id << std::endl;
    std::cout << "Preferred dimensions: " << dimensions.x << ", " << dimensions.y << "," << dimensions.width << ", " << dimensions.height << std::endl;
    std::cout << "Contained components:     " << getSize() << std::endl;
}

void AbsolutePanel::draw(Display *display, Window win, GC gc, const Rectangle& box){
    XSetForeground(display, gc, RGB::WHITE().getColour());
    XDrawRectangle(display, win, gc, box.x, box.y, box.width, box.height);

    // Track which components have been drawn
    std::vector<Component*> drawnComponents;

    // Attempt to draw each component
    for (int i = 0; i < getSize(); i++) {
        Component* component = get(i);
        Rectangle preferredRect = component->getPreferredRectangle();

        // Check if the component fits within the panel's bounds
        bool fitsInPanel = (preferredRect.x >= dimensions.x &&
                            preferredRect.y >= dimensions.y &&
                            preferredRect.x + preferredRect.width <= dimensions.x + dimensions.width &&
                            preferredRect.y + preferredRect.height <= dimensions.y + dimensions.height);

        if (!fitsInPanel) {
            // Skip this component if it doesn't fit within the panel's bounds
            continue;
        }

        // Check if the component overlaps with any previously drawn component
        bool overlaps = false;
        for (Component* drawnComponent : drawnComponents) {
            if (preferredRect.overlaps(drawnComponent->getPreferredRectangle())) {
                overlaps = true;
                break;
            }
        }

        // If the component does not overlap and fits within the panel, draw it
        if (!overlaps) {
            component->draw(display, win, gc, preferredRect);
            drawnComponents.push_back(component);
        }
    }
}