#include <iostream>
#include "Warrior.h"
using namespace std;

Warrior::Warrior(string name,double health,double attackStrength, string allegiance)
    : Character(WARRIOR,name,health,attackStrength),allegiance(allegiance){
    }

const string  & Warrior::getAllegiance() const{
    return this->allegiance;
}

void Warrior::attack(Character &opponent){
    if(opponent.getType() == WARRIOR){
        if (dynamic_cast<Warrior &>(opponent).getAllegiance() == allegiance){
            cout << "Warrior " << getName() << " does not attack Warrior "<< opponent.getName()<<'.'<<endl;
            cout << "They share an allegiance with "<<allegiance<<'.'<< endl;
            return;
        }
    }

    Character::attack(opponent);
    cout << "Warrior "<<getName()<<" attacks " << opponent.getName()<<" --- SLASH!!"<<endl;
    cout << opponent.getName() << " takes "<<attackStrength*(health/MAX_HEALTH)<<" damage." << endl;
}

