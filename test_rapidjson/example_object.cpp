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
    Value kObject(123);
    Document document;
    Value a(kObjectType);
    a.AddMember("abc", kObject, document.GetAllocator());

    Value contact(kObjectType);
    contact.AddMember("name", "Milo", document.GetAllocator());
    contact.AddMember("married", true, document.GetAllocator());
    contact.AddMember("a", a, document.GetAllocator());

    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    contact.Accept(writer);
    cout << buffer.GetString() << endl;

    /*
     bool RemoveMember(const Ch* name)：使用键名来移除成员（线性时间复杂度）。
    bool RemoveMember(const Value& name)：除了 name 是一个 Value，和上一行相同。
    MemberIterator RemoveMember(MemberIterator)：使用迭代器移除成员（_ 常数 _ 时间复杂度）。
    MemberIterator EraseMember(MemberIterator)：和上行相似但维持成员次序（线性时间复杂度）。
    MemberIterator EraseMember(MemberIterator first, MemberIterator last)：移除一个范围内的成员，维持次序（线性时间复杂度）。
     */

    contact.RemoveMember("a");
    buffer.Clear();
    Writer<StringBuffer> writer2(buffer);
    contact.Accept(writer2);
    cout << buffer.GetString() << endl;


//    for(Value::ConstMemberIterator itr = document.MemberBegin(); itr!=document.MemberEnd(); ++itr) {
//        cout << itr->name.GetString();
//    }

    for(auto& item : contact.GetObject()) {
        cout << item.name.GetString() << endl;
        cout << item.value.GetType() << endl;
    }

}