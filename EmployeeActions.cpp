#ifndef EMPLOYEEACTIONS_CPP
#define EMPLOYEEACTIONS_CPP

#include "EmployeeActions.h"

// read file containing bank account details
void EmployeeActions:: readFile() {
    int i = 0;
    ifstream fileToRead("./accounts.txt");

    if (fileToRead.is_open()) {
        while (getline(fileToRead, line)) {
            stringstream getl(line);
            getline(getl, accountNumber[i], '/');
            getline(getl, accountType[i], '/');
            getline(getl, firstName[i], '/');
            getline(getl, lastName[i], '/');
            getline(getl, phoneNumber[i], '/');
            getline(getl, balance[i], '/');
            i++;
        }
    }
    else{
        cout << "error opening accounts.txt" << endl;
    }
}

// write bank account details into file
void EmployeeActions:: writeFile() {
    int i;
    ofstream fileToWrite;
    fileToWrite.open("./accounts.txt");
    
    for (i = 0; i < maxEntries; i++) {
        if (accountNumber[i] == "\0") {
            break;
        }
        else {
            fileToWrite << accountNumber[i] + "/" + accountType[i] + "/" + firstName[i] + "/" + lastName[i] + "/" + phoneNumber[i] + "/" + balance[i] << endl;
        }
    }
}

// list all bank accounts
void EmployeeActions:: listAccounts() {
    int i;
    int index = 0;

    cout << "All accounts" << endl;
    cout << "============" << endl;
    cout << "No.\t||\tAccount No.\t||\tAccount Type\t||\tFirst name\t||\tLast name\t||\tPhone number\t||\tBalance\t\t||\n" << endl;

    for (i = 0; i < maxEntries; i++) {
        if (accountNumber[i] != "\0") {
            index++;
            cout << index << setw(20) << accountNumber[i] << setw(30) << accountType[i] << setw(20) << firstName[i] << setw(25) << lastName[i] << setw(25) << phoneNumber[i] << setw(20) << balance[i] << endl;
        }
    }
    //if there is no account created at all
    if (index == 0) {
        cout << "No account in database" << endl;
    }
}

//display created account details
ostream& operator<<(ostream& out, EmployeeActions emp) {
    for (int i = 0; i < maxEntries; i++) {
        if (emp.accountNumber[i] == "\0") {
            out << "Your account number is: " << emp.accountNumber[i - 1] << "." << endl;
            out << "Your account type is " << emp.accountType[i - 1] << "." << endl;
            out << "Your name is " << emp.firstName[i - 1] << " " << emp.lastName[i - 1] << "." << endl;
            out << "Your phone number is " << emp.phoneNumber[i - 1] << "." << endl;
            out << "Your account balance is " << emp.balance[i - 1] << " dollars." << endl;
            break;
        }
    }
    return out;
}

// create new bank account
void EmployeeActions:: createAccount() {
    int i;
    char accId[10];
    char fname[10];
    char lname[10];
    char pn[10];
    char bal[10];
    cin.clear();
    cout << "Account creation" << endl;
    cout << "================\n" << endl;
    cout << " 1. Savings account" << endl;
    cout << " 2. Fixed deposit" << endl;
    cout << "\n Which type of bank account do you want to create " << endl;

    cin.ignore();
    cout << "Acc Type: ";
    cin.getline(accId, 10);
    
    cout << "First name: ";
    cin.getline(fname, 10);
    
    cout << "Last name: ";
    cin.getline(lname, 10);

    cout << "Phone Number: ";
    cin.getline(pn, 10);

    cout << "Starting balance: ";
    cin.getline(bal, 10);

    for (i = 0; i < maxEntries; i++) {
        if (accountNumber[i] == "\0") {
            if (accId[0] == '1') {
                accountType[i] = "Savings";
                accountNumber[i] = "S" + to_string(savingsAccNo);
                savingsAccNo++;
            } 
            else {
                accountType[i] = "Fixed deposit";
                accountNumber[i] = "F" + to_string(fixedDepAccNo);
                fixedDepAccNo++;
            }
            firstName[i] = fname;
            lastName[i] = lname;
            phoneNumber[i] = pn;
            balance[i] = bal;
            break;
        }
    }
    cout << "\nAccount created successfully!" <<endl;
    system("pause");
    writeFile();
}

// search for bank account
void EmployeeActions:: searchAccount(string accNo) {
    int i;
    int index = 0;
    //system("CLS");
    cout << "Current Booking" << endl;
    cout << "=================" << endl;
    cout << "||\tNo.\t||\tAccount No.\t||\tAccount Type\t||\tFirst name\t||\tLast name\t||\tPhone number\t||\tBalance\t\t||\n" << endl;

    // interate through file and find acc no that matches
    for (i = 0; i < maxEntries; i++) {
        if (accountNumber[i] == accNo) {
            index++;
            cout << index << setw(20) << accountNumber[i] << setw(30) << accountType[i] << setw(20) << firstName[i] << setw(25) << lastName[i] << setw(25) << phoneNumber[i] << setw(20) << balance[i] << endl;
            break;
        }
    }
    // acc dosent exist in database
    if (index == 0) {
        cout << "No account in database" << endl;
    }
    system("pause");
    writeFile();
    //system("CLS");
}

// update bank account details
void EmployeeActions:: updateAccount(string accNo) {
    int i;
    bool accountExist = false;
    char fname[10];
    char lname[10];
    char pn[10];

    for(i = 0; i < maxEntries; i++) {
        if (accountNumber[i] == accNo) {
            accountExist = true;
            cout << "First Name:";
            cin.getline(fname, 10);
            cout << "Last Name:";
            cin.getline(lname, 10);
            cout << "Contact:";
            cin.getline(pn, 10);

            firstName[i] = fname;
            lastName[i] = lname;
            phoneNumber[i] = pn;

            cout << "Account updated" << endl;
            break;
        }
    }
    //no account with the same account number found
    if (accountExist == false) {
        cout << "No account found! Please Try again!" << endl;
    }
}

// delete account entry
void EmployeeActions:: closeAccount(string accNo) {
    int i;
    bool accountExist = false;
    // iterate through file
    for (i = 0; i < maxEntries; i++) {
        // delete if acc found
        if (accountNumber[i] == accNo) {
            accountExist = true;
            accountNumber[i] = "";
            accountType[i] = "";
            firstName[i] = "";
            lastName[i] = "";
            phoneNumber[i] = "";
            balance[i] = "";

            cout << "Account deleted" << endl;
            break;
        }
    }
    //not found in file
    if (accountExist == false) {
        cout << "Account number doesn't exist!" << endl;
    }
}

// read and display file content
void EmployeeActions:: viewFile(string filePath) {
    //system("CLS");
    ifstream openFile(filePath);

    if (openFile.is_open()) {
        while (getline(openFile, line)) {
            cout << line << '\n';
        }
        openFile.close();
    }
    else {
        cout << "Failed to open file" << endl;
    }
    system("pause");
}

#endif