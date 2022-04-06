#ifndef MANAGERLOGIN_CPP
#define MANAGERLOGIN_CPP

#include "ManagerLogin.h"

ManagerLogin:: ManagerLogin(string role, int id): Login(role, id) {

}

void ManagerLogin:: validateLogin() {
    Login:: validateLogin();
    cout << "Welcome, our bank Manager!" << endl;
}

#endif