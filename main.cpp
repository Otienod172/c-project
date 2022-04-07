#include <string>
#include <iostream>

#include "Login.h"
#include "EmployeeLogin.h"
#include "ManagerLogin.h"
#include "EmployeeDisplay.h"
#include "EmployeeActions.h"
#include "ManagerDisplay.h"
#include "ManagerActions.h"

using namespace std;

int main() {
    EmployeeLogin employee("employee", 1234);
    ManagerLogin manager("manager", 5678);
    EmployeeDisplay empChoices;
    ManagerDisplay manaChoices;
    int choice;
    int retry;

    cout << " 1. Employee Login" << endl;
    cout << " 2. Manager Login" << endl;
    cout << " 3. Exit" << endl;

    cin >> choice;
    switch (choice) {
    case 1:
        try {
            employee.validateLogin();
            cin.ignore();
            system("CLS");
            displayUserInfo(employee);
            empChoices.displayEmployeeActions(); // call the employee display
        }
        catch (const string msg) {
            cout << msg << endl;
            cin >> retry;
            switch (retry) {
            case 1:
                cout << "Try again!" << endl;
                system("pause");
                system("CLS");
                main();
            case 2:
                exit(0);
            }
        }
        break;
    case 2:
        try {
            manager.validateLogin();
            cin.ignore();
            system("CLS");
            displayUserInfo(manager);
            manaChoices.displayManagerActions();
        }
        catch (const string msg) {
            cout << msg << endl;
            cin >> retry;
            switch (retry) {
            case 1:
                cout << "Try again!" << endl;
                system("pause");
                system("CLS");
                main();
            case 2:
                exit(0);
            }
        }
        break;
    case 3:
        exit(0);
    }
    return 0;
}