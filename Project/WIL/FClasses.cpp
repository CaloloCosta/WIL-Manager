// A class Person that store the lastname and facultyID of a Person. From this class derive two classes: Lecturer, which add a StudentID count and Supervisor, which add a Company Number. Each of these there classes have a getdata() function to get its data from the user at the keyboard, and put a putdata() function to display its data.
// A base class ReportMark that hold an array of three ints so that it can record the report Marks of particular Person for the last three months. A getData() function to get three ReportMark amount from the user and a putdata() function to display the ReportMark figures. The Lecturer and Supervisor classes are derived from both Person class. An object of class Lecturer or Supervisor input and output ReportMark data along with its other data. 

#include <iostream>
#include <string>

using namespace std;

class Person;
class ReportMark;


class Person
{
public:
	String lastname;
	int facultyID;


private:
	friend class ReportMark;
};

class ReportMark
{
public:
	Person PersonReportMark[3];
	void getdata()
	{
		cout << "Enter Student lastName: " << endl;
		getline(cin, PersonReportMark[0].lastName);
		cout << "Enter facultyID: " << endl;
		cin >> PersonReportMark[0].facultyID;
		cout<<endl;
		cin.ignore();

		cout << "Enter Student lastName: " << endl;
		getline(cin, PersonReportMark[1].lastName);
		cout << "Enter facultyID: " << endl;
		cin >> PersonReportMark[1].facultyID;
	}

	void putdata()
	{
		int total = 0;
		for (int i = 0; i < 2; i++)
		{
			cout <<"Student lastName: "<< PersonReportMark[i].lastName << endl;
			cout << "Student facultyID: " << PersonReportMark[i].facultyID << endl;
			total += PersonReportMark[i].facultyID;
		}
		cout <<"Total ReportMark: " <<total << endl;
	}
};

//Demostration of Multiple inheritance
//The Lecturer and Supervisor Class redefined the non-virtual member functions of ReportMark: getdata() and putdata() this is called function redefining 
class 
//Lecturer
Lecturer : public Person, public ReportMark


{
public:
	int //StudentID
     StudentID;

	void getdata()
	{
		cout << "Enter the Lecturer lastName: ";
		getline(cin, lastName);
		cout << "Enter facultyID: ";
		cin >> facultyID;
		cout << "Enter The StudentID: ";
		cin >> StudentID;
		cout << endl;
		cin.ignore();
	}

	void putdata()
	{
		cout << "Lecturer lastName: "<<lastName << endl;
		cout << "Number of StudentID: "<< StudentID << endl;
		cout << "facultyID: "<<facultyID << endl;
		cout << endl;
	}
};

class 
//Supervisor 
Supervisor: public Person, public ReportMark


{
public:
	int //company
    companyNum;

	void getdata()
	{
		cout << "Enter the Supervisor lastName: ";
		getline(cin, lastName);
		cout << "Enter facultyID: ";
		cin >> facultyID;
		cout << "Company Number: ";
		cin >> companyNum;
		cout << endl;
		cin.ignore();
	}

	void putdata()
	{
		cout << "Supervisor lastName: " << lastName<<endl;
		cout << "Company Number " << companyNum<<endl;
		cout << "facultyID: " << facultyID<< endl; 
		cout << endl;
	}
};

int main()
{

	Lecturer b;
	Supervisor d;

	b.getdata();
	d.getdata();

	b.putdata();
	d.putdata();


	ReportMark s;
	s.getdata();
	s.putdata();

	return 0;
}
