#pragma once

#ifndef EMPLOYEEACTIONS_H
#define EMPLOYEEACTIONS_H

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <iomanip>

using namespace std;

const int maxEntries = 10;

class EmployeeActions {
friend ostream& operator<<(ostream&, EmployeeActions);
private:
    string line;
protected:
    int savingsAccNo = 1000;
    int fixedDepAccNo = 3000;

    string accountNumber[maxEntries] = {};
    string accountType[maxEntries] = {};
    string firstName[maxEntries] = {};
    string lastName[maxEntries] = {};
    string phoneNumber[maxEntries] = {};
    string balance[maxEntries] = {};
public:
    void readFile();
    void writeFile();
    void listAccounts();
    void createAccount();
    void searchAccount(string);
    void updateAccount(string);
    void closeAccount(string);
    void viewFile(string);
};

#endif