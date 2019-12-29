#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H
#include<iostream>
#include<list>
#include "person.h"
#include "json/json.h"
using namespace std;
namespace banking_lib{
    class Employee: public Person {
        private:

        string emp_id;
        Person emp_details;
        static const string uid_pool;
        Employee(string emp_id, Json::Value person_details);

        public:
        Employee();
        
        void generate_employee_id();
        static bool create_uid_pool();
        static Employee* get_employee_from_json(Json::Value root);
        static string get_uid_pool_name();
        static list<Employee*> load_employees_from_config(string employees_cfg_file);
        static Json::Value convertInstanceToJson(Employee* inst);

    };
}

#endif //__EMPLOYEE_H