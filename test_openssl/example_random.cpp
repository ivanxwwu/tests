//
// Created by root on 18-4-30.
//
#include <stdio.h>


typedef int *callback_random(char *random,int len);
void set_callback(callback_random *cb);
int genrate_random(char *random,int len);

static int default_random(char *random,int len)
{
    memset(random,0x01,len);
    return 0;
}

void set_callback(callback_random *cb)
{
    cb_rand=cb;
}

int genrate_random(char *random,int len)
{
    if(cb_rand==NULL)
        return default_random(random,len);
    else
        return cb_rand(random,len);
    return 0;
}

static int my_rand(char *rand,int len)
{
    memset(rand,0x02,len);
    return 0;
}

int main()
{
    char random[10];
    int ret;
    set_callback(my_rand);
    ret=genrate_random(random,10);
    return 0;
}