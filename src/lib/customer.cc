#include "customer.h"
#include<iostream>

using namespace std;

namespace banking_lib {
    Customer::Customer() : Person(){
        this->generate_customer_id();

    }

    void Customer::generate_customer_id() {

    }

    void Customer::add_account_to_customer(Account acct) {
        
    }

    bool Customer::withdraw_cash(int acct_no, float amount) {
        return true;

    }

    bool Customer::deposit_cash(int acct_no, float amount) {
        return true;

    }

    bool Customer::transer_money(int acct_no, float amount){
        return true;

    }
}