//
// Created by root on 18-5-7.
//

#ifndef TEST_ZMQ_ZHELPERS_H
#define TEST_ZMQ_ZHELPERS_H

#include "zmq.h"
#include "assert.h"
#include <stdlib.h>
#include <string.h>

static char * s_recv(void *socket) {
    zmq_msg_t message;
    zmq_msg_init(&message);
    int size = zmq_msg_recv(&message, socket, 0);
    if (size == -1)
        return NULL;
    char *string = malloc(size+1);
    memcpy(string, zmq_msg_data(&message), size);
    zmq_msg_close(&message);
    string[size] = 0;
    return (string);
}

static int s_send(void *socket, char*string) {
    int size = zmq_send(socket, string, strlen(string), 0);
    return size;
}

#endif //TEST_ZMQ_ZHELPERS_H
