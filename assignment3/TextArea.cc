#include "TextArea.h"
#include <iostream>
#include <sstream>
#include <vector>

TextArea::TextArea(const Rectangle& rect, const std::string& id, const std::string& label): Component(rect, id), text(label), border(RGB::BLACK()), fill(RGB::WHITE()) {}

TextArea::TextArea(int x, int y, int width, int height, const std::string& id, const std::string& label): Component(x, y, width, height, id), text(label), border(RGB::BLACK()), fill(RGB::WHITE()) {}

void TextArea::print() const {
    std::cout << "ID:             " << id << std::endl;
    std::cout << "Preferred size: " << dimensions.width << ", " << dimensions.height << std::endl;
    std::cout << "Text:          " << text << std::endl;
}

void TextArea::draw(Display *display, Window win, GC gc, const Rectangle& box) {
    // Fill the background with the specified fill color
    XSetForeground(display, gc, fill.getColour());
    XFillRectangle(display, win, gc, box.x, box.y, box.width, box.height);

    // Draw the border around the text area
    XSetForeground(display, gc, border.getColour());
    XDrawRectangle(display, win, gc, box.x, box.y, box.width, box.height);

    // Set text color to black
    XSetForeground(display, gc, RGB::BLACK().getColour());

    // Load a font explicitly
    XFontStruct *font = XLoadQueryFont(display, "fixed");
    if (!font) {
        font = XLoadQueryFont(display, "9x15"); // Another common fallback
    }
    if (!font) {
        fprintf(stderr, "Error: Failed to load any font\n");
        return;  // Exit if no font is available
    }

    // Apply the font to the GC
    XSetFont(display, gc, font->fid);

    int lineHeight = font->ascent + font->descent;
    int maxLines = box.height / lineHeight;
    int y = box.y + lineHeight;

    std::istringstream stream(text);
    std::string word, line;
    std::vector<std::string> lines;

    // Breaks words or sentences into multiple lines
    while (stream >> word) {
        std::string newLine = line.empty() ? word : line + " " + word;
        int textWidth = XTextWidth(font, newLine.c_str(), newLine.length());

        if (textWidth > box.width - 10) { 
            if (!line.empty()) {  
                lines.push_back(line);
                line = word;  
            } else {  
                std::string brokenWord;
                for (char c : word) {
                    brokenWord += c;
                    if (XTextWidth(font, brokenWord.c_str(), brokenWord.length()) > box.width - 10) {
                        lines.push_back(brokenWord);
                        brokenWord.clear();
                    }
                }
                if (!brokenWord.empty()) line = brokenWord;
            }
        } else {
            line = newLine;
        }
    }

    if (!line.empty()) lines.push_back(line);

    for (int i = 0; i < std::min(maxLines, static_cast<int>(lines.size())); ++i) {
        XDrawString(display, win, gc, box.x + 5, y, lines[i].c_str(), lines[i].length());
        y += lineHeight;
    }

    // Free the manually loaded font
    XFreeFont(display, font);
}


void TextArea::setText(const std::string& newText) {
    text = newText;
}