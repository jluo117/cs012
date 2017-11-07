#include <iostream>
#include <vector>
#include "vectorFunction.h"
#include <cstdlib>
#include <ctime>
using namespace std;
bool match(const vector <int>& v){
for (int i=0; i <v.size(); i++){
    if (v.at(i)==v.size()){
        return true;
    }
}
return false;
}
int main (){
    int vecSize;
    int repeat =0;
    bool vecMatch=true;
    cin >> vecSize;

    vector <int> vec (vecSize);
    while (vecMatch){
    fillVec (vec);
    vecMatch = match(vec);
    printVec(vec);
    repeat ++;

    }
    cout <<repeat <<endl;
    for (int i=0; i<repeat; i++){
        cout << "Do you like jazz?" <<endl;
    }
return 0;
}
