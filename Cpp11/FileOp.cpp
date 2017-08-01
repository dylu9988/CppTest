/*
 * FileOp.cpp
 *
 *  Created on: Jul 31, 2017
 *      Author: ruanbo
 */

#include "comm/comm.hpp"
#include <fstream>

#include <sys/stat.h>


bool is_directory(const string& f)
{
    struct stat st;
    if(stat(f.data(), &st) != 0)
    {
        return false;
    }

    if(S_ISDIR(st.st_mode))
    {
        return true;
    }
    else
    {
        return false;
    }
}
void create_folder(string& f)
{
    size_t len = f.length();
    if(len <= 1)
    {
        return;
    }

    for(size_t i = 1; i<len; ++i)
    {
        if(f[i] == '/')
        {
            string parent_dir(f, 0, i);
            Log("dir:%s", parent_dir.data());

            if(is_directory(parent_dir) == false)
            {
                int ret = mkdir(parent_dir.data(), 0755);
                if(ret != 0)
                {
                    Log("mkdir(%s),errno:%d", parent_dir.data(), errno);
                }
                else
                {
                    Log("mkdir ret:%d", ret);
                }
            }
        }
    }

}

void folder_exist()
{
    {
        string f1 = "/home/ruanbo/Codes/CppTest/Cpp11/Data2";
        struct stat st;
        if(stat(f1.data(), &st) != 0)
        {
            Log("%s is not a folder", f1.data());
            return;
        }

        if(S_ISDIR(st.st_mode))
        {
            Log("%s is a folder", f1.data());
        }
        else
        {
            Log("%s is not a folder 2", f1.data());
        }
    }


}


void file_create_test()
{
    fstream f;
    f.open("/home/ruanbo/Codes/CppTest/Cpp11/Data/FileCreate.txt", ios::out);
    if(f.is_open() == false)
    {
        Log("open file failed, errno:%d", errno);
        return;
    }
    else
    {
        Log("create file ok");
    }

    f.close();
}


void file_op_tests()
{
//    file_create_test();

//    folder_exist();

    string f = "/home/ruanbo/Codes/CppTest/Cpp11/Data2/";
    create_folder(f);

}



