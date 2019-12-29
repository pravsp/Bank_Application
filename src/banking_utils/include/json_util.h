#ifndef __JSON_UTIL_H
#define __JSON_UTIL_H
#include <map>
#include <list>
#include "json/json.h"

using namespace std;
namespace banking_lib_utilities{
    class JsonUtil{
        string m_jfile;
        public:
            JsonUtil(string jfile);
            Json::Value readFromJson();
            bool writeToJson(Json::Value j_obj );
            
            template <typename K, typename V>
            static Json::Value convertMapToJson(map<K,V> my_map){
                Json::Value jsonMap;
                for(auto const& [key, value] : my_map){
                    jsonMap[key] = value;
                }
                return jsonMap;
            }

            static map<string, string> convertJsontoStringMap(Json::Value root){
                map<string, string> json_map;
                for (auto itr = root.begin(); itr != root.end(); itr++){
                    auto key = itr.key().asString();
                    json_map.insert(make_pair(key, root[key].asString()));
                }
                return json_map;
            }

            template <class T>
            static  Json::Value convertObjectListToJson(list<T*> obj_l, Json::Value (*callback) (T* obj)){
                if (!callback){
                    throw invalid_argument( "received null callback" );
                }
                Json::Value root;

                for (auto v : obj_l){
                    root.append(callback(v));
                }
                return root;
            }

    };
}

#endif //__JSON_UTIL_H