#include <iostream>
#include <string>
using namespace std;
class One {
public:
 virtual void method_1() { cout << "One::method_1()->"; }
 void method_1(int i) { cout << "One::method_1(" << i << ")->"; }
 void method_2() { cout << "One::method_2()" << endl; }
 void method_2() const { cout << "One::method_2() const" << endl; }
 void method_3() {
 method_1(); method_1(1); method_2();
 }
 void method_3() const { method_2(); }
};
class Two : public One {
public:
 void method_1() override { cout << "Two::method_1()->"; }
 void method_1(int i) { cout << "Two::method_1(" << i << ")->"; }
 virtual void method_2() const { cout << "Two::method_2() const" << endl; }
 void method_3() {
 method_1(); method_1(2); method_2();
 }
 void method_3() const { method_2(); }
};
class Three : public Two
{
public:
 void method_1() override { cout << "Three::method_1()->"; }
 virtual void method_1(int i) { cout << "Three::method_1(" << i << ")->"; }
 void method_2() { cout << "Three::method_2()" << endl; }
 void method_2() const override { cout << "Three::method_2() const" << endl; }
 void method_3() {
 method_1(); method_1(3); method_2();
 }
 void method_3() const { method_2(); }
};
int main()
{
 Three three;
 One *p_three = &three;
 Two two;
 One *p_two = &two;
 One one;
 One *p_one = &one;
 const Three c_three;
 const Two *c_p_three = &c_three;
 three.method_3();
 two.method_3();
 one.method_3();
 c_three.method_3();
 p_three->method_3();
 p_two->method_3();
 p_one->method_3();
 c_p_three->method_3();
 return 0;
} 