#ifndef BANK_H
#define BANK_H
#include<iostream>
#include <map>
#include <list>
#include "address.h"
#include "customer.h"
#include "account.h"


using namespace std;
namespace banking_lib {
    class Bank{
        
        string cfg_file;
        string name;
        string branch;
        Address* addr;
        map<string, Customer*> customers;
        map<int, Account*> accounts;
        map<string, list<Account*>> cid_account_mapping;

        public:
        Bank(string name, string branch, Address* addr);
        ~Bank();
        bool add_customer(string cust_id, Customer* cust_details);
        bool add_account(int acct_no, Account* acct);
        bool map_cust_id_to_account(string cus_id, Account* acct_details);
        Customer* get_customer_details(string cust_id);
        void set_bank_config(string cfg_file);
        static Bank* start_bank_operations(string cfg_file);
    };
}
#endif //BANK_H