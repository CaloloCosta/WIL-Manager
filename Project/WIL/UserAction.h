#include<string>
#include<iostream>
using namespace std;
class UserAction
{
private:
    /* data */
public:
    UserAction(/* args */);

    static string addNotice(string from, string who){
        string topic, notice;
        cout<<"Notice Topic: ";
        getline(cin,topic);
        cout <<"Notice Message: ";
        getline(cin,notice);

        string fNotice = topic +"("+from+" - "+who+")"+"," + notice + "\n"; 

        return fNotice;
    }

};
