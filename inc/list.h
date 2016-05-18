/*
 * =====================================================================================
 *
 *       Filename:  list.h
 *
 *        Version:  1.0
 *        Created:  04/17/2016 12:36:29 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Seth Lienemann (sal), sethlienemann@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef  LIST_H
#define  LIST_H

#include    <stdint.h>

typedef struct node_type node;
struct node_type
    {
    void             * data;
    struct node_type * prev;
    struct node_type * next;
    };

typedef struct list_type list;
struct list_type
    {
    uint32_t size;
    node   * head;
    node   * tail;
    };

/* Add an element to the end of the given list */
void add
    (
    list * lst,
    void * elem,
    size_t elem_sz
    );

/* get the first element of the given list */
node * get_head
    (
    list * lst
    );

/* get the last element of the given list */
node * get_tail
    (
    list * lst
    );

/* Create a new list and return a pointer to it */
list * make_new_list
    (
    void
    );

/* Add an element to the beginning of the given list */
void prepend
    (
    list * lst,
    void * elem,
    size_t elem_sz
    );

/* remove the nth element (0-based) */
node * remove_element
    (
    list * lst,
    uint32_t n
    );

#endif   /* ----- #ifndef LIST_H    ----- */
