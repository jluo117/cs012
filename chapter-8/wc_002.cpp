#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char* arvg[]){
    if (argc <2){
        cout << "error" <<endl;
        return 1;
    }

    ifstream fin(arvg[1]);
    if (!fin){
        cout << "Error opening" << arvg[1] <<endl;
        return 1;
    }
    char ch;
    string line;
    string word;
    istringstream ssin;
    int Wordcount=0;
    int charCount=0;
    int lineCount=0;
while(getline(fin, line)){

   lineCount ++;
   wordCount = line.size()+wordCount;
   ssin.str(line);
   while (ssin >>word){
       Wordcount++;

   }
   ssin.clear();
}
cout << count << endl;
return 0;
}
