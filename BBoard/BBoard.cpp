#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>




#include "BBoard.h"
#include "User.h"
#include "Reply.h"
#include "Topic.h"
#include "Message.h"
using namespace std;




BBoard::BBoard(){
    currentUser = 0;
}

BBoard::BBoard(const string& subject){
    title = subject;
    currentUser = 0;
}



BBoard::~BBoard(){
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
bool BBoard::loadMessages(const string &datafile){
    ifstream fileIn;
    fileIn.open(datafile.c_str());
    if (!fileIn.is_open()){
        return false;
    }
    string input ,athr,sbjct,bdy,msgType,childrens,junk;
    int id;
    unsigned numMsg;
    fileIn >> input;
    if (input.empty()){
        return true;
    }
    istringstream b(input);
    b >> numMsg;
    vector<vector<int> >msgChild(numMsg);
  for (unsigned i = 0; i< numMsg; i++){
                input = "";
                bdy = "";

                fileIn >>  msgType;
        while (input != "<end>"){
                fileIn >> input;
                if (input == ":id:"){
                    fileIn >> id;
                }
                else if (input == ":subject:"){
                    getline (fileIn,sbjct);
                    sbjct = sbjct.substr(1, sbjct.size()-1) ;


                }
                else if (input == ":from:"){
                    fileIn >> athr;
                }
                else if (input == ":children:"){
                    getline(fileIn,childrens);
                   istringstream a(childrens);
                   int num;
                    while(a >> num){
                        msgChild.at(i).push_back(num);
                    }

                }



					else if (input == ":body:") {
                while (input != "<end>") {

                    getline( fileIn, input );

                    if (input == "<end>") {
                        break;
                    }

                    bdy = bdy + input + '\n';
                }

                bdy = bdy.substr(1);
                bdy = bdy.substr(0, bdy.size()-1);
            }

        }
        if (msgType == "<begin_topic>"){
            messageList.push_back(new Topic(athr,sbjct,bdy,id));
        }
        else {
            messageList.push_back(new Reply(athr,sbjct,bdy,id));
        }


  }
    fileIn.close();
    for (unsigned i = 0; i< messageList.size(); i++){
        for (unsigned j = 0; j<msgChild.at(i).size(); j++){
            messageList.at(i) -> addChild(messageList.at(msgChild.at(i).at(j)-1));
        }
    }
            //cout << child.size() << ' ';
     return true;
    }










void BBoard::login(){
    string userEnter;
    cout << "Welcome to " << title;

    while ((userEnter !="q")||(userEnter !="Q")){
        cout << endl << "Enter your username ('Q' or 'q' to quit): ";
        cin >> userEnter;
        if ((userEnter == "q") || (userEnter == "Q")){
            cout << "Bye!" << endl;
            currentUser = 0;
            exit(1);
            return;
        }

        string PW;
        cout << "Enter your password: ";
        cin >> PW;


        for (unsigned i= 0 ; i<userList.size(); i++) {
            if ((userList.at(i).check (userEnter , PW))&&userExists(userEnter, PW)){
                currentUser = &userList.at(i);
                cout << endl;
                cout << "Welcome back " << userEnter<<'!' << endl;
                return;
            }
        }
        cout << "Invalid Username or Password!"  << endl;
    }

}



void BBoard::run(){
    if (currentUser == 0){
        return;
    }
    char userInput = 'q';
    do {
    cout << endl;
    cout << "Menu" << endl;
    cout << "- Display Messages ('D' or 'd')" << endl;
    cout << "- Add New Topic ('N' or 'n')" << endl;
    cout << "- Add Reply to a Topic ('R' or 'r')" << endl;
    cout << "- Quit ('Q' or 'q')" << endl;
    cout << "Choose an action: ";
    cin>>userInput;
        if ((userInput == 'D')||(userInput == 'd')){
            display();
        }
       else  if ((userInput == 'N')||(userInput == 'n')){
            addTopic();
        }
        else if ((userInput == 'R') ||(userInput == 'r')){
            addReply();

        }
       if ((userInput == 'Q') || (userInput=='q')){
           break;
       }
}
while ((userInput != 'Q')||(userInput != 'q'));
    cout << "Bye!" << endl;

}



void BBoard::addTopic() {
    string Sub;
    cout << "Enter Subject: ";
	cin.ignore();
    getline(cin,Sub);
    string bd;
    string name;
    cout << "Enter Body: ";
    unsigned loop = 0;
 while (getline(cin,name)){
     if (name.empty()){
        unsigned size = messageList.size() + 1;
        messageList.push_back(new Topic(currentUser->getUsername(),Sub,bd,size));
        return;
     }
      if (loop > 0){
         bd += '\n';
     }
     loop ++;
     bd += name;
}
}

void BBoard::addReply(){
    int targetId;
    cout << "Enter Message ID: ";
    cin >> targetId;
    if (targetId == -1){
        return;
    }
    int b = messageList.size();
    if ((targetId > b)||(targetId == 0)){
        cout << "Invalid Message ID!!" << endl;
        addReply();
    }
    string Sub = "Re: "+ messageList.at(targetId -1)->getSubject();

    string bd;
    string name;
    cout << "\nEnter Body" << endl;
    cin.ignore();
    unsigned loop = 0;
 while (getline(cin,name)){
     if (name.empty()){
        unsigned id = messageList.size() + 1;
        Reply *replyStr = new Reply(currentUser->getUsername(),Sub,bd,id);
        messageList.push_back(replyStr);
        messageList.at(targetId -1)-> addChild(replyStr);
        return;
     }
     if (loop > 0){
         bd += '\n';
     }
     loop ++;
     bd += name;
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
		for (unsigned i = 0; i < messageList.size(); i++)
		{

			if (messageList.at(i)->isReply() == false)
			{
				cout << "---------------------------------------------------------" << endl;
				messageList.at(i)->print(0);
                cout << endl;
			}
		}
		cout << "---------------------------------------------------------" << endl;
	}
}
bool BBoard::saveMessages(const string &datafile){
    ofstream writeTo;
    writeTo.open(datafile);
        if (!writeTo.is_open()){
            return false;
        }
        writeTo << messageList.size() << '\n';
    for (unsigned i = 0; i< messageList.size(); i++){
        writeTo << messageList.at(i)->toFormattedString();

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

