#include <iostream>
#include "bank_interface.h"
#include "Banking_Operation.h"

using namespace std;
using namespace banking_lib;



int main(int argc, char *argv[]){
    BankingInterface bui = BankingInterface();
    bui.start_bank_operation();

}