#pragma once

#ifndef MANAGERLOGIN_H
#define MANAGERLOGIN_H

#include<string>
#include<iostream>

#include "Login.h"

using namespace std;

class ManagerLogin: public Login {
public:
    ManagerLogin(string, int);
    void validateLogin();
};

#endif