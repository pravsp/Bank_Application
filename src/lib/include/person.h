#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include "address.h"

using namespace std;

namespace banking_lib{
    class Person{
        public:

        string name;
        string email;
        string phone;
        Address addr;


        bool deposit_money();
    }
}


#endif //PERSON_H