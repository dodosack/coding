#include <iostream>
#include <string>
using namespace std;

int main(){
    string eingabe;
    cin >> eingabe;

    // string s = "Adam";
    string s = "My name is ";
    // cout << s.length(); //11 ist die länge

    s.insert(11, eingabe);
    // cout << (s =="Adam") ;
    // s.insert(10, " APPEEND");

    // int pos;
    // pos = s.find("ist");
    // cout << s.length()<<endl;
    // cout << pos << endl;

    // cout << s;


    string::iterator i;
    for ( i = s.begin(); i < s.end(); i++)
    {
        std ::cout << *i;
    }
    cout << endl;
    return 0;
}
