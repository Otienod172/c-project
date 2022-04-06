
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
        system("CLS");
        cout << "P640 Bank Management" << endl;
        cout << "====================" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Update account details" << endl;
        cout << "3. Close account" << endl;
        cout << "4. Search account detail" << endl;
        cout << "5. List accounts" << endl;
        cout << "6. Check employee schedule" << endl;
        cout << "7. Exit" << endl;
        cin >> action;
        switch(action){
            case 1: // account creation
                system("CLS");
                cin.ignore();
                empAction.createAccount();
                break;
            case 2: // account update
                system("CLS");
                cin.ignore();
                cout << "Enter account ID to update: ";
                getline(cin,accountNumber);

                empAction.updateAccount(accountNumber);
                break;
            case 3: // account deletion
                system("CLS");
                cin.ignore();
                cout << "Enter account ID to close: ";
                getline(cin,accountNumber);
                empAction.closeAccount(accountNumber);
                break;
            case 4: // account searching
                system("CLS");
                cin.ignore();
                cout << "Enter account ID to search for: ";
                getline(cin,accountNumber);
                empAction.searchAccount(accountNumber);
                break;
            case 5: // list all accounts
                //system("CLS");
                cin.ignore();
                empAction.listAccounts();
                break;
            case 6: // view timetable
                empAction.viewFile("timetable.txt");
                break;

            case 7: // exit
                empAction.writeFile();
                //main();
                exit(1);


        }

    }
}



