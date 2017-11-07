#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

// Place charCnt prototype (declaration) here
int charCnt(string filename, char userChar){
   int userCharCnt = 0;
   ifstream inFS;
   inFS.open(filename);
   if (inFS.fail()){
      cout << "Error opening " << filename << endl;
      return 1;
   }
   while (!inFS.eof()){
      char fileChar;

inFS >> fileChar;
	  if (inFS.good()){
	if (fileChar == userChar){
	   userCharCnt++;
	}

   }


}

   inFS.close();
   return userCharCnt;
}

int main() {
   string filename;
   char ch;
   cout << "Enter the name of the input file: ";
   cin >> filename;
   ifstream inFS;
   inFS.open(filename);

   cout << endl;
   cout << "Enter a character: ";
   cin >> ch;
   cout << endl;

   cout << "# of " << ch << "'s: " << charCnt(filename, ch) << endl;

   return 0;
}

