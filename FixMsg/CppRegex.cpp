
#include <comm/Log.hpp>
#include <regex>
#include <string>
#include <iostream>


void std_regex_test()
{
    using namespace std;

    Log("std_regex_test");

    regex reg("38=[0-9]");
    string strIn = "38=123 is http://www.owent.net/";
    std::smatch res;


    bool isUrl = std::regex_search(strIn, res, reg);
    cout<< (isUrl? "It's a url": "It's not a url")<< endl;


    Log("end of std_regex_test()");
}
