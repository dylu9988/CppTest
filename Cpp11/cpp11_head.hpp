/*
 * cpp11_head.hpp
 *
 *  Created on: Apr 21, 2016
 *      Author: ruanbo
 */

#ifndef CPP11_HEAD_HPP_
#define CPP11_HEAD_HPP_




#include <comm/Log.hpp>


void cpp11_loop();

void cpp_template_test();

void random_tests();

void move_test();

void move2_test();

void forward_test();

void emplace_test();

void shared_ptr_tests();

void override_tests();

void unordered_map_test();

void cpp11_entrys()
{
//    cpp11_loop();

//    cpp_template_test();

//    random_tests();

//    move_test();

//    move2_test();

//    forward_test();

//    emplace_test();

//    shared_ptr_tests();

//    override_tests();

    unordered_map_test();


    Log("\n===== end of cpp11 tests=======");
}


#endif /* CPP11_HEAD_HPP_ */
