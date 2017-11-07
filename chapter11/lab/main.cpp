#include <iostream>
#include "IntVector.h"

using namespace std;

int main(){
     IntVector empty;
     IntVector someThing (5 ,5);
     cout << someThing.size() <<endl;
     cout <<someThing.front() <<empty.at(0)<< someThing.back() << endl;
     if (empty.empty()){
         cout << "Empty";
     }

     return 0;
}
