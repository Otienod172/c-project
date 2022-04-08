#pragma once

#ifndef EMPLOYEEDISPLAY_H
#define EMPLOYEEDISPLAY_H

#include "EmployeeActions.h"

using namespace std;

class EmployeeDisplay: public EmployeeActions {
public:
    int action;
    string accountNumber;
    void displayEmployeeActions();
};

#endif