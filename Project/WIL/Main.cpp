#include "User.h"
#include "SuperVisor.h"
#include "Student.h"
#include<iostream>
#include <string>
#include<list>
#include <iterator>
#include "FileHandling.h"
#include "UserManagement.h"
#include "UserAction.h"


// using namespace std;

using namespace std;


void showlist(list<Student> st){
    if(st.size() > 0){
        for(list<Student>::iterator it = st.begin(); it != st.end(); ++it){
            FileHandling::create("students.csv",it->data());
        }
        st.clear();
    }
}

void showlist(list<SuperVisor> sv){
    if(sv.size() > 0){
        for(list<SuperVisor>::iterator it = sv.begin(); it != sv.end(); ++it){
            FileHandling::create("lecturers.csv",it->data());
        }
        sv.clear();
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
        case 1:
            if(login){
                while(option != 0){
                    cout << "Welcome Lecturer!"<<endl;
                    cout << "1 - List Students  "<<endl;
                    cout << "2 - Search Students  "<<endl;
                    cout << "3 - Leave a notice  "<<endl;
                    cout << "4 - See Notices  "<<endl;
                    cout << "5 - See student notices"<<endl;
                    cout << "0 - Logout    "<<endl;
                    cin >> option;
                    getline(cin,b);

                    if(option == 1){
                        showlist(students);
                        students.clear();
                        showlist(lecturers);
                        lecturers.clear();
                        FileHandling::printData(FileHandling::read("students.csv"),2);
                    }
                    else if(option == 2){
                        showlist(students);
                        students.clear();
                        showlist(lecturers);
                        lecturers.clear();
                        cout << "Student Number: ";
                        getline(cin,username);
                        FileHandling::search(FileHandling::read("students.csv"),username,2);

                    }
                    else if(option == 3){
                        // create(string filename, string data){
                        FileHandling::create("notices.csv",UserAction::addNotice(username,"lecturer"));
                    }
                    else if(option == 4){
                        FileHandling::printNotice(FileHandling::read("notices.csv"));
                    }
                    else if(option == 5){
                        FileHandling::printNotice(FileHandling::read("studentNotices.csv"));
                    }
                }
            }
            break;
        case 2:
            if(login){
                while(option != 0){
                    cout << "Welcome Student!"<<endl;
                    cout << "1 - See Lecturers  "<<endl;
                    cout << "2 - Search Lecturer  "<<endl;
                    cout << "3 - See Notices  "<<endl;
                    cout << "4 - Leave a message to lecturer "<<endl;
                    cout << "0 - Logout    "<<endl;
                    cin >> option;
                    getline(cin,b);

                    if(option == 1){
                        showlist(students);
                        students.clear();
                        showlist(lecturers);
                        lecturers.clear();
                        FileHandling::printData(FileHandling::read("lecturers.csv"),1);
                    }else if(option == 2){
                        showlist(students);
                        students.clear();
                        showlist(lecturers);
                        lecturers.clear();
                        cout << "Lecurer uid: ";
                        getline(cin,username);
                        FileHandling::search(FileHandling::read("lecturers.csv"),username,1);
                    }else if(option == 3){
                        FileHandling::printNotice(FileHandling::read("notices.csv"));

                    }else if(option == 4){
                        FileHandling::create("studentNotices.csv",UserAction::addNotice(username,"Student"));
                    }
                }
            }
            break;
        case 3:
            if(login){
                while(option != 0){
                    cout << "Welcome Admin!"<<endl;
                    cout << "1 - Add Lecturer "<<endl;
                    cout << "2 - Add Student  "<<endl;
                    cout << "3 - Search Student  "<<endl;
                    cout << "4 - Search Lecturers  "<<endl;
                    cout << "5 - List Students  "<<endl;
                    cout << "6 - List Lecturers  "<<endl;
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
                        showlist(students);
                        students.clear();
                        showlist(lecturers);
                        lecturers.clear();
                        cout << "Student Number: ";
                        getline(cin,username);
                        FileHandling::search(FileHandling::read("students.csv"),username,2);
                    }
                    else if(option == 4){
                        showlist(students);
                        students.clear();
                        showlist(lecturers);
                        lecturers.clear();
                        cout << "Lecurer uid: ";
                        getline(cin,username);
                        FileHandling::search(FileHandling::read("lecturers.csv"),username,1);
                        
                    }
                    else if(option == 5){
                        showlist(students);
                        students.clear();
                        showlist(lecturers);
                        lecturers.clear();
                        FileHandling::printData(FileHandling::read("students.csv"),2);
                    }
                    else if(option == 6){
                        showlist(students);
                        students.clear();
                        showlist(lecturers);
                        lecturers.clear();
                        FileHandling::printData(FileHandling::read("lecturers.csv"),1);
                    }
                }

                showlist(students);
                students.clear();
                showlist(lecturers);
                lecturers.clear();
            }
            break;
        
        default:
            break;
        }

    }

    return 0;
}
