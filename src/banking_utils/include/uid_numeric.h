#ifndef UID_NUMERIC_H
#define UID_NUMERIC_H
#include<iostream>
#include<map>
#include "uid_generator.h"
using namespace std;
namespace banking_lib_utilities{
    class UIDNumeric {
        /*
         * This class is used to generate numeric uid.
         * This will use the UIDGenerator
         */
        static map<string, UIDGenerator<int64_t>*> pools;
        static UIDGenerator<int64_t>* get_uid_pool(string pool_name);
        public:
        static bool create_UIDPool(string pool_name);
        static int64_t get_new_uid(string pool_name);
        static bool release_uid(string pool_name, int64_t uid);
        static list<string> get_available_uid_pool();
        static bool uid_exists(string pool_name, int64_t uid);
        static list<int64_t> get_all_allocated_uid(string pool_name);

    };
}

#endif //UID_NUMERIC_H
