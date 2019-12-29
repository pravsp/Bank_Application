#ifndef __JSON_UTIL_H
#define __JSON_UTIL_H
#include <map>
#include "json/json.h"

using namespace std;
namespace banking_lib_utilities{
    class JsonUtil{
        string m_jfile;
        public:
            JsonUtil(string jfile);
            Json::Value readFromJson();
            bool writeToJson(Json::Value& j_obj );
            
            template <typename K, typename V>
            Json::Value convertMapToJson(map<K,V> my_map){
                Json::Value jsonMap;
                for(auto const& [key, value] : my_map){
                    jsonMap[key] = value;
                }
                return jsonMap;
            }

            map<string, string> convertJsontoStringMap(Json::Value root){
                map<string, string> json_map;
                for (auto itr = root.begin(); itr != root.end(); itr++){
                    auto key = itr.key().asString();
                    json_map.insert(make_pair(key, root[key].asString()));
                }
                return json_map;
            }

    };
}

#endif //__JSON_UTIL_H