/*
 * docker_head.hpp
 *
 *  Created on: Sep 5, 2017
 *      Author: ruanbo
 */

#ifndef DOCKER_HEAD_HPP_
#define DOCKER_HEAD_HPP_

void docker_base_clone();

void uts_namespace();

void ipc_namespace();

void pid_namespace();

void mount_namespace();

void docker_base_test()
{

//    docker_base_clone();

//    uts_namespace();

//    ipc_namespace();

//    pid_namespace();

    mount_namespace();

}




#endif /* DOCKER_HEAD_HPP_ */
