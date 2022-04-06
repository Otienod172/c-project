#include "ManagerActions.cpp"

using namespace std;

class ManagerDisplay: public ManagerActions, public EmployeeActions{
    public:
        int action;
        string accountNumber;
        void displayManagerActions();
};

void ManagerDisplay::displayManagerActions(){
    EmployeeActions empAction;
    empAction.readFile();
    while(1){

        cout << "P640 Manager Bank Management" << endl;
        cout << "============================\n" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Update account details" << endl;
        cout << "3. Close account" << endl;
        cout << "4. Search account detail" << endl;
        cout << "5. List accounts" << endl;
        cout << "6. Set employee timetable" << endl;
        cout << "7. Check employee timetable" << endl;
        cout << "8. Exit" << endl;
        cin >> action;
        switch(action){
            case 1:
                //system("CLS");
                empAction.createAccount();
                break;
            case 2:
                //system("CLS");
                cin.ignore();
                cout << "Enter account ID to update: ";
                getline(cin,accountNumber);

                empAction.updateAccount(accountNumber);
                break;
            case 3:
                //system("CLS");
                cin.ignore();
                cout << "Enter account ID to close: ";
                getline(cin,accountNumber);
                empAction.closeAccount(accountNumber);
                break;
            case 4:
                //system("CLS");
                cin.ignore();
                cout << "Enter account ID to search for: ";
                getline(cin,accountNumber);
                empAction.searchAccount(accountNumber);
                break;
            case 5:
                //system("CLS");

                empAction.listAccounts();
                break;
            case 6:
                setEmployeeTimetable();
                break;

            case 7:
                empAction.viewFile("timetable.txt");
                break;

            case 8:
                empAction.writeFile();
                cout << "Exiting..." << endl;
                system("pause");
                //system("CLS");
                //main();
                exit(1);
                break;


        }

    }
}
