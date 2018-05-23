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
    Value a(123);
    Value b("Hello");
    a.Swap(b);
    assert(a.IsString());
    assert(b.IsInt());
}