#include "Character.h"
#include "battle.h"

using namespace std;

int main(){
    string fighterName;
    int fighterMaxHealth, fighterDamage;

    cout << "Enter the fighter name, max health, and damage. "<< endl;
    cin >> fighterName >> fighterMaxHealth >> fighterDamage;

    Character fighter = Character(fighterName, fighterMaxHealth, fighterDamage);

    string orcName;
    int orcMaxHealth, orcDamage;

    cout << "Enter the orc name, max health, and damage. "<< endl;
    cin >> orcName >> orcMaxHealth >> orcDamage;

    Character orc = Character(orcName, orcMaxHealth, orcDamage);

    fighter.print();
    orc.print();

    Gondor::fight(fighter, orc);

    fighter.print();
    orc.print();

    Mordor::fight(fighter, orc);

    fighter.print();
    orc.print();

    return 0;
}