#include "Character.h"

using namespace std;

Character::Character(){
    name = "NA";
    maxHealth = 0;
    currentHealth = 0;
    damage = 0;
}

Character::Character(const string& name, int maxHealth, int damage){
            this->name = name;
            this->maxHealth = maxHealth;
            this->currentHealth = maxHealth;
            this->damage = damage;
        }
        
string Character::getName(){
    return name;
}

void Character::takeDamage(int damage){
    currentHealth -= damage;

    if (currentHealth < 0){
        currentHealth = 0;
    }
}

int Character::strike(){
    return damage;
}

void Character::print(){
    cout << "Name: " << name << endl; 
    cout << "Health: " << currentHealth << endl;
}