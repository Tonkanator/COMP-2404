#ifndef DEFS_H
#define DEFS_H
#include <iostream>

using namespace std;

#define MAX_COMPONENTS 256

#define MAX_ARRAY 3

#define CuColour unsigned long


struct Rectangle{
    int x;
    int y;
    int width;
    int height;
    bool overlaps(const Rectangle& rect) const{
        if (x < rect.x + rect.width && x + width > rect.x && y < rect.y + rect.height && y + height > rect.y){
            return true;
        }
        if (rect.x < x + width && rect.x + rect.width > x && rect.y < y + height && rect.y + rect.height > y){
            return true;
        }
        return false;
    }
};



#endif