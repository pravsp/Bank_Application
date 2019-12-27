#include <iostream>
#include "include/Banking_Operation.h"
#include "include/bank.h"
//#include "system_utils.h"

using namespace std;
namespace banking_lib{
    BankingOperation::BankingOperation(string bank_name, string branch){
        Address *b_addr = new Address();
        this->m_bank = new Bank(bank_name, branch, b_addr);
    }

    void BankingOperation::InitializeBank(string name, string branch, Address* addr){
        this->m_bank = new Bank(name, branch, addr);
    }

    BankingOperation::~BankingOperation(){
        if (this->m_bank != NULL){
            delete this->m_bank;
        } else {
            cout << "Bank Operation Destructor with null bank instance"<<endl;
        }
        

    }
    BankingOperation::BankingOperation(){
        cout<<"Bank Operation default constructor"<<endl;
        //banking_lib_utilities::SysUtils::trace_back();
        this->m_bank = NULL;
    }
}
