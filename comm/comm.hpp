/*
 * comm.hpp
 *
 *  Created on: Aug 3, 2016
 *      Author: ruanbo
 */

#ifndef COMM_COMM_HPP_
#define COMM_COMM_HPP_


#include "Log.hpp"

#include <iostream>

#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <string.h>
#include <unistd.h>


using namespace std;


template<class T>
void show_vec(const vector<T>& V, string msg="")
{
    if(msg.length() > 0)
    {
        LogLine("%s:", msg.c_str());
    }

    for(auto &i : V)
    {
        cout << i << " ";
    }
    cout << endl;
}









#endif /* COMM_COMM_HPP_ */
