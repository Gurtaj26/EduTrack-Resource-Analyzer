#ifndef DATABASE_MANAGER_H
#define DATABASE_MANAGER_H

#include "Student.h"
#include <fstream>
#include <vector>

class DatabaseManager {
private:
    const string filename = "student_records.dat";

public:
    void appendRecord(Student& std) {
        // .c_str() translates the string path cleanly for the file system
        ofstream outFile(filename.c_str(), ios::app); 
        if (outFile.is_open()) {
            // FIXED: Changed std::getName() to std.getName()
            outFile << std.getId() << "," 
                    << std.getName() << "," 
                    << std::fixed << std::setprecision(2) << std.getCgpa() << "," 
                    << std::to_string(std.getAttendance()) << "\n";
            outFile.close();
            cout << "\n[SUCCESS] Record safely synchronized with local storage disk.\n";
        } else {
            cout << "\n[ERROR] Fail safe error: Core write buffer stream inaccessible.\n";
        }
    }

    void printAllRecords() {
        ifstream inFile(filename.c_str());
        if (!inFile.is_open()) {
            cout << "\n[SYSTEM NOTICE] DB Registry not discovered. Creating fresh schema...\n";
            return;
        }

        cout << "\n------------------------------------------------------------\n";
        cout << left << setw(10) << "ID" << setw(25) << "Full Name" << setw(10) << "CGPA" << setw(12) << "Attendance" << endl;
        cout << "------------------------------------------------------------\n";

        string line;
        while (getline(inFile, line)) {
            if(line.empty()) continue;
            
            size_t p1 = line.find(',');
            size_t p2 = line.find(',', p1 + 1);
            size_t p3 = line.find(',', p2 + 1);

            string id = line.substr(0, p1);
            string name = line.substr(p1 + 1, p2 - p1 - 1);
            float cgpa = stof(line.substr(p2 + 1, p3 - p2 - 1));
            int attendance = stoi(line.substr(p3 + 1));

            Student temp(id, name, cgpa, attendance);
            temp.displayProfile();
        }
        cout << "------------------------------------------------------------\n";
        inFile.close();
    }
};

#endif