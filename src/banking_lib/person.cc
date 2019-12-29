#include<iostream>
#include "include/person.h"
#include "address.h"
#include "json_util.h"
#include "json/json.h"

using namespace std;
using namespace banking_lib_utilities;
namespace banking_lib {
    Person::Person(){
        this->collect_person_details();
    }
    Person::Person(Json::Value details){
        this->name = details["Name"].asString();
        this->email = details["E-mail"].asString();
        this->phone = details["Phone"].asString();
        //auto address = details["Address"];
        //this->addr = Address::get_address_from_map(JsonUtil::convertJsontoStringMap(details["Address"]));
        this->addr =  Address::get_address_from_json_obj(details["Address"]);
    }
    Person::Person(string name, string email, string phone, Address *addr){
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
        this->addr = new Address();
    }
    bool Person::deposit_money(){
        return true;
    }
    Json::Value Person::convertPersonDetailsToJson(Person* inst){
        Json::Value root;
        cout<<"Converting Person with name: "<<inst->name<<" to JSON\n";
        root["Name"] = inst->name;
        root["E-mail"] = inst->email;
        root["Phone"] = inst->phone;
        root["Address"] = Address::ConvertAddressToJson(inst->addr);
        return root;
    }
}