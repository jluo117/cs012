#include <iostream>
#include <vector>
using namespace std;

struct seat{
    string name;
    int num;
};


int main(){
    vector<seat>v;
    string test;
    seat test1;
    int num;
    while (cin >> test){
        cin >> num;
        test1.name = test;
        test1.num = num;
        v.push_back(test1);
    }

    cout << v.at(1).num;
    return 0;
}
