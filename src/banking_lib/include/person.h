#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include "address.h"

using namespace std;

namespace banking_lib{
    class Person{
        string name;
        string email;
        string phone;
        Address addr;

        public:
        Person();
        Person(string name, string email, string phone, Address addr);
        void collect_person_details();
        bool deposit_money();
    };
}


#endif //PERSON_H