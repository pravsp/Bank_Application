#include<iostream>
#include<fstream>
#include "json/json.h"
#include "../include/json_util.h"

using namespace std;
namespace banking_lib_utilities{
    JsonUtil::JsonUtil(string jfile) {
        this->m_jfile = jfile;
    }

    Json::Value JsonUtil::readFromJson(){
        Json::Reader reader;
        Json::Value obj;
        try{
            ifstream ifs(m_jfile);
            reader.parse(ifs, obj);

            return obj;
        }catch(const ios_base::failure& ex){
            cerr<<"Caught: std::ios_base::failure errno: "<<ex.code().message()<<endl;
            return obj;
        }

    }

    bool JsonUtil::writeToJson(Json::Value& j_obj){
        try{
            ofstream ofs(this->m_jfile);
            Json::StyledWriter writer;

            ofs << writer.write(j_obj);
            ofs.close();
            return true;
        } catch(const ios_base::failure& ex){
            cerr<<"Caught: std::ios_base::failure errno: "<<ex.code().message()<<endl;
            return false;
        }

    }

}