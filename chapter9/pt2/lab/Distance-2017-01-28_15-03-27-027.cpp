#include <iostream>
using namespace std;
#include "Distance.h"
Distance::Distance(){
     feet = 0;
     inches =0.0;
}



Distance::Distance (unsigned ft, double in){
    feet = ft + (in/12);
    inches = in-(feet*12);
}


Distance::Distance ( double in){
    feet = (in/12);
    inches = in-(feet*12);
}

unsigned Distance::getFeet() const {
    return feet;
}

double   Distance::getInches() const{
    return inches;
}

double Distance::distanceInInches() const {
    return (feet*12)+inches;
}

double Distance::distanceInFeet () const{
    return feet+(inches/12.0);
}

double Distance::distanceInMeters() const {
    return (feet*0.3048)+(inches*0.0254);
}

const Distance Distance::operator+(const Distance &rhs) const{
    Distance DistanceFinal;
    double inch = (rhs.feet*12)+rhs.inches + inches + (feet *12);
    DistanceFinal.feet = inch/12;
    DistanceFinal.inches =inch-(DistanceFinal.feet*12);
    return DistanceFinal;
}

const Distance Distance::operator-(const Distance &rhs) const{
    Distance DistanceFinal;
    double finalInch =(inches + feet*12)-((rhs.feet*12) + rhs.inches);
    DistanceFinal.feet = finalInch/12;
    DistanceFinal.inches = finalInch-(DistanceFinal.feet*12);
    return DistanceFinal;
}
ostream& Distance:: operator<<(ostream &out, const Distance &rhs){
    out <<rhs.feet <<"' "<< rhs.inches << "'' ";
}

void Distance::init(){
    if (inches<0){
        inches = inches * -1;
    }
    inches = feet + inches;
    feet = inches/12;
    inches = inches -feet*12;
}

