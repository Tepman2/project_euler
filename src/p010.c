/*
 * =====================================================================================
 *
 *       Filename:  p010.c
 *
 *    Description:  Project Euler Problem 10 
 *
 *    The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.  
 *
 *    Find the sum of all the primes below two million.
 *
 *        Version:  1.0
 *        Created:  05/13/2016 09:14:41 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Seth Lienemann(sal), sethlienemann@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include    <stdio.h>
#include	<stdlib.h>
#include    <string.h>
#include    "prime.h"
#include    "list.h"

#define LIMIT (2000000)

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
list * primes = sieve_of_eratosthenes(LIMIT);
node * cur_val = get_head(primes);
uint64_t sum_val = 0;

while(cur_val != NULL)
    {
    sum_val += *(uint64_t *)cur_val->data;
    cur_val = cur_val->next;
    }
printf("The sum of the primes under %d are: %lu\n", LIMIT, sum_val);
return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

