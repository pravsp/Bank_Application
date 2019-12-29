#include <iostream>
#include "bank_interface.h"
using namespace std;

#undef ENUM_OR_STRING
#define ENUM_OR_STRING( X ) #X
const char* banking_user_option [] = {
    BANK_OPERATIONS
    "Enter your choice:"
};


BankingInterface::BankingInterface(BankingOperation* bank){
    this->m_bank = bank;
}

BankingInterface::BankingInterface(){
    this->get_bank_instance();
}
BankingInterface::~BankingInterface(){
    
    if (this->m_bank){
        delete this->m_bank;
    }
}

int BankingInterface::get_user_option(){
    int user_option = 0;
    cout <<"\nEnter your option:\n"<<endl;
    /*
    for (char const* &c: banking_user_option){
        cout<<"\t"<< user_option << "."<< c <<endl;
        user_option++;
    }
    */
    for(; user_option < sizeof(banking_user_option)/sizeof(const char*) - 1; user_option++){
        cout<<"\t"<< user_option+1 << "."<< banking_user_option[user_option] <<endl;
    }
    cout << "\n\t"<<banking_user_option[user_option]<<" ";
    cin >> user_option;
    return user_option - 1;
}
void BankingInterface::get_bank_instance(){
    /*
    string bank_name;
    string branch_name;
    cout <<"Enter Bank Name:";
    cin >> bank_name;
    cout <<"ENter Branch Name:";
    cin >> branch_name;
    */
    this->m_bank = new BankingOperation();
}
void BankingInterface::start_bank_operation(){
    do{
        auto user_choice = this->get_user_option();
        if (user_choice < MAX_BANKING_USER_OPTION) {
            cout << "User Selected " << banking_user_option[user_choice]<<endl;
        }
        switch(user_choice){
            case OPEN_NEW_ACCOUNT:
                break;
            case CLOSE_ACCOUNT:
                break;
            case WITHDRAW_CASH:
                break;
            case TRANSFER_CASH:
                break;
            case DEPOSIT_CASH:
                break;
            case QUIT:
                cout << "Quitting the bank application" <<endl;
                return;
            default:
                cout << "Invalid Option"<<endl;
        }


    }while(true);
    
}