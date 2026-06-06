#include "DatabaseManager.h"
#include <iostream>

using namespace std;

int main() {
    DatabaseManager db;
    int optionChoice;

    while (true) {
        cout << "\n=== EDUTRACK: REGISTRY SYSTEM ===" << endl;
        cout << "1. Create Student Performance Profile Record" << endl;
        cout << "2. Render Evaluated Class Ledger Reports" << endl;
        cout << "3. Close System Session Pipeline" << endl;
        cout << "Action Target Input Option: ";
        cin >> optionChoice;

        if (optionChoice == 1) {
            string uid, fullName;
            float cgpaScore;
            int currentAttendance;

            cout << "Enter Identification String UID: "; cin >> uid;
            cout << "Enter Legal Identity Name: "; cin.ignore(); getline(cin, fullName);
            cout << "Enter Metric CGPA Float Value: "; cin >> cgpaScore;
            cout << "Enter Total Attendance Integer %: "; cin >> currentAttendance;

            Student freshStudent(uid, fullName, cgpaScore, currentAttendance);
            db.appendRecord(freshStudent);
        } 
        else if (optionChoice == 2) {
            db.printAllRecords();
        } 
        else if (optionChoice == 3) {
            cout << "\n[System Status] Closing database interface tracking lines safely. Session Terminated.\n" << endl;
            break;
        } 
        else {
            cout << "\n[SYSTEM ERROR] Irregular operation code path selection flag.\n" << endl;
        }
    }
    return 0;
}