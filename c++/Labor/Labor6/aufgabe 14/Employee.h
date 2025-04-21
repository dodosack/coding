#pragma once

#include <string>
#include <iostream>

using namespace std;

class Employee {
protected:
    string _first_name;
    string _last_name;

public:
    Employee(const string& f_n, const string& l_n);
    virtual void print() const;
    virtual ~Employee() = default;
};
