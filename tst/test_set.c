/*
 * =====================================================================================
 *
 *       Filename:  test_set.c
 *
 *    Description:  Testing for the set object.
 *
 *        Version:  1.0
 *        Created:  05/02/2016 10:11:02 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Seth Lienemann (sal), sethlienemann@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include    <stdlib.h>
#include    <CUnit/CUnit.h>

#include    "test_set.h"
#include    "list.h"
#include    "rb_tree.h"
#include    "set.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  init_set_suite
 *  Description:  Performs the initialization of the set suite
 * =====================================================================================
 */
int init_set_suite 
    ( 
    void
    )
{
return 0;
}		/* -----  end of function init_set_suite  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  clean_set_suite
 *  Description:  Performs the cleanup for the set suite.
 * =====================================================================================
 */
int clean_set_suite 
    ( 
    void
    )
{
return 0;
}		/* -----  end of function clean_set_suite  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  setup_set_suite
 *  Description:  initializes the set suite, and runs the set tests
 * =====================================================================================
 */
int setup_set_suite
    (
    void 
    )
{
CU_pSuite pSuite = NULL;
pSuite = CU_add_suite(
            "Set Test Suite",
            init_set_suite,
            clean_set_suite);
if(NULL == pSuite)
    {
    return -1;
    }
/* Add more tests here as functions are developed */
if((NULL == CU_add_test(pSuite, "to_list()", test_to_list)          )
|| (NULL == CU_add_test(pSuite, "add_set_node()", test_add_set_node))
|| (NULL == CU_add_test(pSuite, "new_set_node()", test_new_set_node)))
    {
    return -1;
    }
return 0;
}		/* -----  end of function setup_set_suite  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  test_new_set_node
 *  Description:  
 * =====================================================================================
 */
void test_new_set_node
    (
    void
    )
{
set * node = new_set_node();
CU_ASSERT_PTR_NOT_NULL(node);
CU_ASSERT_PTR_NULL(node->parent);
CU_ASSERT_PTR_NULL(node->left);
CU_ASSERT_PTR_NULL(node->right);
CU_ASSERT_EQUAL(node->color, BLACK);

}		/* -----  end of function test_new_set_node  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  test_add_set_node
 *  Description:  
 * =====================================================================================
 */
void test_add_set_node 
    ( 
    void
    )
{
set * root = new_set_node();
int * data;
root->data = malloc(sizeof(int));
*(int *)(root->data) = 4;
data = malloc(sizeof(int));
*data = 2;
add_set_node(root, data, compare_int);
CU_ASSERT_EQUAL(*(int *)(root->left->data), 2);
}		/* -----  end of function test_add_set_node  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  test_to_list
 *  Description:  Test the to_list() function
 * =====================================================================================
 */
void test_to_list 
    ( 
    void
    )
{
}		/* -----  end of function test_to_list  ----- */

int compare_int
    (
    void * vala, 
    void * valb
    )
{
if(*(int *)(vala) < *(int *)(valb))
    {
    return -1;
    }
else if(*(int *)(vala) > *(int *)(valb))
    {
    return 1;
    }
else
    {
    return 0;
    }
}
