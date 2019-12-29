
#include <iostream>
#include <list>
#include "employee.h"
#include "uid_alphanumeric.h"
#include "json_util.h"
#include "json/json.h"

using namespace std;
using namespace banking_lib_utilities;
namespace banking_lib {
    const string Employee::uid_pool = "employees_id";

    Employee::Employee() : Person(){
        this->generate_employee_id();

    }
    Employee::Employee(string emp_id, Json::Value person_details) 
    : Person(person_details) {
        this->emp_id = emp_id;
    }
    void Employee::generate_employee_id(){
        this->emp_id = UIDAlphaNumeric::get_new_uid(Employee::uid_pool);
    }

    bool Employee::create_uid_pool(){
        return UIDAlphaNumeric::create_UIDPool(Employee::uid_pool);
    }
    Employee* Employee::get_employee_from_json(Json::Value root){

        return new Employee(root["Emp_id"].asString(),root["Person_Details"]);
    }

    list<Employee*> Employee::load_employees_from_config(string employees_cfg_file) {
        list<Employee*> employees;
        JsonUtil jsn_utl = JsonUtil(employees_cfg_file);
        auto jsn_obj = jsn_utl.readFromJson()["employees"];
        for (auto itr = jsn_obj.begin(); itr != jsn_obj.end(); itr++){
            employees.push_back(Employee::get_employee_from_json(*itr));
        }
        return employees;
    }
    string Employee::get_uid_pool_name(){
        return Employee::uid_pool;
    }

    Json::Value Employee::convertInstanceToJson(Employee* inst) {
        Json::Value root;
        cout<<"Converting Instance with emp_id: "<<inst->emp_id<<" to JSON\n";
        root["Emp_id"] = inst->emp_id;
        root["Person_Details"] = Person::convertPersonDetailsToJson(inst);

        return root;
    }
}