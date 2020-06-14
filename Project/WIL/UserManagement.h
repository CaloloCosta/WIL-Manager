#include<string>
#include<iostream>


using namespace std;
class UserManagement
{
private:
    string username;
    string password;
    int userType;
public:
    bool login(string username, string password, int userType){
        this->username = username;
        this->password = password;
        this->userType = userType;
        if(this->username.compare("admin") == 0 && this->password.compare("admin") == 0 && this->userType == 3){
            return true;
        }
        return false;
    }

    SuperVisor addLecturer(){
        string firstname,surname, email, vh, phone, uid, office;
        
        cout << "Lecturer Firstname: ";
        getline(cin,firstname); 
        cout << "Lecturer Surname: ";
        getline(cin,surname);
        cout << "Lecturer Phone: ";
        getline(cin,phone);
        cout << "Lecturer Email: ";
        getline(cin,email);
        cout << "Lecturer userId: ";
        getline(cin,uid);
        cout << "Lecturer Office number: ";
        getline(cin,office);


        SuperVisor sv = SuperVisor(office,"10-11",email,phone,uid,"123",firstname,surname);
        cout << "Lecturer reistered successfully!"<<endl;
        sv.details();
        return sv;

    }

    Student addStudent(){
        string firstname,surname, email, phone, uid, programme,b;
        int semester;
        
        cout << "Student Firstname: ";
        getline(cin,firstname); 
        cout << "Student Surname: ";
        getline(cin,surname);
        cout << "Student Phone: ";
        getline(cin,phone);
        cout << "Student Email: ";
        getline(cin,email);
        cout << "Student Number: ";
        getline(cin,uid);
        cout << "Student Current Semester: ";
        cin >> semester;
        getline(cin,b);
        cout << "Student Programme: ";
        getline(cin,programme);
  


        cout << "Student reistered successfully!"<<endl;
        // Student(string email, string phone, string uid, string pw, string firstname, string surname, int semester, string programme)
        Student st = Student(email,phone,uid,"123",firstname,surname,semester,programme);
        st.details();
        return st;

    }
};
