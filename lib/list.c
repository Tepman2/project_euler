/*
 * =====================================================================================
 *
 *       Filename:  list.c
 *
 *    Description:  Implements the functionality behind a generic list data structure
 *
 *        Version:  1.0
 *        Created:  04/17/2016 12:17:29 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Seth Lienemann (sal), sethlienemann@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include    <assert.h>
#include	<stdlib.h>
#include    <stdint.h>
#include    <string.h>
#include    "list.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  get_head
 *  Description:  
 * =====================================================================================
 */
node * get_head
    (
    list * lst
    )
{
assert(lst != NULL);
return lst->head;
}		/* -----  end of function get_head  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  get_tail
 *  Description:  Gives the given list's tail element.
 * =====================================================================================
 */
node * get_tail
    (
    list * lst
    )
{
assert(lst != NULL);
return lst->tail;
}		/* -----  end of function get_tail  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  add
 *  Description:  Adds the given element at the end of the linked list
 * =====================================================================================
 */
void add
    (
    list * lst,
    void * elem,
    size_t elem_sz
    )
{
assert(lst != NULL);
assert(elem != NULL);
assert(elem_sz != 0);
node * new_elem = malloc(sizeof(node));
new_elem->data = malloc(elem_sz);
memcpy(new_elem->data, elem, elem_sz);
new_elem->prev = lst->tail;
/* If this is the first element */
if(lst->head == NULL)
    {
    lst->head = new_elem;
    }
else
    {
    lst->tail->next = new_elem;
    }
lst->tail = new_elem;
lst->size++;
}		/* -----  end of function add  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  remove_element
 *  Description:  Removes the element at the specified position from the list
 * =====================================================================================
 */
node * remove_element
    (
    list * lst,
    uint32_t n
    )
{
assert(lst != NULL);
assert(n >= 0);
assert(n < lst->size);
node * node_to_remove;
/* We're removing the first element */
if(n == 0)
    {
    node_to_remove = get_head(lst);
    lst->head = node_to_remove->next;
    node_to_remove->next->prev = NULL;
    lst->size--;
    }
else if(n == (lst->size - 1))
    {
    node_to_remove = get_tail(lst);
    lst->tail = node_to_remove->prev;
    node_to_remove->prev->next = NULL;
    lst->size--;
    }
else
    {
    node_to_remove = get_head(lst);
    while(n > 0)
        {
        node_to_remove = node_to_remove->next;
        n--;
        }
    node_to_remove->next->prev = node_to_remove->prev;
    node_to_remove->prev->next = node_to_remove->next;
    lst->size--;
    }
return node_to_remove;
}		/* -----  end of function remove_element  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  prepend
 *  Description:  Adds the given element to a new node at the front of the set
 * =====================================================================================
 */
void prepend
    (
    list * lst,
    void * elem,
    size_t elem_sz
    )
{
assert(lst != NULL);
assert(elem != NULL);
node * new_elem = malloc(sizeof(node));
new_elem->data = malloc(elem_sz);
memcpy(new_elem->data, elem, elem_sz);
new_elem->next = lst->head;
if(lst->tail == NULL)
    {
    lst->tail = new_elem;
    }
else
    {
    (lst->head)->prev = new_elem;
    }
lst->head = new_elem;
lst->size++;
}		/* -----  end of function prepend  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  make_new_list
 *  Description:  Creates a new list
 * =====================================================================================
 */
list * make_new_list
    (
    void
    )
{
list * new_list = malloc(sizeof(list));
new_list->head = NULL;
new_list->tail = NULL;
new_list->size = 0;
return new_list;
}		/* -----  end of function make_new_list  ----- */
