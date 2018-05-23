//
// Created by root on 18-5-1.
//

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
using namespace std;
using namespace rapidjson;

int main() {
    string string1 = R"([{"LockIndex":0,"Key":"test/community/daemon/stat_data/","Flags":0,"Value":null,"CreateIndex":127329,"ModifyIndex":127329},{"LockIndex":0,"Key":"test/community/daemon/stat_data/loglevel","Flags":0,"Value":"NA==","CreateIndex":127331,"ModifyIndex":145276},{"LockIndex":0,"Key":"test/community/daemon/stat_data/relation_nrt","Flags":0,"Value":"bnJ0MTQxMDI5","CreateIndex":127332,"ModifyIndex":138131},{"LockIndex":0,"Key":"test/community/daemon/stat_data/topic_count_nrt","Flags":0,"Value":"bnJ0MTQxMDM1","CreateIndex":127334,"ModifyIndex":138031},{"LockIndex":0,"Key":"test/community/daemon/stat_data/topic_info_nrt","Flags":0,"Value":"bnJ0MTQxMDM0","CreateIndex":127336,"ModifyIndex":127336},{"LockIndex":0,"Key":"test/community/daemon/stat_data/user_nrt","Flags":0,"Value":"bnJ0MTQxMDM2","CreateIndex":127337,"ModifyIndex":127337}])";
    Document d;
    d.Parse(string1.c_str());
    if(d.HasParseError()) {
        cout << "Parse error" << endl;
    }
    if(!d.IsArray()) {
        cout << "is not array" << endl;
    }
    for (auto& object : d.GetArray()) {
        string k;
        if(object.HasMember("Key") && object["Key"].GetType()==kStringType) {
            k = object["Key"].GetString();
            cout << k << endl;
        }
    }
}