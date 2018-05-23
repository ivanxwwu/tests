//
// Created by root on 18-5-6.
//

#include <zmq.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    void * context = zmq_ctx_new();
    printf("Connecting to hello world server...\n");
    void * requester = zmq_socket(context, ZMQ_REQ);
    zmq_connect(requester, "tcp://localhost:5555");
    sleep(2);
    zmq_close(requester);
    zmq_ctx_destroy(context);
    return 0;
}