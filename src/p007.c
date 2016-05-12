/*
 * =====================================================================================
 *
 *       Filename:  p007.c
 *
 *    Description:  Project Euler Problem 7 
 *
 *    By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can
 *    see that the 6th prime is 13.  
 *
 *    What is the 10 001st prime number?
 *
 *        Version:  1.0
 *        Created:  05/11/2016 08:32:01 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include    <stdio.h>
#include    <stdint.h>
#include	<stdlib.h>
#include    "prime.h"

#define LIMIT (10001)

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
uint64_t i = 1;
uint32_t num_primes = 0;

/* Solve it using brute force because it's a small enough number */
while(num_primes < LIMIT)
    {
    i++;
    if(is_prime(i))
        {
        num_primes++;
        }
    }
printf("The %ust prime is: %lu\n", num_primes, i);
return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
