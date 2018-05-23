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
    Document document;
    Value a(kArrayType);
    Document::AllocatorType& allocator = document.GetAllocator();
    for (int i = 5; i <= 10; i++)
        a.PushBack(i, allocator);   // 可能需要调用 realloc() 所以需要 allocator
// 流畅接口（Fluent interface）
    a.PushBack("Lua", allocator).PushBack("Mio", allocator);

    cout << a.Size() << endl;
    //a.Clear();
    //cout << a.Size() << endl;
    a.PushBack(Value("copy", document.GetAllocator()).Move(), document.GetAllocator());//copy string
    Value val("key", document.GetAllocator());
    a.PushBack(val, document.GetAllocator());
    cout << a.Size() << endl;
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    a.Accept(writer);
    cout << buffer.GetString() << endl;
}