/*
 * =====================================================================================
 *
 *       Filename:  rb_tree.h
 *
 *        Version:  1.0
 *        Created:  05/01/2016 05:30:09 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Seth Lienemann (sal), sethlienemann@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef RB_TREE_H
#define RB_TREE_H

enum color_type
    {
    BLACK,
    RED
    };

typedef struct set_type set;
struct set_type
    {
    void            * data;
    struct set_type * parent;
    struct set_type * left;
    struct set_type * right;
    enum color_type   color;
    };

void insert_node 
    ( 
    set * root,
    set * node,
    int (*compare)(void *, void *)
    );

#endif
