/*
 * =====================================================================================
 *
 *       Filename:  test_string.c
 *
 *    Description:  Test string functionality
 *
 *        Version:  1.0
 *        Created:  04/30/2016 10:46:40 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Seth Lienemann (sal), sethlienemann@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include    <stdint.h>
//#include    <stdlib.h>
#include    <CUnit/CUnit.h>
#include    "test_string.h"
#include    "string.h"

int setup_string_suite
    (
    void
    )
{
CU_pSuite pSuite = NULL;
pSuite = CU_add_suite(
            "String Suite",
            init_string_suite,
            clean_string_suite);
if(NULL == pSuite)
    {
    return -1;
    }
/* Add more tests here as functions are developed */
if((NULL == CU_add_test(pSuite, "Testing is_palindrome()", test_is_palindrome)))
    {
    return -1;
    }
return 0;
}

int init_string_suite
    (
    void
    )
{
return 0;
}

int clean_string_suite
    (
    void
    )
{
return 0;
}

void test_is_palindrome
    (
    void
    )
{
CU_ASSERT_FALSE(is_palindrome(12));
CU_ASSERT_TRUE(is_palindrome(1));
CU_ASSERT_TRUE(is_palindrome(131));
CU_ASSERT_TRUE(is_palindrome(12321));
CU_ASSERT_TRUE(is_palindrome(1001));
}
