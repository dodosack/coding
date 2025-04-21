#pragma once

#include "Employee.h"

class Manager : public Employee {
private:
    double _salary;

public:
    Manager(const string& f_n, const string& l_n, double s = 0);
    double get_income() const;
    void print() const override;
};
