#ifndef __BANKING_OPERATION_H
#define __BANKING_OPERATION_H
#include<iostream>
#include "bank.h"
using namespace std;
namespace banking_lib {
    class BankingOperation{
        
        Bank* m_bank;
        public:
        BankingOperation();
        BankingOperation(string bank_name, string branch);
        void InitializeBank(string name, string branch, Address* addr);
        ~BankingOperation();
        BankingOperation(string cfg_file);
        

    };
}
#endif //__BANKING_OPERATION_H