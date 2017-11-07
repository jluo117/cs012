#include <iostream>
#include "Vehicle.h"
using namespace std;

Vehicle::Vehicle(int speed, int acceleration, string name, string color)
   :speed(speed),acceleration(acceleration),name(name),color(color){}

void Vehicle::display(){
    cout <<"MPH: " << speed << endl;
    cout <<"Acceleration: " << acceleration << endl;
    cout << name << endl;
    cout <<"Color: " << color << endl;
}
