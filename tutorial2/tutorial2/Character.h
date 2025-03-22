#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>
using namespace std;

class Character {
    private:
        string name;
        int maxHealth, currentHealth, damage;
    public:
        Character();
        Character(const string &n, int maxHealth, int damage);
        string getName();
        void takeDamage(int damage);
        int strike();
        void print();
};

#endif