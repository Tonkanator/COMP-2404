#include <iostream>
#include <string>
#include <sstream>

#include "defs.h"
#include "RGB.h"

using namespace std;

int constructorTests();
int setterTests();

int main(){
    int choice = 0;
    cout<<"0. Constructor tests"<<endl;
    cout<<"1. Setter tests"<<endl;
    cin >> choice;
    switch (choice)
    {
    case 0:
        return constructorTests();
    case 1:
        return setterTests();
    }
    return 0;
}


int constructorTests()
{
    RGB rgb1(10, 210, 33);

    int score = 0;

    if (rgb1.getR() == 10 && rgb1.getG() == 210 && rgb1.getB() == 33)
    {
        cout<< "Red, Green, Blue getter values are correct"<<endl;
        cout << "Constructor test 1 passed" << endl;
        score ++;
    }
    else
    {
        cout<< "Red, Green, Blue getter values are NOT correct"<<endl;
        cout << "Constructor test 1 failed" << endl;
    }

    if (rgb1.getColour() == 0x0AD221)
    {
        cout<< "CuColour getter value is correct"<<endl;
        cout << "Constructor test 2 passed" << endl;
        score ++;
    }
    else
    {
        cout<< "CuColour getter value is NOT correct"<<endl;
        cout << "Constructor test 2 failed" << endl;
    }

    RGB rgb2(0x1A023F);

    if (rgb2.getR() == 0x1A && rgb2.getG() == 0x02 && rgb2.getB() == 0x3F)
    {
        cout<< "Red, Green, Blue getter values are correct"<<endl;
        cout << "Constructor test 3 passed" << endl;
        score ++;
    }
    else
    {
        cout<< "Red, Green, Blue getter values are NOT correct"<<endl;
        cout << "Constructor test 3 failed" << endl;
    }

    if (rgb2.getColour() == 0x1A023F)
    {
        cout<< "CuColour getter value is correct"<<endl;
        cout << "Constructor test 4 passed" << endl;
        score ++;
    }
    else
    {
        cout<< "CuColour getter value is NOT correct"<<endl;
        cout << "Constructor test 4 failed" << endl;
    }

    cout<<"All constructor tests complete. Your score is "<<score<<"/4"<<endl;
    
    return 0;
}

int setterTests()
{
    RGB rgb1(10, 210, 33);

    rgb1.setR(0x1A);

    int score = 0;

    if (rgb1.getR() == 0x1A)
    {
        cout<< "Red setter value is correct"<<endl;
        cout << "Setter test 1 passed" << endl;
        score++;
    }
    else
    {
        cout<< "Red setter value is NOT correct"<<endl;
        cout << "Setter test 1 failed" << endl;
    }

    if (rgb1.getColour() == 0x1AD221)
    {
        cout<< "CuColour getter value is correct"<<endl;
        cout << "Setter test 2 passed" << endl;
        score++;
    }
    else
    {
        cout<< "CuColour getter value is NOT correct"<<endl;
        cout << "Setter test 2 failed" << endl;
    }

    rgb1.setG(0x02);

    if (rgb1.getG() == 0x02)
    {
        cout<< "Green setter value is correct"<<endl;
        cout << "Setter test 3 passed" << endl;
        score++;
    }
    else
    {
        cout<< "Green setter value is NOT correct"<<endl;
        cout << "Setter test 3 failed" << endl;
    }

    if (rgb1.getColour() == 0x1A0221)
    {
        cout<< "CuColour getter value is correct"<<endl;
        cout << "Setter test 4 passed" << endl;
        score++;
    }
    else
    {
        cout<< "CuColour getter value is NOT correct"<<endl;
        cout << "Setter test 4 failed" << endl;
    }

    rgb1.setB(0x3F);

    if (rgb1.getB() == 0x3F)
    {
        cout<< "Blue setter value is correct"<<endl;
        cout << "Setter test 5 passed" << endl;
        score++;
    }
    else
    {
        cout<< "Blue setter value is NOT correct"<<endl;
        cout << "Setter test 5 failed" << endl;
    }

    if (rgb1.getColour() == 0x1A023F)
    {
        cout<< "CuColour getter value is correct"<<endl;
        cout << "Setter test 6 passed" << endl;
        score++;
    }
    else
    {
        cout<< "CuColour getter value is NOT correct"<<endl;
        cout << "Setter test 6 failed" << endl;
    }

    rgb1.setColour(0x0A0A0A);

    if (rgb1.getR() == 0x0A && rgb1.getG() == 0x0A && rgb1.getB() == 0x0A)
    {
        cout<< "Red, Green, Blue getter values are correct after setting CuColour"<<endl;
        cout << "Setter test 7 passed" << endl;
        score++;
    }
    else
    {
        cout<< "Red, Green, Blue getter values are NOT correct after setting CuColour"<<endl;
        cout << "Setter test 7 failed" << endl;
    }

    cout<<"All setter tests complete. Your score is "<<score<<"/7"<<endl;
   
    return 0;
}