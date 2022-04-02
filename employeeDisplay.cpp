

#include "employeeActions.cpp"

using namespace std;

class employeeDisplay : public employeeActions, public basicEmployeeActions {
    public:
        int action;
        string accountNumber;
        void displayEmployeeActions();


}

void employeeDisplay::employeeDisplay(){
    employeeActions empAction;
    empAction.readFile();
}



