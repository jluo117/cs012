#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "BBoard.h"
#include "User.h"
using namespace std;

BBoard::BBoard(){
}

BBoard::BBoard(const string& subject){
    title = subject;
}

bool BBoard::loadUsers( const string& userfile){
    ifstream fileIn;
    fileIn.open(userfile);
    if (!fileIn.is_open()){
        return false;
    }
string userN;
string userPW;

   while (fileIn >> userN){
       fileIn >> userPW;
       User userData (userN , userPW);
       userList.push_back(userData);
   }

    return true;
}

bool BBoard::login(){
    int t=1;
    while (t==1){
    cout << "Enter your username ('Q' or 'q' to quit): ";
    string userEnter;
    cin >> userEnter;
    cout << endl;
    if ((userEnter == "q") || (userEnter == "Q")){
        cout << "Bye!" << endl;
        return false;
    }
    string PW;
    cout << "Enter your password: ";
    cin >> PW;
    cout << endl;


    for (int i= 0 ; i<userList.size(); i++){
        if (userList.at(i).check (userEnter , PW)){
            currentUser = userList.at(i);
            return true;
        }

    }
    cout << "Invalid Username or Password!" << endl;

}
return false;
}



void BBoard::run(){
    if(!login()){
        return;
    }
    char userInput;
    while ((userInput != 'Q')||(userInput != 'q')){
        display();
        cin >> userInput;
        if ((userInput == 'D')||(userInput == 'd')){
            for (int i = 0; i<messageList.size() ; i++){
                cout <<  "Message #" << i <<": ";
           messageList.at(i).display();
            }
        }
        if ((userInput == 'N')||(userInput == 'n')){
            addMessage();
        }

return;
}
}



void BBoard::display() const {
    cout << "Menu" << endl;
    cout << "- Display Messages ('D' or 'd')" << endl;
    cout << "- Quit ('Q' or 'q')" << endl;
    cout << "- Add New Message ('N' or 'n')" << endl;
}
void BBoard::addMessage() {

    string subj;
    string bdy;
    cout << "Enter Subject: ";
    cin >> subj;
    cout << endl;
    cout << "Enter Body: ";
    cin >> bdy;
    cout << endl;
    Message newMsg (currentUser.username, subj , bdy);
    messageList.push_back (newMsg);
}
