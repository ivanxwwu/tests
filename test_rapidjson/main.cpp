#include <iostream>
#include <string>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <openssl/ssl.h>
#include <map>
#include <vector>

using namespace std;
using namespace rapidjson;

struct A{
    int type;
    vector<string> word;
};

int main() {
    vector<A> v;
    v.emplace_back(A{1, {}});
    return 0;
}