#include "battle.h"

using namespace std;

namespace Gondor {
    void fight(Character& fighter, Character& orc){
        int fDamage = fighter.strike() + 1;
        int oDamage = orc.strike() - 1;

        orc.takeDamage(fDamage);
        fighter.takeDamage(oDamage);

        cout << fighter.getName() << " hits " << orc.getName() << " for " << fDamage << " damage!"<< endl;
        cout << orc.getName() << " hits " << fighter.getName() << " for " << oDamage << " damage!"<< endl;
    }
}

namespace Mordor {
    void fight(Character& fighter, Character& orc){
        int fDamage = fighter.strike() - 1;
        int oDamage = orc.strike() + 1;

        orc.takeDamage(fDamage);
        fighter.takeDamage(oDamage);


        cout << fighter.getName() << " hits " << orc.getName() << " for " << fDamage << " damage!"<< endl;
        cout << orc.getName() << " hits " << fighter.getName() << " for " << oDamage << " damage!"<< endl;
    }
}