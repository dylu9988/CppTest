/*
 * FixMsgOp.hpp
 *
 *  Created on: Mar 13, 2016
 *      Author: ruanbo
 */

#ifndef FIXMSGOP_HPP_
#define FIXMSGOP_HPP_

#include <string>
#include <map>


class FixMsgOp
{
#define NEW_ORDER_KEY  "35=D"
#define QTY_KEY "38=[0-9]+"

private:
    std::map<int, std::string> _msgs;  //key:qty no of the new order, value:new order msg

public:
    FixMsgOp();
    virtual ~FixMsgOp();

private:
    int check_valid(const std::string& msg)const;

    void input_msg(const std::string& input_file);
    void ouput_msg(const std::string& output_file);

public:
    void read_msg_ouput(const std::string& input_file="fix42_input_msg.log", const std::string& output_file="fix42_output_msg.log");
};

#endif /* FIXMSGOP_HPP_ */
