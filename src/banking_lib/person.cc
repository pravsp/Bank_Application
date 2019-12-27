#include<iostream>
#include "include/person.h"

using namespace std;

namespace banking_lib {
    Person::Person(){
        this->collect_person_details();
    }
    Person::Person(string name, string email, string phone, Address addr){
        this->name = name;
        this->email = email;
        this->phone = phone;
        this->addr = addr;
    }
    void Person::collect_person_details(){
        cout << "Enter person name:";
        cin >> this->name;
        cout << "Enter email:";
        cin >> this->email;
        cout << "Enter Phone number:";
        cin >> this->phone;
        this->addr = Address();
    }
    bool Person::deposit_money(){
        return true;
    }
}