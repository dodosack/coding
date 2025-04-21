#include <iostream>
using namespace std;
#include "Worker.h"
/* HIER */

Worker::Worker(const string f_n, const string l_n, double h_e, double h)
    : Employee(f_n, l_n), _hourly_earnings(h_e), _hours(h)
      {
    /* HIER */}
double Worker::get_income() const {
    double earnings = _hourly_earnings * _hours;
    return earnings;
    /* HIER */


    }

void Worker::print() const {
    cout << "Worker: ";
    Employee::print();
}