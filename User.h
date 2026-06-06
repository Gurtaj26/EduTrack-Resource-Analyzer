#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
protected:
    string id;
    string name;

public:
    User(string id, string name) : id(id), name(name) {}
    virtual ~User() {} 

    virtual void displayProfile() = 0; // Pure Virtual Function implementing Polymorphism
    
    string getId() { return id; }
    string getName() { return name; }
};

#endif