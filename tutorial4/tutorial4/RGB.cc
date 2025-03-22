#include "RGB.h"
#include <iostream>

RGB::RGB(int red, int green, int blue){
    setR(red);
    setG(green);
    setB(blue);
}

RGB::RGB(){
    setR(0);
    setG(0);
    setB(0);
}

RGB::RGB(CuColour colour){
    setColour(colour);
}

int RGB::getR() const{
    return r;
}

int RGB::getG() const{
    return g;
}

int RGB::getB() const{
    return b;
}

CuColour RGB::getColour() const{
    return (r << 16) | (g << 8) | b;
}

void RGB::setR(int r){
    if (r < 0){
        this->r = 0;
    }
    else if (r > 255){
        this->r = 255;
    }
    else{
        this->r = r;
    }
}

void RGB::setB(int b){
    if (b < 0){
        this->b = 0;
    }
    else if (b > 255){
        this->b = 255;
    }
    else{
        this->b = b;
    }
}

void RGB::setG(int g){
    if (g < 0){
        this->g = 0;
    }
    else if (g > 255){
        this->g = 255;
    }
    else{
        this->g = g;
    }
}

void RGB::setColour(CuColour colour){
    setR((colour >> 16) & 0xFF);
    setG((colour >> 8) & 0xFF);
    setB(colour & 0xFF);
}

void RGB::print() const{
    std::cout << "Red:   " << r << std::endl;
    std::cout << "Green: " << g << std::endl;
    std::cout << "Blue:  " << b << std::endl;
}

RGB RGB::WHITE(){
    return RGB(255, 255, 255);
}

RGB RGB::BLACK(){
    return RGB(0, 0, 0);
}

RGB RGB::RED(){
    return RGB(255, 0, 0);
}

RGB RGB::GREEN(){
    return RGB(0, 255, 0);
}

RGB RGB::BLUE(){
    return RGB(0, 0, 255);
}