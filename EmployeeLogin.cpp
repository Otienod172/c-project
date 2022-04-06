#ifndef EMPLOYEELOGIN_CPP
#define EMPLOYEELOGIN_CPP

#include "EmployeeLogin.h"

EmployeeLogin:: EmployeeLogin(string role, int id): Login(role, id) {

}

void EmployeeLogin:: validateLogin() {
    Login:: validateLogin();
    cout << "Welcome, our bank Employee!" << endl;
}

#endif
