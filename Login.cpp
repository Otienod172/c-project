#include<string>
#include<iostream>
#pragma once

using namespace std;

class Login {
private:
    string role;
    int id;
    bool loginSuccess = false;

public:
    Login(string, int);
    void validateLogin();
};

Login::Login(string role, int id) {
    this-> role = role;
    this-> id = id;
}

void Login:: validateLogin() {
    int ch;
    string inputRole;
    int inputID;
    do {
        cout << " Enter role: ";
        cin >> inputRole;
        cout << " Enter ID: ";
        cin >> inputID;
        cout << "\n";

        if (role == inputRole && id == inputID) {
            cout << " You have successfully login! " << endl;
            loginSuccess = true;
        }
        else {
            cout << " Login fail. You have keyed in the wrong Role or ID. " << endl;
            cout << " Press 1 to try again or press 2 to exit. " << endl;
            cin >> ch;
            switch (ch)
            {
            case 1:
                cout << "Try again!" << endl;
                continue;
            case 2:
                exit(0);
            }
        }
    } while (!loginSuccess);
}