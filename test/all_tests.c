/*
 * =====================================================================================
 *
 *       Filename:  all_tests.c
 *
 *    Description:  Runs all tests using CUnit
 *
 *        Version:  1.0
 *        Created:  04/17/2016 09:19:22 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Seth Lienemann (sal), sethlienemann@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */


#include    <CUnit/CUnit.h>
#include    <CUnit/Automated.h>
#include    "test_prime.h"
#include    "test_list.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main
    ( 
    int argc, 
    char *argv[] 
    )
{
    if(CUE_SUCCESS != CU_initialize_registry())
        {
        return CU_get_error();
        }
    CU_set_output_filename("Project Euler");

    /* Create the suites */
    if((-1 == setup_prime_suite())
    || (-1 == setup_list_suite() ))
        {
        CU_cleanup_registry();
        return CU_get_error();
        }

    /* Run tests */
    CU_automated_run_tests();

    /* Finish up */
    CU_cleanup_registry();
    return CU_get_error();
}				/* ----------  end of function main  ---------- */

