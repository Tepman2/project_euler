/*
 * =====================================================================================
 *
 *       Filename:  set.c
 *
 *    Description:  Set data structure using a Red-Black Tree
 *
 *        Version:  1.0
 *        Created:  04/30/2016 12:39:36 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Seth Lienemann (sal), sethlienemann@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include	<stdlib.h>
#include    <assert.h>
#include    "list.h"
#include    "rb_tree.h"
#include    "set.h"

static void set_to_list
    (
    set * old_set,
    list * new_list
    );

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  new_set_node
 *  Description:  Creates a new set node that is ready to be used by other functions
 * =====================================================================================
 */
set * new_set_node
    (
    void
    )
{
// Initialize the set data structure, and return it
set * new_node = malloc(sizeof(set));

assert(new_node != NULL);

new_node->parent = NULL;
new_node->left = NULL;
new_node->right = NULL;
new_node->color = BLACK;
    
return new_node;
}		/* -----  end of function new_set_node  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  add_set_node
 *  Description:  Adds an item to the set using the provided comparison
 * =====================================================================================
 */
void add_set_node
    ( 
    set * root,
    void * data,
    int (*compare)(void *, void *)
    )
{
set * node = new_set_node();
/* Ensure non-null parameters */
assert(node != NULL);
assert(data != NULL);
assert(root != NULL);
node->data = data;
insert_node(root, node, compare);
}		/* -----  end of function add  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  to_list
 *  Description:  
 * =====================================================================================
 */
list * to_list
    (
    set * old_set
    )
{
list * new_list = make_new_list();
assert(old_set != NULL);
assert(new_list != NULL);
set_to_list(old_set, new_list);
return new_list;
}		/* -----  end of function to_list  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  set_to_list
 *  Description:  Local function to be called recursively to add all values
 *  from the old set to the new list
 * =====================================================================================
 */
static void set_to_list
    ( 
    set *  old_set,
    list * new_list
    )
{
assert(new_list != NULL);
assert(old_set != NULL);
if(old_set->data == NULL)
    {
    return;
    }
/* Perform postfix to put data in "order" */
if(old_set->left != NULL)
    {
    set_to_list(old_set->left, new_list);
    }
if(old_set->right != NULL)
    {
    set_to_list(old_set->right, new_list);
    }
add(new_list, old_set->data);
}		/* -----  end of function set_to_list  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  delete_set_node
 *  Description:  Removes the given set node from the set given by the root
 *  using the given comparison function
 * =====================================================================================
 */
//void delete_set_node
//    ( 
//    set * root,
//    set * node,
//    int (*compare)(void *, void *)
//    )
//{
//assert(root != NULL);
//set * n = root;
///* Find the node to be removed */
///* Remove if the node has only leaves as children (NULL) */
//if((n->right == NULL)
//&& (n->left == NULL ))
//    {
//    free(n);
//    }
///* Remove if the node has two non-leaf children */
//else if((n->right != NULL)
//     && (n->left  != NULL))
//    {
//    delete_two_children(node);
//    }
///* Remove if the node has only one non-leaf child */
//else
//    {
//    delete_one_child(node);
//    }
//}		/* -----  end of function delete_set_node  ----- */
