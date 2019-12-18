#ifndef ACCOUNT_H
#define ACCOUNT_H
#include<iostream>
#include<map>
#include "account_type.h"
#include "transaction.h"

using namespace std;

namespace banking_lib {
    class Account{
        private:
        int account_number;
        float balance;
        enum account_type type;
        string primary_cust_id;
        map<int, Transaction> transac_list;
        map<string, Customer> account_holders;

        public:

        Account();
        int generate_account_number();
        float get_balance();
        string get_statement();
        bool transact();
        bool add_account_holder();
        

    }
}

#endif //ACCOUNT_H