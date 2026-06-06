#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include <iostream>
#include <iomanip>

class Student : public User {
private:
    float cgpa;
    int attendance;

public:
    Student(string id, string name, float cgpa, int attendance) 
        : User(id, name), cgpa(cgpa), attendance(attendance) {}

    float getCgpa() { return cgpa; }
    int getAttendance() { return attendance; }

    void displayProfile() override {
        cout << left << setw(10) << id 
             << setw(25) << name 
             << setw(10) << fixed << setprecision(2) << cgpa 
             << setw(12) << to_string(attendance) + "%" << endl;
    }
};

#endif