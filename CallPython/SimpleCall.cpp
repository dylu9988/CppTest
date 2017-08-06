/*
 * SimpleCall.cpp
 *
 *  Created on: 2017年8月5日
 *      Author: ruanbo
 */

#include "comm/comm.hpp"
#include "python2.7/Python.h"

void none_param_ret_int()
{
    char path[128] = { 0 };
    memset(path, 0, sizeof(path));
    getcwd(path, 128);
    Log("path:%s", path);

    Py_Initialize();
    if(!Py_IsInitialized())
    {
        Log("Py_Initialize failed");
        return;
    }

    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('/home/ruanbo/Codes/CppTest/CallPython')");

    PyObject *pName, *pModule;

    pName = PyString_FromString("pyfuncs");
    pModule = PyImport_Import(pName);
    if(!pModule)
    {
        Log("PyImport_Import test failed");
        Py_Finalize();
        return;
    }

    PyObject *pDict = PyModule_GetDict(pModule);
    if(!pDict)
    {
        Log("PyModule_GetDict failed");
        Py_Finalize();
        return;
    }

    PyObject *list = PyDict_Keys(pDict);
    Py_ssize_t n = PyList_Size(list);
    Py_ssize_t i = 0;
    for (i = 0; i < n; i++)
    {
        PyObject *obj = PyList_GetItem(list, i);
        char *key = PyString_AsString(obj);
        Log("key:%s", key);

        Py_DECREF(obj);
    }

    PyObject* pFunc = PyObject_GetAttrString(pModule, "ret_int");
    if(!pFunc)
    {
        Log("PyObject_GetAttrString callable failed");
        //PyErr_SetString(PyExc_TypeError, "function not found");
        Py_Finalize();
        return;
    }
    if(!PyCallable_Check(pFunc))
    {
        Log("PyObject_GetAttrString callable: not callable");
        Py_Finalize();
        return;
    }

    PyObject *pRet = PyObject_CallObject(pFunc, NULL);
    if(!pRet)
    {
        Log("PyObject_CallObject failed");
        Py_Finalize();
        return;
    }

    long ret = PyInt_AsLong(pRet);

    Log("ret from python:%ld", ret);

    Py_DecRef(pRet);
    Py_DecRef(pFunc);

    Py_DecRef(pName);
    Py_DecRef(pModule);

    Py_Finalize();
}

void run_string()
{
    Py_Initialize();
    if(!Py_IsInitialized())
    {
        Log("Py_Initialize failed");
        return;
    }

//    PyRun_SimpleString("print 'Hello From c++ call'");

    Py_Finalize();
}

void call_py_param_ret()
{
    Py_Initialize();
    if(!Py_IsInitialized())
    {
        Log("Py_Initialize failed");
        return;
    }

    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('/home/ruanbo/Codes/CppTest/CallPython')");

    PyObject *pName, *pModule;

    pName = PyString_FromString("pyfuncs");
    pModule = PyImport_Import(pName);
    if(!pModule)
    {
        Log("PyImport_Import test failed");
        Py_Finalize();
        return;
    }

    if(true)
    {
        PyObject* pFunc = PyObject_GetAttrString(pModule, "AddMulti");
        if(!pFunc)
        {
            Log("PyObject_GetAttrString callable failed");
            Py_Finalize();
            return;
        }
        if(!PyCallable_Check(pFunc))
        {
            Log("PyObject_GetAttrString callable: not callable");
            Py_Finalize();
            return;
        }

        int a = 10, b = 20;
        PyObject *pParam = Py_BuildValue("ii", a, b);

        PyObject *pRet = PyObject_CallObject(pFunc, pParam);
        if(!pRet)
        {
            Log("PyObject_CallObject failed");
            Py_Finalize();
            return;
        }

        Log("pRet size:%lu", PyTuple_Size(pRet));
        int sum = 0, multi = 0;
        if(pRet && PyArg_ParseTuple(pRet, "ii", &sum, &multi))
        {
            Log("a:%d,b:%d, sum:%d, multi:%d", a, b, sum, multi);
        }

        Py_DecRef(pRet);
        Py_DecRef(pParam);
        Py_DecRef(pFunc);
    }

    //返回dict的测试
    if(true)
    {
        PyObject* pFunc = PyObject_GetAttrString(pModule, "ret_dict");
        if(!pFunc)
        {
            Log("PyObject_GetAttrString callable ret_dict failed");
            Py_Finalize();
            return;
        }
        if(!PyCallable_Check(pFunc))
        {
            Log("PyObject_GetAttrString callable: not callable");
            Py_Finalize();
            return;
        }

        PyObject *pRet = PyObject_CallObject(pFunc, NULL);
        if(!pRet)
        {
            Log("PyObject_CallObject ret_dict failed");
            Py_Finalize();
            return;
        }

        Py_ssize_t i = 0;
        PyObject *key;
        PyObject *value;
        while (PyDict_Next(pRet, &i, &key, &value))   //C++中遍历Python的dict对象。此为关键代码
        {
            char * skey = PyString_AS_STRING(key);
            char * svalue = PyString_AS_STRING(value);

            Log("dict[%s] = %s", skey, svalue);
        }

        Py_DecRef(pRet);
        Py_DecRef(pFunc);
    }

    Py_DecRef(pName);
    Py_DecRef(pModule);

    Py_Finalize();
}

void simple_call()
{
	run_string();

//    none_param_ret_int();

//    call_py_param_ret();

}

