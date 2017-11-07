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
}

BBoard::BBoard(const string& subject){
    title = subject;
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
bool BBoard::loadMessages(const string& datafile)
{
	//number of messages in files
	int maxMessage;
	//keep count of amount of messages
	int count = 0;
	
	//holds specific keyword strings
	string keyword;
	
	//type of message (topic or reply)
	//also category
	vector <string> message;
	string messageType;
	
	//hold ids
	vector <int> id;
	int tempid;
	
	//hold subjects
	vector <string> subject;
	string tempSubject;
	string finalSubject;
	
	//holds authors
	vector <string> author;
	string tempAuthor;
	
	//hold vector of child ids inside children vector
	vector <string> child;
	string tempChild;
	string stringChild;
	string finalChild = "";
	int intChild;
	ostringstream ss;
	
	//holds bodies
	vector <string> body;
	string tempBody = "";
	string finalBody = "";
	
	//open stream
	ifstream loadFile;
	loadFile.open(datafile.c_str());
	
	//check if file is opened correctly
	if (!loadFile.is_open()) 
	{
		cout << "Could not open file" << endl;
		return false;
	}
	
	//stream in number of messages
	loadFile >> maxMessage;
	
	while (count < maxMessage)
	{
		//stream message type and verify specific message type
		loadFile >> messageType;
		message.push_back(messageType);
		
		//id
		loadFile >> keyword;
		loadFile >> tempid;
		id.push_back(tempid);
		
		//subject
		loadFile >> keyword;
		loadFile >> finalSubject;
		do
		{
			loadFile >> tempSubject;
			if(tempSubject != ":from:")
			{
				finalSubject += " " + tempSubject;
			}
			
		} while(tempSubject != ":from:");
		subject.push_back(finalSubject);
	
		
		//author
		loadFile >> tempAuthor;
		author.push_back(tempAuthor);

		
		loadFile >> keyword;
		
		
		/* if (keyword == ":children:")
		 {
		     while(loadFile >> keyword)
			{
				
				 ss << intChild;
				 finalChild += ss.str() + " ";
				
				loadFile >> keyword;
			 }
			child.push_back(finalChild);
         }
		
		 else
		{
			 child.push_back("empty");
		 }
*/
		
		//body
		loadFile >> finalBody;
		do
		{	
			loadFile >> tempBody;
			if(tempBody != "<end>")
			{
				finalBody += " " + tempBody;
			}
		}while(tempBody != "<end>");
		finalBody += '\n';
		body.push_back(finalBody);

		//will end if count exceeds size of maxMessages
		count++;
	}
	
	for (int i = 0; i < maxMessage; i++)
	{	
		if (message.at(i) == "<begin_topic>")
		{
			Topic* pTopic = new Topic(author.at(i), subject.at(i), body.at(i), id.at(i));
			messageList.push_back(pTopic);
		}
		else
		{
			 Reply* pReply = new Reply(author.at(i), subject.at(i), body.at(i), id.at(i));
			 messageList.push_back(pReply);
		}
	}
	
	loadFile.close();
    //cout << "We got the fuck out" << endl;
	return true;
}
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
    while ((userInput != 'Q')||(userInput != 'q')){
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
        }
       else  if ((userInput == 'N')||(userInput == 'n')){
            addTopic();
        }
        else if ((userInput == 'R') ||(userInput == 'r')){
            addReply();
        }
       else  if ((userInput =='q')|| (userInput =='Q')){
            cout << "Bye!" << endl;
            return;
        }
        else{
            return;
        }
}
return;

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
        unsigned id = messageList.size() + 1;
        Reply *replyStr = new Reply(currentUser->getUsername(),Sub,bd,id);
        messageList.push_back(replyStr);
        messageList.at(targetId -1)-> addChild(replyStr);
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
        writeTo << messageList.size() << '\n';
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

