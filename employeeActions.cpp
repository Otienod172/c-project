#include <iostream>
#include <string>
#include <cstring>
#include<fstream>
#include <stdlib.h>
#include <sstream>

using namespace std;
const int maxEntries = 10;

class EmployeeActions{
    protected:
        int savingsAccNo = 1000;
        int fixedDepAccNo = 3000;

        string accountNumber[maxEntries] = {};
        string accountType[maxEntries] = {};
        string firstName[maxEntries] = {};
        string lastName[maxEntries] = {};
        string phoneNumber[maxEntries] = {};
        string balance[maxEntries] = {};
    public:
        void readFile();
        void writeFile();
        void listAccounts();
        void createAccount();
        void searchAccount(string);
        void updateAccount(string);
        void closeAccount(string);
        void withdrawMoney(string);
        void depositMoney(string);
};


void EmployeeActions::readFile(){
    string line;
    stringstream getl(line);
    int i = 0;

    ifstream fileToRead("./accounts.txt");

    if(fileToRead.is_open()){
        while(getline(fileToRead,line)){
            getline(getl,accountNumber[i],'/');
            getline(getl,accountType[i],'/');
            getline(getl, firstName[i],'/');
            getline(getl,lastName[i],'/');
            getline(getl,phoneNumber[i], '/');
            getline(getl,balance[i], '/');
            i++;
        }
    }
    else{
        cout << "error opening accounts.txt" << endl;
    }

}

void EmployeeActions::writeFile(){
    int i;
    ofstream fileToWrite;
    fileToWrite.open("./accounts.txt");
    for (i = 0; i < maxEntries;i++){
        if (accountNumber[i] == "\0"){
            break;
        }
        else{
            fileToWrite << accountNumber[i] + "/" + accountType[i] + "/" + firstName[i] + "/" + lastName[i] + "/" + phoneNumber[i] + "/" + balance[i] << endl;
        }
    }
}

void EmployeeActions::listAccounts(){
    int i,index = 0;

    cout << "All accounts" << endl;
    cout << "============" << endl;
    cout<<"No.\t||\tAccount No.\t||\tAccount Type\t||\tFirst name\t||\tLast name\t||\tPhone number\t||\tBalance\t||\n" << endl;
    if (index != 0){
        for (i = 0; i < maxEntries; i++){
            if (accountNumber[i] != "\0"){
                index++;
                cout << "\t\t" << index << "\t\t" << accountNumber[i] << "\t\t" << accountType[i] << "\t\t" << firstName[i] << "\t\t" << lastName[i] << "\t\t" << phoneNumber[i] << "\t\t" << balance[i]<< endl;
            }
        }
    }else{
        cout << "No account in database" << endl;
    }
    system("pause");
    system("CLS");
}

void EmployeeActions::createAccount(){
    int i;
    char accId[10];
    char fname[10];
    char lname[10];
    char pn[10];
    char bal[10];
    cin.clear();
    cout << "Account creation" << endl;
    cout << "================\n" << endl;
    cout << " 1. Savings account" << endl;
    cout << " 2. Fixed deposit" << endl;
    cout << "\n Which type of bank account do you want to create " << endl; ;
    cin.ignore();
    cout << "Acc Type:";
    cin.getline(accId,10);

    cout << "First name:";
    cin.getline(fname,10);

    cout << "Last name:";
    cin.getline(lname,10);

    cout << "Phone Number:";
    cin.getline(pn,10);

    cout << "Starting balance:";
    cin.getline(bal,10);

    for (i = 0; i < maxEntries; i++){
        if (accountNumber[i] == "\0"){
            if (accId[0] == '1'){
                accountType[i] = "Savings";
                accountNumber[i] = "S"+to_string(savingsAccNo) ;
                savingsAccNo++;
            }else{
                accountType[i] = "Fixed deposit";
                accountNumber[i] = "F"+to_string(fixedDepAccNo);
                fixedDepAccNo++;
            }
            firstName[i] = fname;
            lastName[i] = lname;
            phoneNumber[i] = pn;
            balance[i] = bal;
            break;
        }
    }
    cout << "\nAccount created" <<endl;
    system("pause");
    writeFile();

}

void EmployeeActions::searchAccount(string accNo){
    int i;
    int index = 0;
    system("CLS");
    cout << "Current Booking" << endl;
    cout << "=================" << endl;
    cout<<"No.\t||\tAccount No.\t||\tAccount Type\t||\tFirst name\t||\tLast name\t||\tPhone number\t||\tBalance\t||\n" << endl;

    // interate through file and find acc no that matches
    for (i = 0; i<maxEntries;i++){
        if (accountNumber[i] == accNo){
            index++;
            cout << "\t\t" << index << "\t\t" << accountNumber[i] << "\t\t" << accountType[i] << "\t\t" << firstName[i] << "\t\t" << lastName[i] << "\t\t" << phoneNumber[i] << "\t\t" << balance[i]<< endl;
            break;
        }
    }
    // acc dosent exist in database
    if (index == 0 ){
        cout << "No account in database" << endl;
    }
    system("pause");
    writeFile();
    system("CLS");
}

void EmployeeActions::updateAccount(string accNo){
    int i;
    int index = 0;
    char fname[10];
    char lname[10];
    char pn[10];

    for(i = 0; i < maxEntries; i++){
        if (accountNumber[i]== accNo){
            index++;
            cout << "First Name:";
            cin.getline(fname,10);
            cout << "Last Name:";
            cin.getline(lname,10);
            cout << "Contact:";
            cin.getline(pn,10);

            firstName[i] = fname;
            lastName[i] = lname;
            phoneNumber[i] = pn;

            cout <<"Account updated" << endl;
            break;
        }
    }
}
void EmployeeActions::closeAccount(string accNo){
    int i;
    int index = 0;
    for (i= 0; i < maxEntries;i++){
        if (accountNumber[i] == accNo){
            index++;

            accountNumber[i] = "";
            accountType[i] = "";
            firstName[i] = "";
            lastName[i] = "";
            phoneNumber[i] = "";
            balance[i] = "";

            cout<<"Account deleted" << endl;
            break;
        }
    }
    //not found in file
    if (index = 0){
        cout<<"Account number does'nt exist!";
    }
}
