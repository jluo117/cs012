#include <iostream>
#include <vector>
using namespace std;


void getInput(vector <int>& UserVec){
    int userNum;
    while (cin >> userNum){
        UserVec.push_back(userNum);
    }
    return;
}

void printVec (const vector <int>&  UserVec){
    for (int i=0; i <UserVec.size(); i++)
    {
        cout << UserVec.at(i) << ' ';
    }
    cout <<endl;
    return;
}
void printVec (const vector <string>& UserVec){
    for (int i=0; i < UserVec.size();i++){
        cout << UserVec.at(i) <<' ';
    }
    cout << endl;
    return;
}
double mean (const vector <int>& UserVec){
    int userTotal = 0;
    for (int i=0; i<UserVec.size(); i++){
        userTotal = userTotal + UserVec.at(i);
    }
    return userTotal / UserVec.size();
}

int add (const vector <int>& UserVec){
    int userTotal =0;
    for (int i = 0; i<UserVec.size(); i++){
        userTotal = userTotal + UserVec.at(i);
    }
    return userTotal;
}

void swapLocation (vector <int>& UserVec){
    int i=0;
    int j=UserVec.size()-1;
    while (i<j){
        int temp = UserVec.at(i);
        UserVec.at(i) = UserVec.at(j);
        UserVec.at(j) = temp;
        i++;
        j--;
    }
}



int max (const vector <int>& UserVec){
    int maxNum = UserVec.at(0);
    for (int i=1; i< UserVec.size(); i++){
        if (UserVec.at(i) > maxNum){
            maxNum = UserVec.at(i);
        }
    }
        return maxNum;
}



int min (const vector <int>& UserVec){
    int minNum = UserVec.at(0);
    for (int i=1; i < UserVec.size(); i++){
        if (UserVec.at(i) < minNum){
            minNum = UserVec.at(i);
        }
        }
        return minNum;
}

void fillVec(vector<int>& v){
    srand (3333);
    for (int i =0; i<v.size();i++
        v.at(i)=(rand()%v.size());
    }
}
void sortVec (vector <int>& v){
    for (int i=0; i<v.size(); i++){
        for (int r=i; r<v.size();r++){
            if (v.at(i)>v.at(r)){
                swap (v.at(i),v.at(r));
            }
        }
    }
}
