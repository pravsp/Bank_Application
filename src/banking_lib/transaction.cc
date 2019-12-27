#include<iostream>
#include <time.h>
#include "include/transaction.h"


using namespace std;

namespace banking_lib {
    Transaction::Transaction(float amount, float commission,
                             enum transaction_type type,
                             enum transaction_sub_type sub_type,
                             enum transaction_mode mode) {
        time_t now = time(0);
        //Populate transaction time in gmt
        this->transac_time = gmtime(&now);
        this->type = type;
        this->sub_type = sub_type;
        this->mode = mode;
        this->amount = amount;
        this->commission = commission;
    }
    void Transaction::set_status(enum transaction_status status) {
        this->status = status;
    }

    Transaction* Transaction::create_commision_transaction() {
        if (this->commission == 0) {
            /* if commission is 0 then there will not be any 
             * commision transaction
             */
            return NULL;
        }
        return new Transaction(this->commission, 0,
                               transaction_type::DEBIT,
                               transaction_sub_type::TRANSACTION_COMISSION,
                               transaction_mode::SYSTEM_TRANSACTION);
    }
    Transaction::~Transaction() {
        delete this->transac_time;
    }
    string Transaction::get_transaction_details() {
        string transac_detail;
        if (this->type == transaction_type::DEBIT) {
            transac_detail += "Dr";
        } else {
            transac_detail += "Cr";
        }

        transac_detail = transac_detail + " " + to_string(this->amount);
        return transac_detail;
    }
}