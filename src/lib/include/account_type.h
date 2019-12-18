#ifndef ACCT_TYPE_H
#define ACCT_TYPE_H

namesapce banking_lib {
    enum account_type {
        SAVINGS_ACCT,
        CURRENT_ACCT,
        FD_ACCT,
        /*Add anything above this line*/
        MAX_ACCT_TYPE
    };
}

#endif //ACCT_TYPE_H