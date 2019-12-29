#include<iostream>
#include<map>
#include<iterator>
#include "include/bank.h"
#include "json_util.h"
#include "employee.h"


using namespace std;
using namespace banking_lib_utilities;
namespace banking_lib {
    Bank::Bank(string name, string branch, Address* addr){
        this->name = name;
        this->addr = addr;
        this->branch = branch;
    }

    bool Bank::add_customer(string cust_id, Customer* cust_details){
        Customer* existing_cust = this->get_customer_details(cust_id);
        if (existing_cust == NULL) {
            // New customer found add an entry
            this->customers.insert(make_pair(cust_id, cust_details));

        } else {
            cout<<"customer already exists"<<endl;

        }
        return true;
    }
    Customer* Bank::get_customer_details(string cust_id){
        auto itr = this->customers.find(cust_id);
        if (itr == this->customers.end()){
            return NULL;
        }
        return itr->second;
        
    }
    bool Bank::add_account(int acct_no, Account* acct){
        return true;

    }
    bool Bank::map_cust_id_to_account(string cus_id, Account* acct_details){
        return true;
    }

    Bank::~Bank(){
        if (this->addr != NULL){
            delete this->addr;
        } else {
            cout << "Bank destructor with Null address"<<endl;
        }
    }
    Bank* Bank::start_bank_operations(string cfg_file){
        //cfg_file is expected to be the absolute path of config file
        JsonUtil jsn_utl = JsonUtil(cfg_file);
        auto jsn_obj = jsn_utl.readFromJson();
        auto bank_name = jsn_obj["BankName"];
        auto bank_branch = jsn_obj["BankBranch"];
        auto addr = jsn_obj["Address"];
        cout << "bank_name: "<<bank_name<<endl;
        cout << "bank_branch_name: "<<bank_branch<<endl;
        //cout << "bank_address: "<<addr<<endl;
        //cout << addr.isString() << endl;
        auto addr_obj = Address::get_address_from_map(JsonUtil::convertJsontoStringMap(addr));
        auto bank_obj = new Bank(bank_name.asString(), bank_branch.asString(), addr_obj);
        Employee::create_uid_pool();
        return bank_obj;
    }
    void Bank::set_bank_config(string cfg_file){
        this->cfg_file = cfg_file;
    }
}