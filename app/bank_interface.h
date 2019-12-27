#ifndef __BANK_INTERFACE_H
#define __BANK_INTERFACE_H

#include "Banking_Operation.h"

using namespace std;
using namespace banking_lib;

#define BANK_OPERATIONS \
    ENUM_OR_STRING( OPEN_NEW_ACCOUNT ),   \
    ENUM_OR_STRING( CLOSE_ACCOUNT ),    \
    ENUM_OR_STRING( WITHDRAW_CASH ),    \
    ENUM_OR_STRING( TRANSFER_CASH ),    \
    ENUM_OR_STRING( DEPOSIT_CASH ),     \
    ENUM_OR_STRING( QUIT ),     \
    
#undef ENUM_OR_STRING
#define ENUM_OR_STRING( X ) X    
enum BankingUserOption {
    BANK_OPERATIONS
    //ADD Any new option in the above macro
    MAX_BANKING_USER_OPTION
};


class BankingInterface{
    BankingOperation *m_bank;

    int get_user_option();

    public:
        BankingInterface(BankingOperation* bank);
        BankingInterface();
        ~BankingInterface();
        void get_bank_instance();
        void start_bank_operation();


    
};

#endif //__BANK_INTERFACE_H