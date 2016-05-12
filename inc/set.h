/*
 * =====================================================================================
 *
 *       Filename:  set.h
 *
 *        Version:  1.0
 *        Created:  05/01/2016 05:27:32 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Seth Lienemann (sal), sethlienemann@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef SET_H
#define SET_H

#include    "rb_tree.h"
#include    "list.h"

set * new_set_node
    (
    void
    );

void add_set_node
    ( 
    set * root,
    void * data,
    int (*compare)(void *, void *)
    );

list * to_list
    (
    set * old_set
    );

#endif
