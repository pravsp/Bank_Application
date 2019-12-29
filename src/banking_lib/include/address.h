#ifndef ADDRESS_H
#define ADDRESS_H
#include<iostream>
#include<map>
//#include "json/json.h"

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
        //static Address* get_address_from_json_obj(Json::Value addr_jsn_obj);
        static Address* get_address_from_map(map<string,string> json_map);
    };
}


#endif //ADDRESS_H