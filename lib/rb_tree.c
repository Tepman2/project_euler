/*
 * =====================================================================================
 *
 *       Filename:  rb_tree.c
 *
 *    Description:  Red-Black Tree utility functionality
 *
 *        Version:  1.0
 *        Created:  05/01/2016 11:18:59 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Seth Lienemann (sal), sethlienemann@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include    <stdlib.h>
#include    <assert.h>
#include    "rb_tree.h"
#include    "list.h"

/* #####   FUNCTION DEFINITIONS  -  EXPORTED FUNCTIONS   ############################ */
static set * grandparent
    ( 
    set * child 
    );

static set * uncle 
    ( 
    set * child 
    );

static void insert_case1 
    ( 
    set * n
    );

static void insert_case2 
    ( 
    set * n
    );

static void insert_case3 
    ( 
    set * n
    );

static void insert_case4 
    ( 
    set * n
    );

static void insert_case5 
    ( 
    set * n
    );

static void rotate_left 
    ( 
    set * root
    );

static void rotate_right 
    ( 
    set * root
    );

//static void set_to_list
//    (
//    set *  old_set,
//    list * new_list
//    );


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  insert_node
 *  Description:  
 * =====================================================================================
 */
void insert_node 
    ( 
    set * root,
    set * node,
    int (*compare)(void *, void *)
    )
{
set * set_ptr = root;
set * set_ptr_parent;

/***************************************
*       Insert the actual data         *
***************************************/
/* If there's no data in the root just add the data there */
if(root->data == NULL)
    {
    root->data = node->data;
    }
else
    {
    /* Remember: only unique values are allowed */
    while(set_ptr != NULL)
        {
        if(compare(node->data, set_ptr->data) == 0)
            {
            /* Return since we're trying to insert an item already in the set */
            return;
            }
        else if(compare(node->data, set_ptr->data) < 0)
            {
            set_ptr_parent = set_ptr;
            set_ptr = set_ptr->left;
            }
        else
            {
            set_ptr_parent = set_ptr;
            set_ptr = set_ptr->right;
            }
        }
    /* Decide if the node should be left or right child */
    if(compare(node->data, set_ptr_parent->data) < 0)
        {
        set_ptr_parent->left = node;
        }
    else
        {
        set_ptr_parent->right = node;
        }
    }
node->color = RED;


/***************************************
*        Insertion bookkeeping         *
***************************************/
insert_case1(node);
}		/* -----  end of function insert_node  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  insert_case1
 *  Description:  Covers if this is inserting the root
 * =====================================================================================
 */
static void insert_case1 
    ( 
    set * n
    )
{
if(n->parent == NULL)
    {
    n->color = BLACK;
    }
else
    {
    insert_case2(n);
    }
}		/* -----  end of function insert_case1  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  insert_case2
 *  Description:  Covers the case that the parent's color is BLACK
 * =====================================================================================
 */
static void insert_case2 
    ( 
    set * n
    )
{
if(n->parent->color == BLACK)
    {
    return;
    }
else
    {
    insert_case3(n);
    }
}		/* -----  end of static function insert_case2  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  insert_case3
 *  Description:  Covers the case that the parent and uncle are both RED
 * =====================================================================================
 */
static void insert_case3 
    ( 
    set * n
    )
{
set * u = uncle(n);
set * g;
if((u != NULL      )
&& (u->color == RED))
    {
    n->parent->color = BLACK;
    u->color = BLACK;
    g = grandparent(n);
    g->color = RED;
    insert_case1(g);
    }
else
    {
    insert_case4(n);
    }
}		/* -----  end of static function insert_case3  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  insert_case4
 *  Description:  Covers the case where the parent is RED but the uncle is BLACK
 * =====================================================================================
 */
static void insert_case4 
    ( 
    set * n
    )
{
set * g = grandparent(n);
if((n == n->parent->right)
&& (n->parent == g->left))
    {
    rotate_left(n->parent);
    n = n->left;
    }
else if((n == n->parent->left)
     && (n->parent == g->right))
    {
    rotate_right(n->parent);
    n = n->right;
    }
insert_case5(n);
}		/* -----  end of static function insert_case4  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  insert_case5
 *  Description:  Covers the case that parent is RED but the uncle is BLACK
 * =====================================================================================
 */
