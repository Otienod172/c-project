#ifndef LOGIN_CPP
#define LOGIN_CPP

#include "Login.h"

Login:: Login(string role, int id) {
    this-> role = role;
    this-> id = id;
}

void Login:: validateLogin() {
    int ch;
    string inputRole;
    int inputID;
    const string msg = "Login fail. You have keyed in the wrong Role or ID.\nPress 1 to try again or press 2 to exit.";
    cout << " Enter role: ";
    cin >> inputRole;
    cout << " Enter ID: ";
    cin >> inputID;
    cout << endl;
    if (role == inputRole && id == inputID) {
        cout << " You have successfully login! " << endl;
        loginSuccess = true;
    }
    else {
        throw(msg);
    }
}

#endif