/*
 * =====================================================================================
 *
 *       Filename:  p003.c
 *
 *    Description:  Project Euler Problem 3
 *    
 *    The prime factors of 13195 are 5, 7, 13 and 29.
 *    
 *    What is the largest prime factor of the number 600851475143 ?
 *
 *        Version:  1.0
 *        Created:  04/19/2016 04:16:33 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Seth Lienemann (sal), sethlienemann@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include    <stdio.h>
#include    <stdint.h>
#include	<stdlib.h>
#include    "list.h"
#include    "prime.h"

#define LIMIT (600851475143UL)

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
    list * factors = prime_factors( LIMIT );
    printf("The answer is: %d\n", *(uint32_t *)(get_tail(factors)->data));
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

