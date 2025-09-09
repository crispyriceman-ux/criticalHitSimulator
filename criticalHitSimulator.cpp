#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand (time(0));
    int criticalHitChance = 10; // 10% chance for a critical hit
    int roll = rand() % 100 + 1; // Roll a number between 1 and 100

    cout << "Choose an attack!" << endl;
    cout << "1: Sword Slash! " << "2: Fireball!" << endl;
    cout << "3: Arrow Shot! " << "4: Thunderbolt!" << endl;
    int choice;
    cin >> choice;

    string attackName;
    int baseDamage = 0;
    int accuracy = 0; 
    bool criticalAttack = false;
    bool normalAttack = false;

        switch (choice) {
            case 1: attackName = "Sword Slash"; baseDamage = 10; accuracy = 90; break;
            case 2: attackName = "Fireball";  baseDamage = 12; accuracy = 75; break;
            case 3: attackName = "Arrow Shot"; baseDamage = 8; accuracy = 95; break;
            case 4: attackName = "Thunderbolt"; baseDamage = 15; accuracy = 70; break;
        }
       if (attackName.empty()) {
           cout << "Invalid choice!" << endl;
           switch (rand() % 4 + 1) { // lowkey cheat to avoid empty attackName
               case 1: attackName = "Sword Slash"; baseDamage = 10; break;
               case 2: attackName = "Fireball";  baseDamage = 12; break;
               case 3: attackName = "Arrow Shot"; baseDamage = 8; break;
               case 4: attackName = "Thunderbolt"; baseDamage = 15; break;
           }
           cout << "You randomly perform " << attackName << "!" << endl;
         } else {
           cout << "You chose " << attackName << "!" << endl;
       }
       if (rand() % 100 + 1 > accuracy) {
           cout << "But it missed!" << endl;
           return 0;
       }
    // Result messages
    string resultsCrit[] = {
        "The enemy staggers back in pain!",
        "It’s super effective!",
        "The enemy is critically wounded!",
        "The enemy screams in agony!",
        "The attack lands with a loud *SMASH*!"
    };
    string resultsNorm[] = {
        "The enemy shrugs off the attack.",
        "Tis' but a scratch!",
        "The attack barely scratches the enemy.",
        "The enemy laughs at your feeble attempt.",
        "The attack lands with a soft *thud*."
    };
        if (roll <= criticalHitChance) {
            criticalAttack = true;
            cout << "Critical hit! " << resultsCrit[rand() % 5] << endl;
        } else {
            normalAttack = true;
            cout << "Regular hit. " << resultsNorm[rand() % 5] << endl;
        }
        if (normalAttack) {
            cout << "You dealt " << baseDamage << " damage." << endl;
        } else if (criticalAttack) {
            cout << "You dealt " << baseDamage * 2 << " damage!" << endl;
        }
    return 0;
}