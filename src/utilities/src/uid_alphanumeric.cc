#include<iostream>
#include<map>
#include "../include/uid_type.h"
#include "../include/uid_alphanumeric.h"


using namespace std;

namespace banking_lib_utilities {
    map<string, UIDGenerator<string>*> UIDAlphaNumeric::pools;

    bool UIDAlphaNumeric::create_UIDPool(string pool_name){
        UIDGenerator<string>* pool = UIDAlphaNumeric::get_uid_pool(pool_name); 
        if ( pool == NULL) {
            pool = new UIDGenerator<string>(ALPHA_NUMERIC);
            if (pool == NULL) {
                cout<<"Error Creating AlphaNumeric UIDPool"<<endl;
                return false;
            }
            UIDAlphaNumeric::pools.insert(make_pair(pool_name, pool));    
        }
        return true;
    }
    UIDGenerator<string>* UIDAlphaNumeric::get_uid_pool(string pool_name){
        auto itr = UIDAlphaNumeric::pools.find(pool_name);
        if (itr == UIDAlphaNumeric::pools.end()){
            return NULL;
        }
        return itr->second;
    }

    list<string> UIDAlphaNumeric::get_available_uid_pool(){
        list<string> available_pools;
        for (auto itr = UIDAlphaNumeric::pools.begin();
                itr != UIDAlphaNumeric::pools.end(); itr++){
            available_pools.push_back(itr->first);
        }
        return available_pools;
    }

    string UIDAlphaNumeric::get_new_uid(string pool_name){
        auto pool = UIDAlphaNumeric::get_uid_pool(pool_name);
        if (pool == NULL) {
            cout<<"Couldn't find the pool for "<<pool_name<<endl;
            return string();
        }
        return pool->create_new_uid();

    }
    bool UIDAlphaNumeric::release_uid(string pool_name, string uid){
        auto pool = UIDAlphaNumeric::get_uid_pool(pool_name);
        if (pool == NULL) {
            cout<<"Couldn't find the pool for "<<pool_name<<endl;
            return false;
        }
        return pool->release_uid(uid);
    }

    bool UIDAlphaNumeric::uid_exists(string pool_name, string uid){
        auto pool = UIDAlphaNumeric::get_uid_pool(pool_name);
        if (pool == NULL) {
            cout<<"Couldn't find the pool for "<<pool_name<<endl;
            return false;
        }
        return pool->uid_exists(uid);
    }
    list<string> UIDAlphaNumeric::get_all_allocated_uid(string pool_name){
        auto pool = UIDAlphaNumeric::get_uid_pool(pool_name);
        if (pool == NULL) {
            cout<<"Couldn't find the pool for "<<pool_name<<endl;
            //return empty list
            return list<string>();
        }
        return pool->get_all_allocated_uid();        

    }


}