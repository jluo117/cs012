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
    delete[] data;
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
    if (amount < cap){
        expand();
        return;
    }
    else {
        cap = amount + cap;
    }
    int dataTemp[sz];
    for (unsigned i = 0; i < sz; i++){
        dataTemp[i] = data[i];
    }
    delete[] data;
    data = new int[cap];
    for (unsigned i = 0; i< sz; i++){
        data[i] = dataTemp[i];
    }
    return;
}

void IntVector::expand(){
    if (cap == 0){
        cap = 1;
    }
    else{
        cap = cap * 2;
    }
     int dataTemp[sz];
     for (unsigned i = 0; i < sz; i++){
          dataTemp[i] = data[i];
     }
      delete[] data;
      data = new int[cap];
      for (unsigned i = 0; i< sz; i++){
         data[i] = dataTemp[i];
     }
     return;
}

void IntVector :: insert(unsigned index, int value){
    if (index > sz){
        throw out_of_range("IntVector::insert_range_check");
    }
    if ((sz + 1) > cap){
        expand(1);
    }
    sz++;
    for (unsigned i = index + 1; i < sz; i++){
        data[i] = data[i - 1];
    }
    data[index] = value;
}
void IntVector :: erase (unsigned index){
    if (index >= sz){
        throw out_of_range("IntVector::erase_range_check");
    }
    for (unsigned i = index; i < sz; i++){
        data[i] = data[i + 1];
    }
    sz--;
}
void IntVector :: push_back(int value){
    if (sz == cap){
        expand();
    }
    sz++;
    data[sz -1] = value;
}

void IntVector::pop_back(){
    sz--;
}

void IntVector::clear(){
    sz = 0;
}

int& IntVector:: at(unsigned index){
   if (index < sz ) {
          return data[index];
    }
    else {
          throw out_of_range("IntVector::at_range_check");

    }
}

const int & IntVector:: at(unsigned index) const{
    if (index < sz ) {
        return data[index];
    }
    else {
        throw out_of_range("IntVector::at_range_check");

    }

}
void IntVector::reserve(unsigned n) {
    if (n < cap){
        return;
    }
	expand(n-cap);

}
const int & IntVector::  back() const{
    return data[sz -1];
}

const int & IntVector::front() const{
    return data[0];
}

int & IntVector::front() {
    return data[0];
}

int & IntVector::back(){
    return data[sz-1];
}

void IntVector::resize(unsigned size, int value){
    if (size < sz){
        sz =size;
        return;
    }
    if (size > cap){
        expand(size-cap);
    }
    for (unsigned i = sz; i < size; i++){
        data[i] = value;
    }
    sz = size;
}

void IntVector::assign(unsigned n, int value){

    sz = n;
    if (sz > cap){
        if (cap<(sz-cap)){
            cap = sz;
        }
        else {
            cap = cap * 2;
        }
        delete[] data;
        data = new int [cap];
    }
    for (unsigned i = 0; i < sz; i++){
        data[i] = value;
    }
}



