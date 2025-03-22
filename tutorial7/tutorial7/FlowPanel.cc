#include "FlowPanel.h"

FlowPanel::FlowPanel(Rectangle dimensions, const std::string& id): Panel(dimensions, id) {}

FlowPanel::FlowPanel(int x, int y, int width, int height, const std::string& id): Panel(x, y, width, height, id) {}

void FlowPanel::print() const {
    std::cout << "FlowPanel layout" << std::endl;
    std::cout << "AbsolutePanel id:     " << id << std::endl;
    std::cout << "Preferred dimensions: " << dimensions.width << ", " << dimensions.height << std::endl;
    std::cout << "Contained components:     " << getSize() << std::endl;
}

void FlowPanel::draw(Display *display, Window win, GC gc, const Rectangle& box) {
    XDrawRectangle(display, window, gc, box.x, box.y, box.width, box.height);

    // Constants for gaps between components
    const int xgap = 10;
    const int ygap = 10;

    // Initial position for drawing components
    int x = box.x + xgap;
    int y = box.y + ygap;

    // Track the height of the current row
    int rowHeight = 0;

    // Attempt to draw each component
    for (int i = 0; i < getSize(); i++) {
        Component* component = get(i);
        Rectangle preferredRect = component->getPreferredRectangle();

        // Check if the component fits in the current row
        if (x + preferredRect.width > box.x + box.width) {
            // Move to the next row
            x = box.x + xgap;
            y += rowHeight + ygap;
            rowHeight = 0;
        }

        // Check if the component fits in the panel vertically
        if (y + preferredRect.height > box.y + box.height) {
            // Stop drawing if the component does not fit
            break;
        }

        // Draw the component at the current position
        component->draw(display, win, gc, Rectangle(x, y, preferredRect.width, preferredRect.height));

        // Update the current position and row height
        x += preferredRect.width + xgap;
        if (preferredRect.height > rowHeight) {
            rowHeight = preferredRect.height;
        }
    }
}