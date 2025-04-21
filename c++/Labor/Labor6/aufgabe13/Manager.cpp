#include <iostream>
using namespace std;

/* HIER */
#include "Manager.h"
// #include "Employee.h" ist schon in maneger.h


Manager::Manager(const string f_n, const string l_n, double s = 0)
    : Employee(f_n, l_n), _salary(s) {}
// salary mit initalisierungsliste


double Manager::get_income() const {
    return _salary;
}

void Manager::print() const {
    cout << "Manager: ";
    Employee::print();
}