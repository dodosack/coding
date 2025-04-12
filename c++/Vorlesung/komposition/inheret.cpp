#include<iostream>
using namespace std;
class Class_1 {
public:
int get_id() {return 1;}
};
class Class_2: private Class_1 {
};
class Class_3: public Class_2 {
public:
int get_inherited_id(){
// return get_id(); // Fehler!
}
};

int main() {
Class_1 o_1;
cout << o_1.get_id() << endl;
Class_2 o_2;
cout << o_2.get_id() << endl; // Fehler!
Class_3 o_3;
cout << o_3.get_inherited_id() << endl;
return 0;}