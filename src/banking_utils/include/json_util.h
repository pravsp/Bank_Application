#ifndef __JSON_UTIL_H
#define __JSON_UTIL_H
#include <map>
#include <json/json.h>

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

    };
}

#endif //__JSON_UTIL_H