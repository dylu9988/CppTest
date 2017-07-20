/*
 * SmartPtr.hpp
 *
 *  Created on: Jul 13, 2017
 *      Author: ruanbo
 */

#ifndef CPP11_SMARTPTR_HPP_
#define CPP11_SMARTPTR_HPP_

#include "comm/comm.hpp"

template<typename TP>
class RefCount
{
private:
    int _ref_count;
public:
    TP* _refp;

public:
    RefCount(TP* p = NULL)
    {
        _refp = p;
        if(_refp)
        {
            _ref_count = 1;
        }
        else
        {
            _ref_count = 0;
        }
    }

    ~RefCount()
    {
        Log("~RefCount()");
    }

private:
    void destroy()
    {
        if(_refp)
        {
            delete _refp;
        }
        delete this;
    }

public:
    void inc_ref()
    {
        _ref_count++;
    }
    void dec_ref()
    {
        _ref_count--;
        if(_ref_count == 0)
        {
            destroy();
        }
    }

    void swap(RefCount* rhs)
    {
        if(!rhs)
        {
            dec_ref();
        }
        else
        {
            std::swap(_refp, rhs->_refp);
            std::swap(_ref_count, rhs->_ref_count);
        }
    }
};

template<class TP>
class SmartPtr
{
private:
    TP* _p;
    RefCount<TP>* _ref;

public:
    SmartPtr(TP* datap=NULL)
    {
        if(datap == NULL)
        {
            _p = NULL;
            _ref = NULL;
        }
        else
        {
            _p = datap;
            _ref = new RefCount<TP>(datap);
        }
    }

    virtual ~SmartPtr()
    {
        Log("~SmartPtr()");
        if(_ref)
        {
            _ref->dec_ref();
        }

    }

    SmartPtr& operator = (const SmartPtr& rhs)
    {
        if(_p == rhs._p)
        {
            return *this;
        }

        if(_p)
        {
            _ref->dec_ref();
        }

        if(rhs._p)
        {
            _p = rhs._p;
            _ref = rhs._ref;
            _ref->inc_ref();
        }
        else
        {
            _p = NULL;
            _ref = NULL;
        }

        Log("SmartPtr& operator = (const SmartPtr& rhs)");

        return *this;
    }

    SmartPtr(const SmartPtr& rhs)
    {
        if(_p)
        {
            _ref->dec_ref();
        }

        if(rhs._p)
        {
            _p = rhs._p;
            _ref = rhs._ref;
            _ref->inc_ref();
        }
        else
        {
            _p = NULL;
            _ref = NULL;
        }

        Log("SmartPtr(const SmartPtr& rhs)");
    }
};


#endif /* CPP11_SMARTPTR_HPP_ */







