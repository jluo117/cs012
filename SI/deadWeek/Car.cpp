#include <iostream>
#include "Car.h"
using namespace std;

Car::Car(int speed, int acceleration,string name, string color,int numTires,string brand, int MPG)
:Vehicle(speed,acceleration,name,color),numTires(numTires),brand(brand),MPG(MPG)
{}

int Car::howFar(int gallon){
    return gallon*MPG;
}


void Car::printstats(){
    Vehicle::display();
    cout << "Tires: "<< numTires << endl;
    cout << "Brand: "<<brand << endl;
    cout <<"MPG: " << MPG << endl;
}
