#pragma once

#ifndef EMPLOYEELOGIN_H
#define EMPLOYEELOGIN_H

#include <string>
#include <iostream>

#include "Login.h"

using namespace std;

class EmployeeLogin: public Login {
public:
    EmployeeLogin(string, int);
    void validateLogin();
};

#endif