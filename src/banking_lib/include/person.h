#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include "address.h"
#include "json/json.h"

using namespace std;

namespace banking_lib{
    class Person{
        string name;
        string email;
        string phone;
        Address *addr;
        
        protected:
        Person(Json::Value details);

        public:
        Person();
        Person(string name, string email, string phone, Address* addr);
        void collect_person_details();
        bool deposit_money();
        static Json::Value convertPersonDetailsToJson(Person* inst);
    };
}


#endif //PERSON_H