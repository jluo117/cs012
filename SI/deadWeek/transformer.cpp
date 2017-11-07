#include <iostream>
#include "transformer.h"
using namespace std;

transformer::transformer(int speed,int acceleration,string name,string color,int hp, int attack)
    :Vehicle(speed,accleration,name,color), hp(hp), attack(attack)
    {}

void transformer::attack(Vechicle &target){
    cout << target.name << " hits " << this->name <<'.' << endl;
    cout << this->name <<" blows up "<< target.name << " with "<< this->attack <<" attack." << endl;
}
