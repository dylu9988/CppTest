/*
 * FixMsgOp.cpp
 *
 *  Created on: Mar 13, 2016
 *      Author: ruanbo
 */

#include <FixMsg/FixMsgOp.hpp>
#include <boost/algorithm/string/regex.hpp>
#include <boost/lexical_cast.hpp>
#include <vector>
#include <fstream>

FixMsgOp::FixMsgOp()
{
    _msgs.clear();
}

FixMsgOp::~FixMsgOp()
{
    _msgs.clear();
}

int FixMsgOp::check_valid(const std::string& msg)const
{
    boost::regex new_order_re(NEW_ORDER_KEY);
    boost::regex qty_re(QTY_KEY);
    std::vector<std::string> new_order_ret;
    std::vector<std::string> qty_ret;

    boost::find_all_regex(new_order_ret, msg, new_order_re);
    if(new_order_ret.size() != 1)
    {
        return -1;
    }

    boost::find_all_regex(qty_ret, msg, qty_re);
    if(qty_ret.size() != 1)
    {
        return -1;
    }

    std::string qty_no(qty_ret[0], 4, qty_ret[0].size());
    return boost::lexical_cast<int>(qty_no);
}

void FixMsgOp::input_msg(const std::string& input_file)
{
    std::ifstream input;
    input.open(input_file.data(), std::ios::in);
    if(input.is_open() == false)
    {
        return;
    }

    std::string line_str = "";
    while(getline(input, line_str))
    {
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
    }

    input.close();
}
void FixMsgOp::ouput_msg(const std::string& output_file)
{
    std::ofstream output;
    output.open(output_file.data(), std::ios::out);
    if(output.is_open() == false)
    {
        return;
    }

    for(std::map<int, std::string>::const_iterator it=_msgs.begin(); it!=_msgs.end(); ++it)
    {
        output << it->second << std::endl;
    }

    output.close();
}

void FixMsgOp::read_msg_ouput(const std::string& input_file, const std::string& output_file)
{
    input_msg(input_file);
    ouput_msg(output_file);

}
