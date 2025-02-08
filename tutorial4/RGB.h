#ifndef RGB_H
#define RGB_H

#include "defs.h"

class RGB
{
private:
    int r, g, b;

public:
    RGB(int r, int g, int b);
    RGB(CuColour colour);
    RGB();
    CuColour getColour() const;
    void setColour(CuColour colour);
    void print() const;
    int getR() const;
    int getG() const;
    int getB() const;
    void setR(int r);
    void setG(int g);
    void setB(int b);

    static RGB WHITE();
    static RGB BLACK();
    static RGB RED();
    static RGB GREEN();
    static RGB BLUE();
};

#endif