static void insert_case5 
    ( 
    set * n
    )
{
set * g = grandparent(n);

n->parent->color = BLACK;
g->color = RED;
if(n == n->parent->left)
    {
    rotate_right(g);
    }
else
    {
    rotate_left(g);
    }
}		/* -----  end of static function insert_case5  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  rotate_left
 *  Description:  Rotates the tree left with the given node as root
 * =====================================================================================
 */
static void rotate_left 
    ( 
    set * root
    )
{
set * pivot = root->right;
/* Start by correcting the parent's pointer */
if(root->parent != NULL)
    {
    /* If we're on the parent's right, replace with the pivot */
    if(root == root->parent->right)
        {
        root->parent->right = pivot;
        }
    /* Otherwise replace the parent's left with the pivot */
    else
        {
        root->parent->left = pivot;
        }
    }
root->parent = pivot;

root->right = pivot->left;
pivot->left = root;
}		/* -----  end of function rotate_left  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  rotate_right
 *  Description:  Rotates the tree right with the given node as the root
 * =====================================================================================
 */
static void rotate_right 
    ( 
    set * root
    )
{
set * pivot = root->left;
/* Take care of the parent's pointers */
if(root->parent != NULL)
    {
    if(root == root->parent->left)
        {
        root->parent->left = pivot;
        }
    else
        {
        root->parent->right = pivot;
        }
    }
root->parent = pivot;

root->left = pivot->right;
pivot->right = root;
}		/* -----  end of static function rotate_right  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  to_list
 *  Description:  Put all of the items in the set into a list
 * =====================================================================================
 */
//list * to_list 
//    ( 
//    set * old_set
//    )
//{
//list * new_list = make_new_list();
//
//set_to_list(old_set, new_list);
//return new_list;
//
//}		/* -----  end of function to_list  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  set_to_list
 *  Description:  
 * =====================================================================================
 */
//static void set_to_list
//    ( 
//    set * old_set, 
//    list * new_list 
//    )
//{
//assert(NULL != old_set);
//assert(NULL != new_list);
//if(NULL == old_set->data)
//    {
//    return;
//    }
///* Perform postfix so as to return the structure in "order" */
//set_to_list(old_set->left, new_list);
//set_to_list(old_set->right, new_list);
//add(new_list, old_set->data);
//}		/* -----  end of function set_to_list  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  delete_one_child
 *  Description:  
 * =====================================================================================
 */
//void delete_one_child 
//    ( 
//    set * n
//    )
//{
//set * child = is_leaf(n->right) ? n->left : n->right;
//
//replace_node(n, child);
//if(n->color == BLACK)
//    {
//    if(child->color == RED)
//        {
//        child->color = BLACK;
//        }
//    else
//        {
//        remove_case1(child);
//        }
//    }
//free(n);
//}		/* -----  end of function delete_one_child  ----- */
//
///* 
// * ===  FUNCTION  ======================================================================
// *         Name:  remove_case1
// *  Description:  Covers the case where removing the node would place the child as root
// * =====================================================================================
// */
//static void remove_case1 
//    ( 
//    set * n
//    )
//{
//  if(n->parent != NULL)
//      {
//      remove_case2(n);
//      }
//}		/* -----  end of static function remove_case1  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  grandparent
 *  Description:  Utility function to return the grandparent of the given child node
 * =====================================================================================
 */
static set * grandparent
    ( 
    set * child 
    )
{
if((child != NULL        )
&& (child->parent != NULL))
    {
    return child->parent->parent;
    }
else
    {
    return NULL;
    }
}		/* -----  end of function grandparent  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  uncle
 *  Description:  Utility function to return the uncle of the given child node
 * =====================================================================================
 */
static set * uncle 
    ( 
    set * child 
    )
{
set * g = grandparent(child);
if(g == NULL)
    {
    /* No grandparent means no uncle */
    return NULL;
    }
if(child->parent == g->left)
    {
    return g->right;
    }
else
    {
    return g->left;
    }
}		/* -----  end of function uncle  ----- */
