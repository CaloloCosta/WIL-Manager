#include<string>
using namespace std;
class User
{
private:
    /* data */
    string userid;
    string password;
    string firstname;
    string surname;
    string email;
    string phone;
    int userType;
public:
    User(string uid, string pw,string firstname,string surname, string phone, string email, int userType){
        userid = uid;
        password = pw;
        this->email = email;
        this->phone = phone;
        this->firstname = firstname;
        this->surname = surname;
        this->userType = userType;
    }
// setters
    void setUserid(string uid){
        userid = uid;
    }
    void setPassword(string pw){
        password = pw;
    }
    void setFirtsname(string fn){
        firstname = fn;
    }
    void setSurname(string sn){
        surname = sn;
    }
     void setEmail(string email){
        this->email = email;
    }
    void setPhone(string phone){
        this->phone = phone;
    }
    
// Getters
    string setUserid(){
        return userid;
    }
    string getPassword(){
        return password;
    }
    string getFirstname(){
        return firstname;
    }
    string getSurname(){
        return surname;
    }
     string getPhone(){
        return this->phone;
    }
    string getEmail(){
        return this->email;
    }
};
