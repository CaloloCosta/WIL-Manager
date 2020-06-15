#include<string>
#include<fstream>
#include<iostream>
#include<vector>
#include <sstream>
#include <algorithm>
#include <boost/algorithm/string.hpp>


using namespace std;

class FileHandling
{
private:
    /* data */
public:
    FileHandling(/* args */);

    static void create(string filename, string data){
        fstream fout;
        // oen existing one or creane a new if dont exist
        fout.open(filename,ios::app);

        fout << data;
    }


    static void search(string filename,string uid){
        fstream fin;
        fin.open(filename,ios::in);
        vector<string> row;
        string line, word, temp;
        while(fin >> temp){
            getline(fin,line);
            cout << line;
        }
        fin.close();
    }


    static std::vector<std::vector<std::string> > read(string fileName){
        std::ifstream file(fileName);
    
        std::vector<std::vector<std::string> > dataList;
    
        std::string line = "";
        // Iterate through each line and split the content using delimeter
        while (getline(file, line))
        {
            std::vector<std::string> vec;
            boost::algorithm::split(vec, line, boost::is_any_of(","));
            dataList.push_back(vec);
        }
        // Close the File
        file.close();
    
        return dataList;
    }

    static void printData(std::vector<std::vector<std::string> > dataList, int userType){
        // Print the content of row by row on screen
        if(userType == 1)
            cout << "UserID \t\tFirstname \t\tSurname \t\tEmail \t\tPhone \t\tOffice \t\tVisiting hours"<<endl;
        else
            cout << "St Number \t\tFirstname \t\tSurname \t\tEmail \t\tPhone \t\tSemester \t\trogramme"<<endl;

        for(std::vector<std::string> vec : dataList)
        {   int i = 0;
            for(std::string data : vec)
            {
                if(i != 1)
                    std::cout<<data << "\t\t";
                i++;
            }
            std::cout<<std::endl;
        }
    }

    static void printNotice(std::vector<std::vector<std::string> > dataList){
        // Print the content of row by row on screen
        for(std::vector<std::string> vec : dataList)
        { 
            for(std::string data : vec)
            {
               
                std::cout<<data << "\n";
            }
            std::cout<<std::endl;
        }
    }

    static void search(std::vector<std::vector<std::string> > dataList, string uid, int userType){
        // Print the content of row by row on screen
        if(userType == 1)
            cout << "UserID \t\tFirstname \t\tSurname \t\tEmail \t\tPhone \t\tOffice \t\tVisiting hours"<<endl;
        else
            cout << "St Number \t\tFirstname \t\tSurname \t\tEmail \t\tPhone \t\tSemester \t\trogramme"<<endl;
        for(std::vector<std::string> vec : dataList)
        {   int i = 0;
            if(vec.at(0).compare(uid) == 0){
                for(std::string data : vec)
                {
                    if(i != 1)
                        std::cout<<data << "\t\t";
                    i++;
                }
                std::cout<<std::endl;
            }
            
        }
    }

    // 
    static bool check(std::vector<std::vector<std::string> > dataList, string uid, string pw, int userType){
        bool found = false;
        // Print the content of row by row on screen
        for(std::vector<std::string> vec : dataList)
        {   int i = 0;
            if(vec.at(0).compare(uid) == 0 && vec.at(1).compare(pw) == 0){
                found = true;
            }
            
        }
        return found;
    }
    

};
