#pragma once

#ifndef MANAGERDISPLAY_H
#define MANAGERDISPLAY_H

#include "ManagerActions.h"
#include "EmployeeActions.h"

using namespace std;

class ManagerDisplay: public ManagerActions, public EmployeeActions {
public:
    int action;
    string accountNumber;
    void displayManagerActions();
};

#endif