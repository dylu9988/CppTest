/*
 * mmap_file.cpp
 *
 *  Created on: Jun 20, 2017
 *      Author: ruanbo
 */

#include "comm/comm.hpp"

#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

void op_file()
{
    int msize = getpagesize();

    int fd = open("/home/ruanbo/Codes/CppTest/System/mmap.txt", O_RDWR);
    if(fd == -1)
    {
        Log("open mmap.txt failed, errno:%d", errno);
        return;
    }

    //修改文件大小
    ftruncate(fd, msize);
    syncfs(fd);

    struct stat st;
    if((fstat(fd, &st)) == -1)
    {
        Log("fstat mmap.txt failed, errno:%d", errno);
        close(fd);
        return;
    }

    Log("file size:%lu", st.st_size);

    char* mmaped = (char*)mmap(NULL, msize, PROT_READ|PROT_WRITE,
                               MAP_SHARED, fd, 0);
    if(mmaped == (void*)-1)
    {
        Log("mmap() failed.errno:%d", errno);
        close(fd);
        return;
    }

    // 这里可以先close文件句柄，不影响后面通过mmap读写文件
    close(fd);

    string str = "%d-written by mmap\n";
    if(true)
    {
        // 写文件

        int pos = 0;
        char data[20] = { 0 };
        int wr_time = 20;
        for(int i=1; i<=wr_time; ++i)
        {
            sprintf(data, str.data(), i);
            strcpy(mmaped+pos, data);

            pos += strlen(data);
        }
    }

    if(true)
    {
        //　读文件

        char rdata[20] = { 0 };
        strncpy(rdata, mmaped, str.length()-1);
        Log("read mmap.txt by mmap:%s", rdata);
    }

    int ret = munmap((void*)mmaped, msize);
    if(ret == -1)
    {
        Log("munmap() failed, errno:%d", errno);
        //close(fd);
        return;
    }

    Log("\n=end of op_file=");
}



void mmap_file_test()
{

    op_file();
}


