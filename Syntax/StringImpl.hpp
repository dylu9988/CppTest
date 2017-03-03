/*
 * StringImpl.hpp
 *
 *  Created on: Feb 17, 2016
 *      Author: ruanbo
 */

#ifndef STRINGIMPL_HPP_
#define STRINGIMPL_HPP_

#include <string.h>


class StringImpl
{
private:
    char *m_data;

public:
    // 默认构造函数
    StringImpl()
    {
        m_data = new char[1];
        *m_data = '\0';
    }

    //拷贝构造函数
    StringImpl(const StringImpl& rhs)
    {
        if(&rhs != this)
        {
            delete [] m_data;
            m_data = new char[strlen(rhs.m_data)+1];
            strcpy(m_data, rhs.m_data);
        }
    }

    // 赋值函数
    StringImpl& operator=(const StringImpl& rhs)
    {
        if(&rhs == this)
        {
            return *this;
        }

        delete [] m_data;
        int len = strlen(rhs.m_data);
        m_data = new char[len + 1];
        strcpy(m_data, rhs.m_data);

        return *this;
    }

    ~StringImpl()
    {
        delete [] m_data;
        m_data = NULL;
    }
};




#endif /* STRINGIMPL_HPP_ */
