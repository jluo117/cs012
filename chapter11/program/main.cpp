#include <iostream>
#include "IntVector.h"

using namespace std;

int main(){
     IntVector empty;
     IntVector someThing (20 ,5);
     IntVector assignedTest (12 , 5);
     someThing.pop_back();
     cout << someThing.size() <<endl;
     cout <<someThing.front() <<someThing.at(0)<< someThing.back() << endl;
     if (empty.empty()){
         cout << "Empty" << endl;
     }
     someThing.at(2) = 5;
     someThing.push_back(2);
     cout << someThing.back() << endl;
     someThing.clear();
     someThing.assign (4,10);
     someThing.erase (3);
     someThing.clear();
     someThing.insert(0,-747);
    // cout << "Value changed" << endl;
    // cout <<someThing.at(1);
     cout << someThing.size() << endl;
     someThing.reserve(100);
     assignedTest.assign(10 , 4);
     cout << assignedTest.size() << endl;
     cout << assignedTest.at(10) << endl;
     cout << "Finished" <<endl;
     return 0;
}
