/*
 * =====================================================================================
 *
 *       Filename:  test_set.h
 *
 *        Version:  1.0
 *        Created:  05/09/2016 07:27:04 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Seth Lienemann (sal), sethlienemann@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef TEST_SET_H
#define TEST_SET_H
int init_set_suite
    (
    void
    );

int clean_set_suite
    (
    void
    );

int setup_set_suite
    (
    void
    );

void test_new_set_node
    (
    void
    );

void test_add_set_node 
    ( 
    void
    );

void test_to_list 
    ( 
    void
    );

int compare_int
    (
    void * vala, 
    void * valb
    );

#endif
