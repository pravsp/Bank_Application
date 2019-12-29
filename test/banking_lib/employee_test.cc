#include "gtest/gtest.h"
#include "uid_alphanumeric.h"
#include "json_util.h"
#include "employee.h"

using namespace banking_lib;
using namespace banking_lib_utilities;
using namespace std;

TEST(EmployeeShould, CreateNewUidPool){
    auto employee_pool_created = Employee::create_uid_pool();
    EXPECT_EQ(employee_pool_created, true);
}

TEST(EmployeeShouldNot, CreateSecondUIDPoolWithSameName){
    auto employee_pool_created = Employee::create_uid_pool();
    EXPECT_EQ(employee_pool_created, true);

    employee_pool_created = Employee::create_uid_pool();
    EXPECT_EQ(employee_pool_created, true);

    auto pool_list = UIDAlphaNumeric::get_available_uid_pool();
    cout<<"List of aphanumeric pools available:"<<endl;
    for (auto v : pool_list)
        cout << v << "\n";
    
    auto emp_pool_name = Employee::get_uid_pool_name();
    EXPECT_EQ(count(pool_list.begin(), pool_list.end(), emp_pool_name), 1);
}

TEST(EmployeeShould, ReturnListOfEmployees){
    auto employee_pool_created = Employee::create_uid_pool();
    EXPECT_EQ(employee_pool_created, true);
    string cfg_file = "config/ABC_bank_hrbr_employees.json";
    auto emp_l = Employee::load_employees_from_config(cfg_file);
    EXPECT_EQ(emp_l.empty(),true);
}

TEST(EmployeeShould, CreateNewEmployee){
    auto employee_pool_created = Employee::create_uid_pool();
    EXPECT_EQ(employee_pool_created, true);

    auto emp = new Employee();
}

TEST(EmployeeShould, WriteListOfEmployeesToJson){
    auto employee_pool_created = Employee::create_uid_pool();
    EXPECT_EQ(employee_pool_created, true);
    /*
    list<Employee*> my_employee;
    for (auto i = 0; i < 10; i++){
        auto emp = new Employee();
        my_employee.push_back(emp);
    }
    */
    
    auto my_employee = Employee::load_employees_from_config("config/test_employees.json");
    EXPECT_EQ(my_employee.size(), 2);
    Json::Value emp_json;
    emp_json["employees"] = JsonUtil::convertObjectListToJson<Employee>(my_employee, Employee::convertInstanceToJson);
    cout << emp_json << endl;
    
    string cfg_file = "config/ABC_bank_hrbr_employees.json";
    auto json_utl = JsonUtil(cfg_file);
    json_utl.writeToJson(emp_json);
}
