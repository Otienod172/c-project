#include<string>
#include<iostream>

#include "Login.cpp"
#include "EmployeeLogin.cpp"
#include "ManagerLogin.cpp"

using namespace std;

int main() {
    EmployeeLogin employee("employee", 1234);
    ManagerLogin manager("manager", 5678);
    int choice;
    cout << " 1. Employee Login" << endl;
    cout << " 2. Manager Login" << endl;
    cout << " 3. Exit" << endl;

    cin >> choice;
    switch (choice) {
    case 1:
        employee.validateLogin();
        // system("pause");
        system("CLS");
        //Employeedisplayscreen.displayEmployeeMenu(); // call the employee display
        //main();
        break;
    case 2:
        manager.validateLogin();
        //system("pause");
        system("CLS");
        //managerdisplayscreen.displayManagerMenu();
        //main();
        break;
    case 3:
        exit(0);

    }
    return 0;
}