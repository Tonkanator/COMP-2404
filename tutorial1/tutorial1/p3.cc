#include<iostream>
#include "power.h"

using namespace std;

int main(){
    int a, b, c;
    cout <<"Please enter two integers: ";
    cin >> a >> b;
    power(a, b, c);
    cout << a << " to the power " << b << " is " << c << "!";
}