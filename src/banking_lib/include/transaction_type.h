#ifndef TRANSACT_TYPE_H
#define TRANSACT_TYPE_H

namespace banking_lib {
    enum transaction_mode {
        BANK_TRANSACTION,
        ATM_TRANSACTION,
        ONLINE_TRANSACTION,
        SYSTEM_TRANSACTION,
        /*Add anything above this line*/
        MAX_TRANSACTION_MODE
    };

    enum transaction_type {
        CREDIT,
        DEBIT,
        /*Add anything above this line*/
        MAX_TRANSACTION_TYPE
    };

    enum transaction_sub_type {
        CASH_DEPOSIT,
        CASH_TRANSFER,
        CREDIT_INTEREST,
        CASH_WITHDRAWL,
        BANK_CHARGES,
        TRANSACTION_COMISSION,
        /*Add anything above this line*/
        MAX_TRANSACTION_SUB_TYPE
    };

    enum transaction_status {
        SUCCEEDED,
        FAILED,
        ROLLBACK,
        /*Add anything aove this line*/
        MAX_TRANSACTION_STATUS
    };
}

#endif //TRANSACT_TYPE_H