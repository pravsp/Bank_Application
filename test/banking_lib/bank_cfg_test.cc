#include "gtest/gtest.h"
#include "bank.h"

using namespace banking_lib;
using namespace std;
TEST(BankShould, LoadFromConfigFile){
    
    string cfg_file = "/Users/praveen/Desktop/my_data/My_Project/Banking_System/config/ABC_bank_hrbr.json";
    auto bank = Bank::start_bank_operations(cfg_file);
    EXPECT_NE(bank, (Bank*)NULL);
    delete bank;
}