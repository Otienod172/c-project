#include<string>
#include<iostream>

#include "Login.cpp"

using namespace std;

class EmployeeLogin: public Login {
private:

public:
    EmployeeLogin(string, int);
    void ValidateLogin();
};

EmployeeLogin::EmployeeLogin(string role, int id) : Login(role, id) {

}

void EmployeeLogin::ValidateLogin() {
    Login::validateLogin();

    cout << "Welcome, our bank Employee!" << endl;
    system("pause");
    system("CLS");
}
