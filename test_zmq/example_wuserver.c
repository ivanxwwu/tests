//
// Created by root on 18-5-7.
//

#include "zhelpers.h"
#include "time.h"
#include "assert.h"
#include "stdlib.h"

int main()
{
    void *context = zmq_ctx_new();
    void *publisher = zmq_socket(context, ZMQ_PUB);
    int rc = zmq_bind(publisher, "tcp://*:5556");
    assert(rc==0);
    rc = zmq_bind(publisher, "ipc://weather.ipc");
    srandom((unsigned)time(NULL));
    while(1) {
        int zipcode, temperature, relhumidity;
        zipcode = rand()%100000;
        temperature = rand()%215 - 80;
        relhumidity = rand()%50 + 10;
        char update[20];
        sprintf(update, "%05d %d %d", zipcode, temperature, relhumidity);
        printf("%s\n", update);
        s_send(publisher, update);
    }
    zmp_close(publisher);
    zmq_ctx_destroy(context);
    return 0;
}
