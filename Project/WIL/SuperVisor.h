#include<iostream>
#include <string>
#include "User.h"
using namespace std;
class SuperVisor:public User
{
private:
    /* data */
    string officenumber;
    string visiting_hours;
public:                                                                                                                  
    SuperVisor(string on, string vh, string email, string phone, string uid, string pw, string firstname, string surname):User(uid,pw,firstname,surname,phone,email,1){
        officenumber = on;
        visiting_hours = vh;
    }

    // setters
    void setOfficeNumber(string on){
        this->officenumber = on;
    }
    void setVh(string vh){
        this->visiting_hours = vh;
    }

    // getters
    string getOfficeNumber(){
        return this->officenumber;
    }
    string getVh(){
        return this->visiting_hours;
    }


    // details
    void details(){
        cout << "Office: "+ this->getOfficeNumber();
    }

};

