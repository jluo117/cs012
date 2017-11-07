#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include "IntVector.h"
using namespace std;

IntVector :: IntVector(){
    sz = 0;
    cap = 0;
    data = 0;
}

IntVector :: IntVector(unsigned size, int value){
    sz = size;
    cap = sz;
    data = new int [cap];
    for (unsigned i = 0;i < size; i++){
        data[i] = value;
    }
return;
}

IntVector ::~ IntVector(){
    delete data;
    return;
}

unsigned IntVector :: size() const {
    return sz;
}
unsigned IntVector :: capacity() const {
    return cap;
}
bool IntVector:: empty() const {
    return (sz == 0);
}
void IntVector::expand(unsigned amount){
    dataTemp = new int[cap];
    for (unsigned i = 0; i < cap; i++){
        dataTemp[i] = data[i];
    }
    delete data;
    data = new int[amount];
    for (unsigned i = 0; i< cap; i++){
        data[i] = dataTemp[i];
    }
    delete dataTemp;
}


void IntVector :: insert(unsigned index, int value){
    if (index >= sz){
    throw out_of_range("IntVector::at_range_check");
    }
    if (sz == cap){
        expand(cap *2);
    }
    sz++;
    for (unsigned i = sz; i > index; i++){
        data[i] = data[i -1];
    }
    data[index] = value;
}


const int & IntVector:: at(unsigned index) const{

    /*if ((index >= sz)||(empty())){
        throw out_of_range("IntVector::at_range_check");
    }
    return data[index];
    */

    if (index < sz ) {
        return data[index];
    }
    else {
        throw out_of_range("IntVector::at_range_check");

    }

}
const int & IntVector::  back() const{
    return data[sz -1];
}
const int & IntVector::front() const{
    return data[0];
}
