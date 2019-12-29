#ifndef __CUSTOMER_H
#define __CUSTOMER_H
#include<iostream>
#include<map>
#include "person.h"
#include "account.h"

using namespace std;

namespace banking_lib {
    class Account;
    class Customer: public Person {
        private:

        string cus_id;
        Person cus_details;
        map<int, Account*> account_details;

        public:

        Customer();
        void generate_customer_id();

        void add_account_to_customer(Account acct);

        bool withdraw_cash(int acct_no, float amount);

        bool deposit_cash(int acct_no, float amount);

        bool transer_money(int acct_no, float amount);

    };
}

#endif //__CUSTOMER_H