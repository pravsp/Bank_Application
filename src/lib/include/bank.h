#ifndef BANK_H
#define BANK_H
#include<iostream>
#include <map>
#include "address.h"
#include "customer.h"
#include "account.h"

using namespace std;
namespace banking_lib {
    class Bank{
        public:
        string name;
        string branch;
        Address addr;
        map<string, Customer*> customers;
        map<int, Account*> accounts;
        map<string, lisz<Account*>> cid_account_mapping;

        Bank(string name, string branch, Address addr);
        bool add_customer(string cust_id, Customer* cust_details);
        bool add_account(int acct_no, Account* acct);
        bool map_cust_id_to_account(string cus_id, Account* acct_details);
        Customer* get_customer_details(string cust_id);
    }
}
#endif //BANK_H