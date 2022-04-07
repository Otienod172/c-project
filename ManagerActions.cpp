#ifndef MANAGERACTIONS_CPP
#define MANAGERACTIONS_CPP

#include "ManagerActions.h"

void ManagerActions:: setEmployeeTimetable() {
    vector <string> weekday, shifts;
    vector <string> employee;
    int i, j;
    int k = 0;
    ofstream timetable;

    cout << "Set Employee's timetable" << endl;
    cout << "========================\n" << endl;

    timetable.open("timetable.txt", ios::in| ios::out| ios::trunc);

    shifts.push_back("Shift 1 - 9AM to 1PM");
    shifts.push_back("Shift 2 - 1PM to 6PM");
    shifts.push_back("Shift 3 - 6PM to 10PM");

    weekday.push_back("Monday Personnel");
    weekday.push_back("Tuesday Personnel");
    weekday.push_back("Wednesday Personnel");
    weekday.push_back("Thursday Personnel");
    weekday.push_back("Friday Personnel");

    timetable << "Employee's timetable" << endl;
    timetable << "====================\n" << endl;

    // insert staff name for the five days
    for (i = 0; i < 5; i++) {
        cout << weekday[i] << endl;
        // Pushback employee name for the 3 shifts
        for (j = 0; j < 3; j ++) {
            cout << shifts[j] << " Employee: ";
            cin >> empName;
            employee.push_back(empName);
        }
        timetable << weekday[i] << endl;
        timetable << "________________________________" << endl;

        //Insert name for the 3 shifts
        for (j = 0; j < 3; j++) {
            timetable << shifts[j] << ": " << employee[k] << endl;
            k++;
        }
        timetable << "________________________________\n" << endl;
    }
    timetable.close();
    system("pause");
    system("CLS");
}

#endif
