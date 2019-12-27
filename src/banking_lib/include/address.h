#ifndef ADDRESS_H
#define ADDRESS_H
#include<iostream>

using namespace std;

namespace banking_lib {
    class Address {
        //Access Specifier
        public:
        string street_address;
        string city;
        string state;
        string country;
        string zipcode;

        Address() ;
        Address(string street_addr, string city, string state,
                string country, string zipcode);
        void collect_address();
        string get_address();
    };
}


#endif //ADDRESS_H