/*
 * Iconv.cpp
 *
 *  Created on: Jul 31, 2017
 *      Author: ruanbo
 */

#include "comm/comm.hpp"
#include <iconv.h>
#include <fstream>


void encode_iconv()
{
    iconv_t cd = iconv_open("utf-8", "latin1");
    if(cd == (iconv_t)-1)
    {
        Log("iconv_open failed");
        return;
    }

    ifstream f;
    f.open("Datas/test.txt");
    if(f.is_open() == false)
    {
        Log("open file failed");
        iconv_close(cd);
        return;
    }

    f.seekg(0, ios::end);
    size_t len = f.tellg();
    f.seekg(0, ios::beg);

    Log("file data len:%lu", len);

    char data[8192] = { 0 };
    memset(data, 0, sizeof(data));

    f.read(data, len);

    Log("read data size:%lu\n", strlen(data));

//    Log("%s", data);


    size_t inlen = 8192;
    size_t outlen = 10240;
    char d2[10240] = { 0 };
    memset(d2, 0, sizeof(d2));

    char* pin = data;
    char* pout = d2;

    Log("before iconv");

    int ret = iconv(cd, &pin, &len, &pout, &outlen);
    if(ret < 0)
    {
        Log("iconv() failed, errno:%d", errno);
        return;
    }
    else
    {
        Log("ret:%d\n", ret);
    }

    Log("%s", d2);

    Log("\n\n\n\n\n");
    for(int i=0; i<300; ++i)
    {
        LogLine("%c", data[i]);
    }

    iconv_close(cd);
}


