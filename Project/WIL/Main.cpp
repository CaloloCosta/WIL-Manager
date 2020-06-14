#include<iostream>
#include <string>
#include "UserManagement.h"
// using namespace std;

using namespace std;

int main()
{
    /* code */
    // create a supervisor
    //SuperVisor(string on, string vh, string email, string phone, string uid, string pw, string firstname, string surname):User(uid,pw,firstname,surname,phone,email)
    //SuperVisor sv = SuperVisor("505","anytime","carlos@est.com","0819191","2190000","ppassword","carlos","costa");
    // cout << "First Name: ";
    // sv.details();
    int option;
    string username, password,b;
    cout << "Welcome to WIL - MANAGEMENT"<<endl;
    cout << "1 - Lecturer Login "<<endl;
    cout << "2 - Student Login  "<<endl;
    cout << "3 - Admin Login    "<<endl;
    cout << "4 - Exit           "<<endl;

    cin >> option;
    getline(cin,b);

    if (option == 4){
        return 0;
    }
    
    cout <<"Username: ";
    getline(cin,username);
    cout <<"Password: ";
    getline(cin,password);
    UserManagement uManagement = UserManagement();
    bool login = uManagement.login(username,password,option);


    switch (option)
    {
    case 3:
        if(login){
            cout << "Welcome Admin!"<<endl;
            cout << "1 - Add Lecturer "<<endl;
            cout << "2 - Add Student  "<<endl;
            cout << "3 - Login Logout    "<<endl;

            cin >> option;
            getline(cin,b);

            if(option == 1){
                uManagement.addLecturer();
            }
            else if(option == 2){
                uManagement.addStudent();
            }
        }
        break;
    
    default:
        break;
    }

    return 0;
}
