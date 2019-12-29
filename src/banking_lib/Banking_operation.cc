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
        string cfg_file = "/Users/praveen/Desktop/my_data/My_Project/Banking_System/config/ABC_bank_hrbr.json";
        this-> m_bank = Bank::start_bank_operations(cfg_file);
        //banking_lib_utilities::SysUtils::trace_back();
        
    }
    BankingOperation::BankingOperation(string cfg_file){
        cout<<"Bank Operation called with cfg file: "<<cfg_file<<endl;
        this-> m_bank = Bank::start_bank_operations(cfg_file);
    }
}
