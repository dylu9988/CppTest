/*
 * file_op.cpp
 *
 *  Created on: Mar 10, 2016
 *      Author: ruanbo
 */


#include <boost/filesystem.hpp>
#include <string>
#include <fstream>
#include <boost/lexical_cast.hpp>
#include <map>
#include <boost/regex.hpp>
#include <boost/algorithm/string/regex.hpp>
#include <comm/Log.hpp>
#include <regex>
#include <vector>

class NewOrderItem
{
private:
    int _qty;
    std::string _fix_msg;

public:

};

class RaiiFile
{
private:
#define NEW_ORDER_KEY  "35=D"
#define QTY_KEY "38=[0-9]+"

    std::map<int, std::string> _msgs;

public:
    RaiiFile(const std::string& file_name="")
    {
//        Log("RaiiFile");
    }

    ~RaiiFile()
    {
//        Log("~RaiiFile");
    }

    void read_data()
    {
        Log("read_data()");

        std::fstream _file_stream;
        _file_stream.open("boost/test.txt");

        if(_file_stream.is_open() == false)
        {
            Log("read test.txt error");
            return;
        }

        std::string _line_str;
        while(getline(_file_stream, _line_str))
        {
            Log("%s", _line_str.data());
        }


        _file_stream.close();
    }

    void read_data2()
    {
        Log("read_data2()");

        std::ifstream fin("boost/test.txt");
        if(!fin)
        {
            Log("error open test.txt");
        }

        std::string _line_str = "";
        while(getline(fin, _line_str))
        {
            Log("%s", _line_str.data());
        }

        fin.close();
    }

    int check_valid(const std::string& msg)
    {
//        Log("msg:%s", msg.data());
        boost::regex new_order_re(NEW_ORDER_KEY);
        boost::regex qty_re(QTY_KEY);
        std::vector<std::string> new_order_ret;
        std::vector<std::string> qty_ret;

        boost::find_all_regex(new_order_ret, msg, new_order_re);
//        Log("new_order_ret.size():%d", (int)new_order_ret.size());
        if(new_order_ret.size() != 1)
        {
//            Log("error new order size:%d", (int)new_order_ret.size());
            return -1;
        }

        boost::find_all_regex(qty_ret, msg, qty_re);
//        Log("qty_ret.size():%d", (int)qty_ret.size());
        if(qty_ret.size() != 1)
        {
//            Log("error qty_ret size:%d", (int)qty_ret.size());
            return -1;
        }

//        Log("qty match:%s", qty_ret[0].data());
        std::string qty_no(qty_ret[0], 4, qty_ret[0].size());

        return boost::lexical_cast<int>(qty_no);
    }

    void read_fix()
    {
        std::ifstream fix;
        fix.open("boost/fix42_input_msg.log");
        if(fix.is_open() == false)
        {
            Log("error open fix42_input_msg.log");
        }

        std::string line_str = "";
        while(getline(fix, line_str))
        {
//            Log("str:%s", line_str.data());
            int qty_no = check_valid(line_str);
            if(qty_no < 0)
            {
                continue;
            }

            if(_msgs.find(qty_no) != _msgs.end())
            {
                continue;
            }

            _msgs[qty_no] = line_str;

            Log("%s", line_str.data());
        }

        fix.close();

        output_msg();
    }

    void output_msg()
    {
        std::ofstream out_file;
        out_file.open("boost/fix42_output_msg.log", std::ios::out);
        if(out_file.is_open() == false)
        {
            return;
        }

        for(std::map<int, std::string>::const_iterator it=_msgs.begin(); it!=_msgs.end(); ++it)
        {
            Log("output:%s", it->second.data());
            out_file << it->second << std::endl;
//            out_file.write(it->second.data(), it->second.size());
        }

        out_file.close();
    }

    void regex_test()
    {
        boost::regex qty_pat("38=[0-9]+");
        std::string msg = "test38=1:ruanbo38=2";
        boost::smatch match;
        bool ret = boost::regex_search(msg, match, qty_pat);

        Log("ret = %d, match size=%d", ret, (int)match.size());
        for(size_t i=0; i<match.size(); ++i)
        {
            if(match[i].matched)
            {
                std::cout << match[i] << std::endl;
            }
        }
    }
    void std_regex_test()
    {
        std::string s("this subject has a submarine as");

    }

    void boost_algo_regex()
    {
        std::string line_str = "test:38=100robert38=99kingsoft";
        boost::regex pat("38=[0-9]+");
        std::vector<std::string> rets;

        boost::find_all_regex(rets, line_str, pat);

        for(size_t i=0; i<rets.size(); ++i)
        {
            Log("%s", rets[i].data());
        }
    }
};



void boost_file_op()
{
    RaiiFile rf;

//    rf.read_data();
//    rf.read_data2();
//    rf.regex_test();
//    rf.boost_algo_regex();
//    rf.read_fix();

//    {
//        std::string line_str = "20120315-03:55:42.401 : 8=FIX.4.29=6735=A49=CM_INI56=CM_ACC34=152=20120315-03:55:42.40098=0108=6010=12635=D38=10";
//        int qty_no = rf.check_valid(line_str);
//        Log("qty_no = %d", qty_no);
//    }


//    std::string fix = "20120315-03:55:42.401 : 8=FIX.4.29=6735=A49=CM_INI56=CM_ACC34=152=20120315-03:55:42.40098=0108=6010=126";
//    int i = fix.find("8=FIX.4.2test");
//    Log("fix[%d] = %c", i, fix[i]);
//    Log("fix[33]=%c", fix[33]);


    Log("end of boost file operation");
}


