//
// Created by root on 18-5-19.
//

#include "rapidjson/pointer.h"
#include "rapidjson/document.h"
#include <iostream>
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

using namespace std;
using namespace rapidjson;

int main()
{
    std::string json = R"(
        {
            "project":"rapidjson",
            "stars":[{"a":1},{"a":2}],
            "test":{"0":1},
            "foo":[1,2,3],
            "foo/0":{"a":1, "b":2},
            "m~n":123
        }
       )";
    char* cJson = NULL;
    Document d;
    d.Parse(json.c_str());
    cout << d.HasParseError() << endl;
    Pointer p = Pointer("/test") ;
    cout << d.GetParseError() << endl;
    cout << d.GetErrorOffset() << endl;

    Value* v = p.Get(d);
    cout << v->IsArray() << endl;
    cout << v->Size() << endl;

//
//    if (Value* v = GetValueByPointer(d, "stars"))
//    {
//        cout << "123" << endl;
//    }
//    cout << Pointer::GetParseErrorCode() << endl;
//    Pointer::GetParseErrorOffset
    if (v == nullptr)
    {
        cerr << "err..." << endl;
        return -1;
    }
    //cout << v->GetInt();
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    v->Accept(writer);
    cout << buffer.GetString() << endl;
}
