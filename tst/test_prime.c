/*
 * =====================================================================================
 *
 *       Filename:  test_prime.c
 *
 *    Description:  Tests to test all of the functionality for prime numbers
 *    using CUnit
 *
 *        Version:  1.0
 *        Created:  04/17/2016 03:25:02 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Seth Lienemann (sal), sethlienemann@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include    <stdint.h>
#include    <stdlib.h>
#include    <CUnit/CUnit.h>

#include    "test_prime.h"
#include    "prime.h"

int setup_prime_suite
    (
    void
    )
{
CU_pSuite pSuite = NULL;
pSuite = CU_add_suite(
            "Prime Number Test Suite", 
            init_prime_suite, 
            clean_prime_suite);
if(NULL == pSuite)
    {
    return -1;
    }
/* Add more tests here as functions are developed */
if((NULL == CU_add_test(pSuite, "Testing is_prime()", test_is_prime)))
    {
    return -1;
    }
return 0;
}

int init_prime_suite
    (
    void
    )
{
return 0;
}

int clean_prime_suite
    (
    void
    )
{
return 0;
}

void test_is_prime
    (
    void
    )
{
CU_ASSERT_FALSE(is_prime(9));
CU_ASSERT_TRUE(is_prime(2));
CU_ASSERT_TRUE(is_prime(3));
CU_ASSERT_TRUE(is_prime(97));
}

