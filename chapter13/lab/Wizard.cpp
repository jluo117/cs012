#include <iostream>
#include "Wizard.h"
using namespace std;

Wizard::Wizard(string name, double health , double attackStrength, int rank)
    : Character(WIZARD,name,health,attackStrength), rank(rank){
    }
int Wizard::getRank(){
    return this->rank;
}

void Wizard::attack(Character &opponent){
    if (opponent.getType() == WIZARD){
        WizFight(opponent);
        return;
    }
    opponent.setHealth(opponent.getHealth() - attackStrength);
    cout <<"Wizard "<<getName() << " attacks "<<opponent.getName()<<" --- POOF!!" << endl;
    cout <<opponent.getName() <<" takes "<< attackStrength <<" damage." << endl;
    }
void Wizard::WizFight(Character &opponent){
   double damage = attackStrength *  (static_cast<double>(rank) / dynamic_cast<Wizard &>(opponent).getRank());
    opponent.setHealth(opponent.getHealth() - damage);
    cout << "Wizard " << name << " attacks " << opponent.getName() << " --- POOF!!\n";
    cout << opponent.getName() << " takes " << damage << " damage." << endl;
}
