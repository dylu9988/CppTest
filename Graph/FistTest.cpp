/*
 * FistTest.cpp
 *
 *  Created on: Dec 20, 2016
 *      Author: ruanbo
 */


#include "comm/comm.hpp"


struct Edge
{
    int _vertex;
    int _weight;
    Edge* _next;

    Edge() : _vertex(0), _weight(0), _next(NULL)
    {

    }

    Edge(int v, int w) : _vertex(v), _weight(w), _next(NULL)
    {

    }

    Edge(int v) : _vertex(v), _weight(0), _next(NULL)
    {

    }
};


class Graph1
{

};











