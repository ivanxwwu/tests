#include <iostream>
#include <openssl/ssl.h>
#include "string.h"
#include <string>
using namespace std;

char * Base64Decode(const char * input, int length)
{
    BIO * b64 = NULL;
    BIO * bmem = NULL;
    char * buffer = (char *)malloc(length);
    memset(buffer, 0, length);

    b64 = BIO_new(BIO_f_base64());
    bmem = BIO_new_mem_buf(input, length);
    bmem = BIO_push(b64, bmem);
    BIO_read(bmem, buffer, length);

    BIO_free_all(bmem);

    return buffer;
}

char * Base64Encode(const char * input, int length)
{
    BIO * bmem = NULL;
    BIO * b64 = NULL;
    BUF_MEM * bptr = NULL;

    b64 = BIO_new(BIO_f_base64());
    bmem = BIO_new(BIO_s_mem());
    b64 = BIO_push(b64, bmem);
    BIO_write(b64, input, length);
    BIO_flush(b64);
    BIO_get_mem_ptr(b64, &bptr);

    char * buff = (char *)malloc(bptr->length + 1);
    memcpy(buff, bptr->data, bptr->length);
    buff[bptr->length] = 0;

    BIO_free_all(b64);

    return buff;
}

int Base64Encode2(const char *encoded, int encodedLength, char *decoded)
{
    return EVP_EncodeBlock((unsigned char*)decoded, (const unsigned char*)encoded, encodedLength);
}

int Base64Decode2(const char *encoded, int encodedLength, char *decoded)
{
    return EVP_DecodeBlock((unsigned char*)decoded, (const unsigned char*)encoded, encodedLength);
}

int main() {
//    char s[1024] = "nrt141029";
//    char* p = Base64Encode(s, strlen(s));
//    printf("%s %d\n", p, strlen(p));
//    p = Base64Decode(p, strlen(p));
//    printf("%s\n", p);
//
//    string s1 = "bnJ0MTQxMDI5";
//    char *p2 = Base64Decode(s1.c_str(), s1.length());
//    printf("%s\n", p2);

    char test[] = "nrt141029";
    char result[1000] = {0}; // 编码的结果
    cout << Base64Encode2(test, strlen(test), result) << endl;
    cout << result << endl;

    char org[1000] = {0};    // 解码的结果
    cout << Base64Decode2(result, strlen(result), org) << endl;
    cout << org << endl;

    return 0;
    return 0;
}