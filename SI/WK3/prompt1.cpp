#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "vectorFunction.h"
using namespace std;
struct students {
    string name;
    string major;
}
;

int main(){
   vector <students> college1;
    string name;
    string major;
    ifstream fileIn;
    fileIn.open ("file.txt");

    while ((fileIn >> name) && (fileIn>>major)){
    students i;
    i.name = name;
    i.major = major;
    college1.push_back(i);
    }
    for (int i=0; i <college1.size();i++){
        cout << college1.at(i).name <<':' <<college1.at(i).major <<endl;
    }
return 0;
}
