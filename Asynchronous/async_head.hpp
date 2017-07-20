/*
 * async_head.hpp
 *
 *  Created on: Jun 21, 2017
 *      Author: ruanbo
 */

#ifndef ASYNC_HEAD_HPP_
#define ASYNC_HEAD_HPP_

void aio_read_file();

void aio_file();

void example_run();

void event_fd_test();

void native_aio_test();

void async_test_entry()
{
//    aio_read_file();

//    aio_file();

//    example_run();

//    event_fd_test();

    native_aio_test();
}




#endif /* ASYNC_HEAD_HPP_ */
