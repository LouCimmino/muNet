#include <zmq.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
int main (int argc, char *argv[])
{
    //  Socket to talk to clients
    void *context = zmq_ctx_new ();
    void *responder = zmq_socket (context, ZMQ_REQ);
    int rc = zmq_connect (responder, "tcp://192.168.77.19:5000");
    assert (rc == 0);
    char buffer[10];
    char runNum[5];
    sprintf(runNum, argv[1]);
    zmq_send (responder, runNum, 5, 0);
    zmq_recv (responder, buffer, 10, 0);
    //printf ("%s\n",buffer);
    return 0;
}
