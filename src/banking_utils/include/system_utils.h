#ifndef __SYSTEM_UTILS_H
#define __SYSTEM_UTILS_H
#include<stdio.h>
#include<stdlib.h>
#include<execinfo.h>


using namespace std;
namespace banking_lib_utilities{
    class SysUtils{
        public:
        static void trace_back(void);
    };

}

#endif //__SYSTEM_UTILS_H