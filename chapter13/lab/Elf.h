#ifndef ELF_H
#define ELF_H
#include "Character.h"
class Elf: public Character{
    private:
    string family;
    public:
    Elf(string name,double health,double attackStrength,string family);
    string getFamily();
    void attack(Character &opponent);
};
#endif

