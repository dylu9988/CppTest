/*
 * SmartPtr.cpp
 *
 *  Created on: Jul 13, 2017
 *      Author: ruanbo
 */

#include "SmartPtr.hpp"

/*
template<class DP>
SmartPtr<DP>::SmartPtr(DP* datap)
{
    _p = datap;
    _ref_count = 1;
}

template<class TP>
SmartPtr<TP>::~SmartPtr()
{
    _ref_count--;
    if(_ref_count == 0)
    {
        delete _p;
    }
}

template<class TP>
SmartPtr<TP>& SmartPtr<TP>::operator = (const SmartPtr& rhs)
{
    if(_ref_count == 1)
    {
        delete _p;
        _p = NULL;
    }

    _p = rhs._p;
    rhs._ref_count++;
    _ref_count = rhs._ref_count;

    return *this;
}

template<typename TP>
SmartPtr<TP>::SmartPtr(const SmartPtr& rhs)
{
    if(_ref_count == 1)
    {
        delete _p;
        _p = NULL;
    }

    _p = rhs._p;
    rhs._ref_count++;
    _ref_count = rhs._ref_count;
}
*/








