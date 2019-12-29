#include<iostream>
#include<map>
#include "include/address.h"
//#include "json/json.h"

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
    /*
    Address* Address::get_address_from_json_obj(Json::Value addr_jsn_obj){
        auto st_addr = addr_jsn_obj["Street"];
        auto city = addr_jsn_obj["City"];
        auto state = addr_jsn_obj["State"];
        auto country = addr_jsn_obj["Country"];
        auto z_code = addr_jsn_obj["Zipcode"];

        cout << "street_address: "<<st_addr<<endl;
        cout << "city: "<<city<<endl;
        cout << "state: "<<state<<endl;
        cout << "country: "<<country<<endl;
        cout << "zip_code: "<<z_code<<endl;

        return new Address(st_addr.asString(), city.asString(), state.asString(), country.asString(), z_code.asString());
    }
    */
    Address* Address::get_address_from_map(map<string,string> json_map){
        
        auto st_addr = json_map["Street"];
        auto city = json_map["City"];
        auto state = json_map["State"];
        auto country = json_map["Country"];
        auto z_code = json_map["Zipcode"];

        cout << "street_address: "<<st_addr<<endl;
        cout << "city: "<<city<<endl;
        cout << "state: "<<state<<endl;
        cout << "country: "<<country<<endl;
        cout << "zip_code: "<<z_code<<endl;
        return new Address(st_addr, city, state, country, z_code);
        
    }


}