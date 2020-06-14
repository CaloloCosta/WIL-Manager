#include<string>
#include<fstream>
#include<iostream>
#include<vector>
#include <sstream>
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
        fout.open(filename,ios::out | ios::app);

        fout << data;
    }

    // list al the data
    static void read(string filename){
        cout << "read";
        fstream fin;
        fin.open(filename,ios::in);
        vector<string> row;
        string line, word, temp;
        while(fin >> temp){
           row.clear();
           getline(fin,line);
           std::stringstream s(line);

           while(getline(s, word,',')){
               row.push_back(word);
               cout << "is it in\n"<<endl;
           }
           cout << row[0];
        }
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
    }

};
