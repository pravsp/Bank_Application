#ifndef TRANSACTION_H
#define TRANSACTION_H
#include<iostream>
#include<time.h>
#include "transaction_type.h"


using namespace std;

namespace banking_lib {
    class Transaction {
        public:
        enum transaction_type type;
        enum transaction_sub_type sub_type;
        enum transaction_status status;
        enum transaction_mode mode;
        tm* transac_time;
        float commission;
        float amount;
        

        Transaction(float amount, float commission,
                    enum transaction_type type,
                    enum transaction_sub_type sub_type,
                    enum transaction_mode mode);
        ~Transaction();
        
        void set_status(enum transaction_status status);
        Transaction* create_commision_transaction();
        string get_transaction_details();
    };
}

#endif //TRANSACTION_H