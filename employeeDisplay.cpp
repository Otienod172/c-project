

#include "EmployeeActions.cpp"

using namespace std;

class EmployeeDisplay : public EmployeeActions{
    public:
        int action;
        string accountNumber;
        void displayEmployeeActions();


};

void EmployeeDisplay::displayEmployeeActions(){
    EmployeeActions empAction;
    empAction.readFile();
    while(1){

        cout << "P640 Bank Management" << endl;
        cout << "====================\n" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Update account details" << endl;
        cout << "3. Close account" << endl;
        cout << "4. Search account detail" << endl;
        cout << "5. List accounts" << endl;
        cout << "6. Check employee schedule" << endl;
        cout << "7. Exit" << endl;
        cin >> action;
        switch(action){
            case 1:
                system("CLS");
                empAction.createAccount();
                break;
            case 2:
                system("CLS");
                cin.ignore();
                cout << "Enter account ID to update: ";
                getline(cin,accountNumber);

                empAction.updateAccount(accountNumber);
                break;
            case 3:
                system("CLS");
                cin.ignore();
                cout << "Enter account ID to close: ";
                getline(cin,accountNumber);
                empAction.closeAccount(accountNumber);
                break;
            case 4:
                system("CLS");
                cin.ignore();
                cout << "Enter account ID to search for: ";
                getline(cin,accountNumber);
                empAction.searchAccount(accountNumber);
                break;
            case 5:
                system("CLS");

                empAction.listAccounts();
                break;
            case 6:
                break;

            case 7:
                empAction.writeFile();
                //main();
                exit(1);


        }

    }
}



