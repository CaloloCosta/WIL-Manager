#include "User.h"
#include "SuperVisor.h"
#include "Student.h"
#include<iostream>
#include <string>
#include<list>
#include <iterator>
#include "UserManagement.h"
#include "FileHandling.h"

// using namespace std;

using namespace std;


void showlist(list<Student> st){
    
    for(list<Student>::iterator it = st.begin(); it != st.end(); ++it){
        FileHandling::create("students.csv",it->data());
    }
}

void showlist(list<SuperVisor> st){
    for(list<SuperVisor>::iterator it = st.begin(); it != st.end(); ++it){
        FileHandling::create("lectures.csv",it->data());
    }
}

int main()
{
    list <Student> students;
    list <SuperVisor> lecturers;
    int option;
    string username, password,b;
    while(option != 4){
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
                while(option != 0){
                    cout << "Welcome Admin!"<<endl;
                    cout << "1 - Add Lecturer "<<endl;
                    cout << "2 - Add Student  "<<endl;
                    cout << "3 - Search Student  "<<endl;
                    cout << "4 - Search Lecturers  "<<endl;
                    cout << "4 - List Students  "<<endl;
                    cout << "5 - List Lecturers  "<<endl;
                    cout << "0 - Logout    "<<endl;

                    cin >> option;
                    getline(cin,b);

                    if(option == 1){
                        lecturers.push_back(uManagement.addLecturer());
                    }
                    else if(option == 2){
                        students.push_back(uManagement.addStudent());
                    }
                    else if(option == 3){

                    }
                    else if(option == 4){
                        
                    }
                    else if(option == 5){
                        cout << "here";
                        FileHandling::read("lectures.csv");
                        
                    }
                }

                showlist(students);
                showlist(lecturers);
            }
            break;
        
        default:
            break;
        }

    }

    return 0;
}
