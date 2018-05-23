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
    Document d;
    Document::AllocatorType& a = d.GetAllocator();
    Value v1("foo");
// Value v2(v1); // 不容许
    Value v2(v1, a);                      // 制造一个克隆
    assert(v1.IsString());                // v1 不变
    d.SetArray().PushBack(v1, a).PushBack(v2, a);
    assert(v1.IsNull() && v2.IsNull());   // 两个都转移动 d
    v2.CopyFrom(d, a);                    // 把整个 document 复制至 v2
    assert(d.IsArray() && d.Size() == 2); // d 不变
    v1.SetObject().AddMember("array", v2, a);
    d.PushBack(v1, a);
}