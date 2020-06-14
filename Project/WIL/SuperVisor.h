#include<iostream>
#include <string>
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
    SuperVisor();

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
        cout << "Firstname: "+ this->getFirstname()<<endl;
        cout << "Surname: "+ this->getSurname()<<endl;
        cout << "Office: "+ this->getOfficeNumber()<<endl;
        cout << "Phone: "+ this->getPhone()<<endl;
        cout << "Email: "+ this->getEmail()<<endl;
        cout << "Visiting hours: "+ this->getVh()<<endl;
    }

    string data(){
        //string on, string vh, string email, string phone, string uid, string pw, string firstname, string surname
        return this->setUserid()+","+this->getPassword()+","+this->getFirstname()+","+this->getSurname()+","+this->getEmail()+","+this->getPhone()+","+this->getOfficeNumber()+","+this->getVh()+"\n";
    }
    

};

