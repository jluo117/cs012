#include <iostream>
#include "User.h"
#include <string>
using namespace std;

User::User(){
    username = "";
    password = "";
}


User::User(const string &uname, const string &pass){
    username = uname;
    password = pass;
}

string User::getUsername() const{
    return username;
}

bool User::check(const string &uname, const string &pass) const{
    if ((uname==username && pass==password)&& ((uname!="")&&(pass!=""))){
        return true;
    }
    return false;
}

bool User::setPassword(const string &oldpass, const string &newpass){
    if (oldpass != password){
        return false;
    }
    password = newpass;
    return true;
}


