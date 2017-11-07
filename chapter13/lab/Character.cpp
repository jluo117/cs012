#include <iostream>
#include "Character.h"
using namespace std;

Character::Character(HeroType type, const string &name, double health, double attackStrength){
    if (health > MAX_HEALTH){
        health = MAX_HEALTH;
    }
    this->type = type;
    this->name = name;
    this->health = health;
    this->attackStrength=attackStrength;
}


HeroType Character ::getType() const{
    return type;
}


const string &Character::getName() const{
    return name;
}


int Character::getHealth() const{
    return health;
}

void Character::setHealth(double h){
    if (h > MAX_HEALTH){
        h = MAX_HEALTH;
    }
    this->health = h;
}

bool Character::isAlive() const{
    if (health > 0){
        getHealth();
        return true;
    }
    return false;
}

 void Character::attack(Character & opponent){
    double damage = attackStrength*(health/MAX_HEALTH);
    double hp =opponent.getHealth() - damage;
    opponent.setHealth(hp);
}
