#include<iostream>
#include<map>
#include "../include/uid_type.h"
#include "../include/uid_numeric.h"


using namespace std;

namespace banking_lib_utilities {
    map<string, UIDGenerator<int64_t>*> UIDNumeric::pools;

    bool UIDNumeric::create_UIDPool(string pool_name){
        UIDGenerator<int64_t>* pool = UIDNumeric::get_uid_pool(pool_name); 
        if ( pool == NULL) {
            pool = new UIDGenerator<int64_t>(INTEGER);
            if (pool == NULL) {
                cout<<"Error Creating Numeric UIDPool"<<endl;
                return false;
            }
            UIDNumeric::pools.insert(make_pair(pool_name, pool));    
        }
        return true;
    }
    UIDGenerator<int64_t>* UIDNumeric::get_uid_pool(string pool_name){
        auto itr = UIDNumeric::pools.find(pool_name);
        if (itr == UIDNumeric::pools.end()){
            return NULL;
        }
        return itr->second;
    }

    list<string> UIDNumeric::get_available_uid_pool(){
        list<string> available_pools;
        for (auto itr = UIDNumeric::pools.begin();
                itr != UIDNumeric::pools.end(); itr++){
            available_pools.push_back(itr->first);
        }
        return available_pools;
    }

    int64_t UIDNumeric::get_new_uid(string pool_name){
        auto pool = UIDNumeric::get_uid_pool(pool_name);
        if (pool == NULL) {
            cout<<"Couldn't find the pool for "<<pool_name<<endl;
            return -1;
        }
        return pool->create_new_uid();

    }
    bool UIDNumeric::release_uid(string pool_name, int64_t uid){
        auto pool = UIDNumeric::get_uid_pool(pool_name);
        if (pool == NULL) {
            cout<<"Couldn't find the pool for "<<pool_name<<endl;
            return false;
        }
        return pool->release_uid(uid);
    }

    bool UIDNumeric::uid_exists(string pool_name, int64_t uid){
        auto pool = UIDNumeric::get_uid_pool(pool_name);
        if (pool == NULL) {
            cout<<"Couldn't find the pool for "<<pool_name<<endl;
            return false;
        }
        return pool->uid_exists(uid);
    }
    list<int64_t> UIDNumeric::get_all_allocated_uid(string pool_name){
        auto pool = UIDNumeric::get_uid_pool(pool_name);
        if (pool == NULL) {
            cout<<"Couldn't find the pool for "<<pool_name<<endl;
            //return empty list
            return list<int64_t>();
        }
        return pool->get_all_allocated_uid();        

    }

}