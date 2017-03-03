/*
 * FirstTest.cpp
 *
 *  Created on: Mar 1, 2016
 *      Author: ruanbo
 */


#include <comm/Log.hpp>
#include <zmq.hpp>
#include <string.h>
#include <iostream>
#include <unistd.h>


void zero_first_test()
{
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_REQ);
    socket.bind("tcp://*:5555");

    while(true)
    {
        zmq::message_t request;

        socket.recv(&request);

        //Log("Received:%s", (char*)request.data());

        Log("Received Hello");

        sleep(1);

        zmq::message_t reply(5);
        memcpy(reply.data(), "World", 5);
        socket.send(reply);
    }




    Log("end of zeromq first test");
}


void zero_first_test2 (void)
{
    //  Socket to talk to clients
    void *context = zmq_ctx_new ();
    void *responder = zmq_socket (context, ZMQ_REP);
    int rc = zmq_bind (responder, "tcp://*:5555");
    assert (rc == 0);

    while (1)
    {
        char buffer [10];
        zmq_recv (responder, buffer, 10, 0);
        Log ("Received:%s\n", buffer);

        sleep (1);          //  Do some 'work'

        zmq_send (responder, "World", 5, 0);
    }

    Log("end of zeromq first test2");
}













