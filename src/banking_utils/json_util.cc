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
            if(!(reader.parse(ifs, obj))){
                cout<<"Error Parsing the file: "<<this->m_jfile<<endl;
            }
            ifs.close();
            return obj;
        }catch(const ios_base::failure& ex){
            cerr<<"Caught: std::ios_base::failure errno: "<<ex.code().message()<<endl;
            return obj;
        }

    }

    bool JsonUtil::writeToJson(Json::Value j_obj){
        try{
            cout << "writing to file: "<<this->m_jfile<<endl;
            cout << "writing data: "<< j_obj <<endl;
            ofstream ofs(this->m_jfile);
            Json::StyledWriter writer;

            ofs << writer.write(j_obj);
            ofs.close();
            return true;
        } catch(const ios_base::failure& ex){
            cout<<"Caught: std::ios_base::failure errno: "<<ex.code().message()<<endl;
            return false;
        }

    }
    /*
    map<string, string> convertJsontoStringMap(Json::Value root){
        map<string, string> json_map;
        for (auto itr = root.begin(); itr != root.end(); itr++){
            auto key = itr.key().asString();
            json_map.insert(make_pair(key, root[key].asString()));
        }
        return json_map;
    }
    */
}