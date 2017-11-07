#ifndef WARRIOR_H
#define WARRIOR_H
#include "Character.h"
class Warrior: public Character{
    private:
    string allegiance;
    public:
    Warrior(string name,double health,double attackStrength,string allegiance);
    const string & getAllegiance() const;
    void attack(Character &opponent);
};

#endif
