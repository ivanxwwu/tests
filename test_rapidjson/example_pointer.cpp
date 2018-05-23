//
// Created by root on 18-4-30.
//

#include "rapidjson/pointer.h"
#include "rapidjson/document.h"
#include <iostream>
#include <rapidjson/stringbuffer.h>
#include "rapidjson/writer.h"

using namespace std;
using namespace rapidjson;

int main() {

    Document d;
    Pointer("/project").Set(d, "RapidJSON");
    Pointer("/stars").Set(d, 10);
    if (Value* stars = Pointer("/stars").Get(d))
        stars->SetInt(stars->GetInt() + 1);
    Pointer("/a/b/0").Create(d);
    Value& hello = Pointer("/hello").GetWithDefault(d, "world");
    Value x("C++");
    Pointer("/hello").Swap(d, x);
    bool success = Pointer("/a").Erase(d);
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);
    cout << buffer.GetString() << endl;


    Document d2;
    SetValueByPointer(d2, "/project/a/b", "RapidJSON");
    SetValueByPointer(d2, "/stars", 10);
    if (Value* stars = GetValueByPointer(d2, "/stars"))
        stars->SetInt(stars->GetInt() + 1);
    CreateValueByPointer(d2, "/a/b/0");

    Value& hello2 = GetValueByPointerWithDefault(d2, "/hello", "world");
    Value x2("C++");
    SwapValueByPointer(d2, "/hello", x2);

    bool success2 = EraseValueByPointer(d2, "/a");
    assert(success2);
    StringBuffer buffer2;
    Writer<StringBuffer> writer2(buffer2);
    d2.Accept(writer2);
    cout << buffer2.GetString() << endl;



}