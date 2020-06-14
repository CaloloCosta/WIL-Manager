#include<iostream>
using namespace std;
class Student:public User
{
private:
    /* data */
    int semester;
    string programme;

public:
    Student(/* args */);
    Student(string email, string phone, string uid, string pw, string firstname, string surname, int semester, string programme):User(uid,pw,firstname,surname,phone,email,2){
        this->semester = semester;
        this->programme = programme;
    }


    // setters
    void setSemester(int semester){
        this->semester = semester;
    }
    void setProgramme(string programme){
        this->programme = programme;
    }


    // getters
    int getSemester(){
        return semester;
    }
    
    string getProgramme(){
        return programme;
    }

    // details
    void details(){
        cout << "Firstname: "+ this->getFirstname()<<endl;
        cout << "Surname: "+ this->getSurname()<<endl;
        cout << "Phone: "+ this->getPhone()<<endl;
        cout << "Email: "+ this->getEmail()<<endl;
        cout << "Current Semester: "+ this->getSemester()<<endl;
        cout << "Programmer: "+ this->getProgramme()<<endl;
    }

    string data(){
        //string on, string vh, string email, string phone, string uid, string pw, string firstname, string surname
        return this->setUserid()+","+this->getPassword()+","+this->getFirstname()+","+this->getSurname()+","+this->getEmail()+","+this->getPhone()+","+to_string(this->getSemester())+","+this->getProgramme()+"\n";
    }
    

};


