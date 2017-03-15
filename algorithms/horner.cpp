/*
 * horner.cpp
 *
 *  Created on: Mar 8, 2017
 *      Author: ruanbo
 */


#include "comm/comm.hpp"
#include <cmath>

/*
 *  f(x) = a[n]*x^n + a[n-1]*x^(n-1) + ... + a[1]*x + a[0]
 */

class horner
{
private:
    vector<int> _data;
    int _key;

public:
    horner()
    {
        _data = {1, 2, 3, -1, 9};
        _key = 5;
    }

public:
    void show()
    {
        for(auto &x: _data)
        {
            LogLine("%d ", x);
        }

        Log(" ");
    }

    void hn_cal()
    {
        int val = 0;

        size_t len = _data.size();
        if(len == 0)
        {
            Log("val = 0");
            return;
        }
        for(size_t i=len-1; i>0; --i)
        {
            val = _key * (_data[i] + val);
        }

        val += _data[0];

        Log("horner val:%d", val);
    }


    void confirm()
    {
        int val = 0;

        size_t len = _data.size();
        for(size_t i=0; i<len; ++i)
        {
            val += _data[i] * pow(_key, i);
        }

        Log("confirm val:%d", val);
    }
};



void horner_tests()
{
    horner hn;

    hn.show();

    hn.hn_cal();
    hn.confirm();
}

