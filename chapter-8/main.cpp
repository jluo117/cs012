#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
void readData(const string  inputFile, vector<double> &flightAngles, vector<double> &lift){
	ifstream inFS;
	inFS.open(inputFile);
	if (!inFS.is_open()){
        cout <<endl;
		cout << "Error opening " << inputFile <<endl;
		exit(1);
	}
	double angles;
	double coLift;
	while (inFS >> angles){
		flightAngles.push_back(angles);
		inFS >> coLift;
		lift.push_back(coLift);
	}
}
void reorder (vector <double>& angles, vector <double>& lift){
    for (unsigned i=0; i<angles.size(); i++){
        for (unsigned r=i; r<angles.size();r++){
            if (angles.at(i)>angles.at(r)){
                swap (angles.at(i),angles.at(r));
                swap (lift.at(i),lift.at(r));
            }
        }
    }
}
bool isOrdered( const vector<double>& v){
for (unsigned i=0; i<v.size();i++){
    for (unsigned j=i; j<v.size(); j++){
        if (v.at(i)>v.at(j)){
    return false;
    }
}
}
    return true;
}




double interpolation(double flightAngle, const vector<double> & angle, const vector<double> & lift){
    for (unsigned i=0; i<angle.size();i++){
        if (angle.at(i)==flightAngle){
            return lift.at(i);
        }
    }

int lessThen;
int moreThen;
    for (unsigned i=0; i<angle.size();i++){
        if (angle.at(i)<flightAngle){
            lessThen = i;
        }
    }
    for (int i=angle.size()-1;i>=0;i--){
        if (angle.at(i)>flightAngle){
            moreThen = i;
        }
    }
    return lift.at(lessThen)+(flightAngle - angle.at(lessThen))/(angle.at(moreThen)-angle.at(lessThen))*(lift.at(moreThen)-lift.at(lessThen));
}





void printVec (const vector <double>&  UserVec){
    for (unsigned i=0; i <UserVec.size(); i++)
    {
        cout << UserVec.at(i) << ' ';
    }
    cout <<endl;
    return;
}

int main (){
	string test;
   cout <<"Enter name of input data file:" <<endl;
	cin >> test;
    double angles;
    bool go =true;
	vector <double> flightAngles;
	vector <double> lift;
	readData(test,flightAngles,lift);
    cout << "testing order"<<endl;
    while (!isOrdered(flightAngles)){
         reorder(flightAngles,lift);
    }
    while(go){
    cin >> angles;
    if (angles>flightAngles.at(flightAngles.size()-1)||angles<flightAngles.at(0)){
        cout << "Error" <<endl;
        return 1;
    }
    cout <<interpolation(angles,flightAngles,lift) <<endl;
    cout << "Do you want to continue" <<endl;
    string keepGoing;
    cin >> keepGoing;
    if (keepGoing =="No"){
        go = false;
    }
    }


return 0;
}
