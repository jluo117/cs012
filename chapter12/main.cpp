#include <iostream>
#include <string>
using namespace std;




void flipString(string &s){
if (s.size() == 0){
    return;
}
if (s.size() <= 3){
    swap(s.at(0),s.at(s.size()-1) );
}
else{
    swap(s.at(0),s.at(s.size() -1));
    string b = (s.substr(1, s.size() - 2));
    flipString(b);
    s.replace(1,s.size()-2,b);
}
}

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

