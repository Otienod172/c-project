#include<string>
#include<iostream>

#include "Login.cpp"

using namespace std;

class ManagerLogin: public Login {
private:

public:
    ManagerLogin(string, int);
    void ValidateLogin();
};

ManagerLogin:: ManagerLogin(string role, int id) : Login(role, id) {

}

void ManagerLogin:: ValidateLogin() {
    Login:: validateLogin();
    cout << "Welcome, our bank Manager!" << endl;
    system("pause");
    system("CLS");


}
