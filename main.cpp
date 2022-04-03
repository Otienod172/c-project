#include<string>
#include<iostream>

#include "Login.cpp"
#include "EmployeeLogin.cpp"
#include "ManagerLogin.cpp"
#include "EmployeeDisplay.cpp"
#include "EmployeeActions.cpp"

using namespace std;

int main() {
    EmployeeLogin employee("employee", 1234);
    ManagerLogin manager("manager", 5678);
    EmployeeDisplay empChoices;
    int choice;
    int retry;
    cout << " 1. Employee Login" << endl;
    cout << " 2. Manager Login" << endl;
    cout << " 3. Exit" << endl;
    //cin.ignore();
    cin >> choice;
    switch (choice) {
    case 1:
        try {
            employee.validateLogin();
        }
        catch(const string msg) {
            cout << msg << endl;
            cin >> retry;
            switch (retry) {
            case 1:
                cout << "Try again!" << endl;
                main();
            case 2:
                exit(0);
            }
        }
        //employee.validateLogin();
        // system("pause");
        cin.ignore();
        //system("CLS");
        empChoices.displayEmployeeActions(); // call the employee display
        //main();
        break;
    case 2:
        manager.validateLogin();
        cin.ignore();
        system("CLS");
        //managerdisplayscreen.displayManagerMenu();
        //main();
        break;
    case 3:
        exit(0);

    }
    return 0;
}