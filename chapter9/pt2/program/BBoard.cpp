#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>




#include "BBoard.h"
#include "User.h"
#include "Reply.h"
#include "Topic.h"
#include "Message.h"
using namespace std;

BBoard::BBoard(){
}

BBoard::BBoard(const string& subject){
    title = subject;
}



BBoard::~BBoard(){
    if (messageList.at(0) == 0){
        return;
    }

    for(unsigned i = 0; i<messageList.size();i++){
    delete messageList.at(i);
    }

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


bool BBoard::loadMessages(const string &datafile)



bool BBoard::login(){
    string userEnter;
    cout << "Welcome to " << title;

    while ((userEnter !="q")||(userEnter !="Q")){
        cout << endl << "Enter your username ('Q' or 'q' to quit): ";
        cin >> userEnter;
        cout << endl;
        if ((userEnter == "q") || (userEnter == "Q")){
            cout << "Bye!" << endl;
            exit(0);
            return false;
        }

        string PW;
        cout << "Enter your password: ";
        cin >> PW;
        cout << endl;


        for (unsigned i= 0 ; i<userList.size(); i++) {
            if ((userList.at(i).check (userEnter , PW))&&userExists(userEnter, PW)){
                currentUser = &userList.at(i);
                cout << "Welcome back " << userEnter<<'!' << endl;
                return true;
            }
        }
        cout << "Invalid Username or Password!"  << endl;
    }

    return false;
}



void BBoard::run(){
    char userInput = '\0';
    cout << endl;
    cout << "Menu" << endl;
    cout << "- Display Messages ('D' or 'd')" << endl;
    cout << "- Add New Topic ('N' or 'n')" << endl;
    cout << "- Add Reply to Topic ('R' or 'r')" << endl;
    cout << "- Quit ('Q' or 'q')" << endl;
    cout << "Choose an action: "<<endl;;
    cin>>userInput;
        if ((userInput == 'D')||(userInput == 'd')){
            display();
            run();
        }
       else  if ((userInput == 'N')||(userInput == 'n')){
            addTopic();
            run();
        }
        else if ((userInput == 'R') ||(userInput == 'r')){
            addReply();
            run();
        }

            cout << "Bye!" << endl;
        }






void BBoard::addTopic() {
    string Sub;
    cout << "Subject: ";
	cin.ignore();
    getline(cin,Sub);
    string bd;
    string name;
    cout << "\nBody" << endl;
 while (getline(cin,name)){
     if (name.empty()){
        unsigned size = messageList.size() + 1;
        messageList.push_back(new Topic(currentUser->getUsername(),Sub,bd,size));
        return;
     }
     cout << "Enter a body" << endl;
     bd = bd + (name + "\n");
}
}

void BBoard::addReply(){
    int targetId;
    cout << "Enter Message ID: ";
    cin >> targetId;
    if (targetId == -1){
        return;
    }
    if (targetId > messageList.size()||targetId == 0){
        cout << "Invalid Message ID!!" << endl;
        addReply();
    }
    string Sub = "Re: "+ messageList.at(targetId -1)->getSubject();

    string bd;
    string name;
    cout << "\nBody" << endl;
    cin.ignore();
 while (getline(cin,name)){
     if (name.empty()){
        unsigned size = messageList.size() + 1;
        Reply *msg = new Reply(currentUser->getUsername(),Sub,bd,size);
        messageList.push_back(msg);
       messageList.at(targetId -1)-> addChild(Reply(currentUser->getUsername(),Sub,bd,size));
        return;
     }

     bd = bd + name + "\n";
}
}

void BBoard::display() const{
	cout << endl;
	//if there is at least 1 message pointer, continue on with functions
	if (messageList.size() == 0)
	{
		cout << "Nothing to Display." << endl;
	}
	else
	{
		for (unsigned int i = 0; i < messageList.size(); i++)
		{

			if (messageList.at(i)->isReply() == false)
			{
				cout << "-------------------------------------------------------------------------------" << endl;
				messageList.at(i)->print(0);
			}
		}
		cout << "-------------------------------------------------------------------------------" << endl;
	}
}
bool BBoard::saveMessages(const string &datafile){
    ofstream writeTo;
    writeTo.open(datafile);
        if (!writeTo.is_open()){
            return false;
        }
    for (unsigned i = 0; i< messageList.size(); i++){
        writeTo << messageList.at(i)->toFormattedString();
                writeTo << '\n';
    }
    writeTo.close();
    return true;
}


 bool  BBoard::userExists(const string & Uname, const string & pw) const{
     if ((Uname =="")||(pw =="")){
         cout << "Invalid Username or Password!" << endl;
         return false;
     }
     return true;
 }

