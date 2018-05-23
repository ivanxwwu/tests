//
// Created by root on 18-4-30.
//

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
using namespace std;
using namespace rapidjson;

int main() {
    const char* json = R"({"project":"rapidjson","stars":10, "testNull":null})";
    Document d;
    d.Parse(json);
    if (d.HasMember("stars") == true) {
        cout << "d hasMember stars" << endl;
        if (d["stars"].IsInt()) {
            cout << "d['stars'] is int" << endl;
        }
        Value& stars = d["stars"];
        cout << stars.GetInt() << endl;
        cout << d["testNull"].IsNull() << endl;
    }


    //array
    const char* json2 = R"({"project":[1,2,3,4, "5", null]})";
    Document d2;
    d2.Parse(json2);
    cout << d2["project"].Size() << endl;
    const Value& project =d2["project"];
    for(SizeType i=0; i<project.Size(); i++) {
        if (project[i].IsInt()) {
            cout << project[i].GetInt() << endl;
        }
        if (project[i].IsString()) {
            cout << project[i].GetString() << endl;
        }
        if (project[i].IsNull()) {
            cout << i+1 << ":" << " null" << endl;
        }
    }
    for(auto& v : project.GetArray()) {
        //...
    }

    Value vb(true);    // 调用 Value(bool)
    Value vi(-123);    // 调用 Value(int)
    Value vu(123u);    // 调用 Value(unsigned)
    Value vd(1.5);     // 调用 Value(double)
    Value va(true);
    cout << "============================" << endl;
    cout << vb.GetBool();
    va = vb; //move
    //cout << vb.GetBool();

    Value o(kObjectType);
    {
        Value contacts(kArrayType);
        // 把元素加进 contacts 数组。
        // ...
        o.AddMember("contacts", contacts, d.GetAllocator());  // 深度复制 contacts （可能有大量内存分配）
        // 析构 contacts。
    }

    Value a(kArrayType);
    Document::AllocatorType& allocator = d.GetAllocator();
// a.PushBack(Value(42), allocator);       // 不能通过编译
    a.PushBack(Value().SetInt(42), allocator); // fluent API
    a.PushBack(Value(42).Move(), allocator);   // 和上一行相同


    Document document;
    Value author;
    char buffer[10];
    int len = sprintf(buffer, "%s %s", "Milo", "Yip"); // 动态创建的字符串。
    author.SetString(buffer, len, document.GetAllocator());
    memset(buffer, 0, sizeof(buffer));

    Value s;
    s.SetString("rapidjson");    // 可包含空字符，长度在编译萁推导
    s = "rapidjson";             // 上行的缩写


}