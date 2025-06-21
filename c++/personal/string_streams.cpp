#include <iostream>
#include <sstream>
// #include <vcruntime_typeinfo.h>


using namespace std;
int main() {
    string f;
    int    date;
    char sep;
cin >> f;
stringstream ss(f);
ss>>date>> sep;
 cout<< date <<endl;

    stringstream s;
    s << "ich bin " << 19 << " Jahre alt";
    cout << s.str();
    
}