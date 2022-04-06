#pragma once

#ifndef LOGIN_H
#define LOGIN_H

#include <string>
#include <iostream>

using namespace std;

class Login {
template <class T>
friend void displayUserInfo(T user);
private:
    string role;
    int id;
    bool loginSuccess = false;
public:
    Login(string, int);
    void validateLogin();
};

//template must be defined in header file
template <class T>
void displayUserInfo(T user) {
    cout << "User Role: " << user.role << endl;
    cout << "User ID: " << user.id << endl;
}

#endif