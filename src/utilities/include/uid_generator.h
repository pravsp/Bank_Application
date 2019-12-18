#ifndef UID_GENERATOR_H
#define UID_GENERATOR_H
#include<iostream>
#include<map>
#include<list>
#include <sstream>
#include "uid_type.h"


using namespace std;

namespace banking_lib_utilities{
    #define DEFAULT_ALPHANUMERIC_UID_LENGTH 10
    class UIDNumeric;
    class UIDAlphaNumeric;

    template<typename T>
    class UIDGenerator{
        /*
         * This class is used to generate unique id. The unique id can be
         * integer or alphanumeric.
         */
        list <T> m_allocated_id;
        static map<string, UIDGenerator<T>*> pools;
        enum uid_type type;
        int length;
        
        UIDGenerator(enum uid_type type)
        :m_allocated_id()
        {
            this->type = type;
            this->length = DEFAULT_ALPHANUMERIC_UID_LENGTH;
            
        }
        
        bool uid_exists(T uid){
            /*
             * uid_exists check if the uid exists in allocated list
             * :param uid: unique id
             * :type uid: template<typename T>
             * :return: true if the id exists else false
             * :rtype: bool
             */
            auto itr = find(this->m_allocated_id.begin(),
                            this->m_allocated_id.end(),
                            uid);
            if (itr == this->m_allocated_id.end()) {
                return false;
            }

            return true;
        }
        T create_new_uid(){
            /*
             * create_new_uid will create a new uid
             * :return: newly generated uid
             * :rtype: template<typename T>
             */
            T uid;
            do {
                uid = this->random_uid();
            }while(this->uid_exists(uid));
            this->m_allocated_id.push_back(uid);
            return uid;
        }
        bool release_uid(T uid){
            /*
             * release_uid will release the uid from the allocated_list
             * :param uid: unique id to be released
             * :type uid: template<typename T>
             * :return: true if the id is successfully released else false
             * :rtype: bool
             */
            if (this->uid_exists(uid)){
                this->m_allocated_id.remove(uid);
                return true;
            } else {
                cout<<"The entry didnt exists"<<endl;
                return false;
            }
        }
        list<T> get_all_allocated_uid(){
            /*
             * get_all_allocated_uid will get all the allocated uids
             * :return: list of allocated uids
             * :rtype: list<template<typename T>>
             */
            return this->m_allocated_id;
        }
        T random_uid(){
            /*
             * rand_uid will generate the random uid depending on template type
             * :return: uid generated
             * :rtype: template<typename T>
             */
            auto randchar_int = []() -> char
            {
                const char charset[] =
                "0123456789";
                const size_t max_index = (sizeof(charset) - 1);
                return charset[ rand() % max_index ];
            };
            auto randchar_str = []() -> char
            {
                const char charset[] =
                "0123456789"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "abcdefghijklmnopqrstuvwxyz";
                const size_t max_index = (sizeof(charset) - 1);
                return charset[ rand() % max_index ];
            };
            
            string str(length,0);
            
            
            if (this->type == INTEGER){
                generate_n( str.begin(), length, randchar_int);
            }else {
                generate_n( str.begin(), length, randchar_str);
            }
            
            stringstream convert(str);
            T value;
            convert >> value;
            return value;
        }
        
        //Make the instantiation only through the friend class
        friend class UIDNumeric;
        friend class UIDAlphaNumeric;
        
    };
    

}

#endif //UID_GENERATOR_H