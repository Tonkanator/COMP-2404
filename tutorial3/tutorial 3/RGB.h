#ifndef RGB_H
#define RGB_H

#include "defs.h"

class RGB {
    private:
        int r, g, b;
    public:
        RGB(int red, int green, int blue);
        RGB(CuColour colour);
        RGB();
        int getR();
        int getG();
        int getB();
        CuColour getColour();
        void setR(int r);
        void setB(int b);
        void setG(int g);
        void setColour(CuColour colour);
};

#endif