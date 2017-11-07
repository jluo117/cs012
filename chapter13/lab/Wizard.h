#ifndef WIZARD_H
#define WIZARD_H
#include "Character.h"

class Wizard:public Character{
    private:
    int rank;
    public:
    Wizard(string name,double health, double attackStrength,int rank);
    int getRank();
    void attack(Character &opponent);
    private:
    void WizFight(Character &target);
};
#endif

