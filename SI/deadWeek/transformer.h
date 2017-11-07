#include "Vehicle.h"
class transformer public:Vechicle{
    private:
    int hp;
    int attack;
    public:
    transformer(int speed,int acceleration,string name,string color,int hp, int attack);
    void attack(Vehicle &target);
};
