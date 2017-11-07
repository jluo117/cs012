#include <iostream>
#include "vectorFunction.h"
#include <vector>
using namespace std;

int main(){
    vector <int> rand(100);
    fillVec(rand);
    cout << "Enter a number" << endl;
    int toGuess;
    cin >> toGuess;
    sortVec(rand);
    int loc = rand.size()/2;
    i = rand.at(loc);
    while (rand.at(loc) != toGuess)
    if (toGuess < loc){
        loc = loc/2;

    }
    else

