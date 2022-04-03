#include<string>
#include<iostream>

#include "Login.cpp"

using namespace std;

class EmployeeLogin: public Login {
private:

public:
    EmployeeLogin(string, int);
    void validateLogin();
};

EmployeeLogin::EmployeeLogin(string role, int id) : Login(role, id) {

}

void EmployeeLogin::validateLogin() {
    Login::validateLogin();
    cout << "Welcome, our bank Employee!" << endl;
}
