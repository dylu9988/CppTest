/*
 * ServerTest.cpp
 *
 *  Created on: Sep 6, 2017
 *      Author: ruanbo
 */

#include "SimpleServer.hpp"

void server_test()
{
    SimpleServer ss;

    if(ss.init() == false)
    {
        return;
    }

    ss.run();

}



