#include<iostream>
#include<map>
#include<iterator>
#include "include/bank.h"


using namespace std;

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
}