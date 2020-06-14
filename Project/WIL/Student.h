#include "User.h"
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

};


