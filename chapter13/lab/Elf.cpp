#include <iostream>
#include "Elf.h"
using namespace std;

Elf::Elf(string name,double health,double attackStrength,string family)
: Character(ELF,name,health,attackStrength){
    this->family = family;
}

string Elf::getFamily(){
    return family;
}

void Elf::attack(Character &opponent){
    if (opponent.getType() == ELF){
        if (dynamic_cast<Elf &>(opponent).getFamily() == getFamily()){
            cout <<"Elf "<<getName() <<" does not attack Elf "<<opponent.getName()<<'.' << endl;
            cout << "They are both members of the "<<getFamily() <<" family." <<endl;
            return;
        }
    }
Character::attack(opponent);
cout <<"Elf "<<getName() << " shoots an arrow at " << opponent.getName() <<" --- TWANG!!" << endl;
cout << opponent.getName()<<" takes "<< attackStrength*(health/MAX_HEALTH) << " damage." << endl;
}
