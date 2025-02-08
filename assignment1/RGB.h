#ifndef RGB_H
#define RGB_H

#include "defs.h"

class RGB{
    private:
        int r, g, b;
    public:
        RGB(int r, int g, int b);
        RGB(CuColour colour);
        RGB();
        CuColour getColour();
        void setColour(CuColour colour);
        void print();
        int getR();
        int getG();
        int getB();
        void setR(int r);
        void setG(int g);
        void setB(int b);
};

#endif