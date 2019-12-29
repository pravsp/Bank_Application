#include<stdio.h>
#include<stdlib.h>
#include<execinfo.h>
#include<iostream>
#include "system_utils.h"

using namespace std;
namespace banking_lib_utilities{
    void SysUtils::trace_back(void){
        void* array[10];
        size_t size;
        char **strings;
        size_t i;

        size = backtrace(array, 10);
        strings = backtrace_symbols (array, size);
        for (i=0; i < size; i++){
            cout <<strings[i]<<endl;
        }
        free(strings);
    }
}