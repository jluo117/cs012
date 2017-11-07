#include <iostream>
#include <stdlib.h>
using namespace std;
#include "Distance.h"
Distance::Distance(){
     feet = 0;
     inches =0.0;
}



Distance::Distance (unsigned ft, double in){
    if (in<0){
        in=in*-1;
    }
    feet = ft + in/12;
    inches = (in+ft*12)-feet*12;


}


Distance::Distance ( double in){
    if (in<0){
        in=in*-1;
    }
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
    DistanceFinal.inches = (rhs.feet*12)+rhs.inches + inches + (feet *12);
    DistanceFinal.init();
    return DistanceFinal;
}

const Distance Distance::operator-(const Distance &rhs) const{
    Distance DistanceFinal;
    double finalInch;
    double finalInch1 =((inches + feet*12)-((rhs.feet*12) + rhs.inches));
    if (finalInch1<0){
         finalInch = finalInch1*-1;
    }
    else{
         finalInch = (finalInch1);
    }
    DistanceFinal.feet = finalInch/12;
    DistanceFinal.inches = finalInch-(DistanceFinal.feet*12);
    return DistanceFinal;
}
ostream & operator<<(ostream &out, const Distance &rhs){
   return out <<rhs.feet <<"' "<< rhs.inches << "\"";

}

 void Distance::init(){
    if (inches<0){
        inches = inches * -1;
    }
    inches = feet + inches;
    feet = inches/12;
    inches = inches -feet*12;
}

