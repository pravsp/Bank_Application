#include<iostream>
#include "include/address.h"

using namespace std;

namespace banking_lib {
    Address::Address() {
        this->collect_address();
    }

    Address::Address(string street_addr, string city, string state,
                     string country, string zipcode) {
        this->street_address = street_addr;
        this->city = city;
        this->state = state;
        this->country = country;
        this->zipcode = zipcode;

    }

    void Address::collect_address(){
        cout << "Enter street address:";
        cin >> this->street_address;
        cout << "Enter City:";
        cin >> this->city;
        cout << "Enter state:";
        cin >> this->state;
        cout << "Enter country:";
        cin >> this->country;
        cout << "Enter zipcode:";
        cin >> this->zipcode;

    }

    string Address::get_address(){
        string addr;
        addr = addr + this->street_address + "\n";
        addr = addr + this->city + "\n";
        addr = addr + this->state + "\n";
        addr = addr + this->country + "\n";
        addr = addr + this->zipcode;

        return addr;

    }


}