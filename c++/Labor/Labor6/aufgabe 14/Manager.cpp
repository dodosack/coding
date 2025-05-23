#include "Manager.h"

Manager::Manager(const string& f_n, const string& l_n, double s)
    : Employee(f_n, l_n), _salary(s) {}

double Manager::get_income() const {
    return _salary;
}

void Manager::print() const {
    cout << "Manager: ";
    Employee::print();
}
