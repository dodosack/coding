#pragma once

#include "Employee.h"

class Worker : public Employee {
private:
    double _hourly_earnings;
    double _hours;

public:
    Worker(const string& f_n, const string& l_n, double h_e = 0.0, double h = 0.0);
    double get_income() const;
    void print() const override;
};
