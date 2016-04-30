/*
 * =====================================================================================
 *
 *       Filename:  p001.c
 *
 *    Description:  Project Euler Problem 1
 *
 *    If we list all the natural numbers below 10 that are multiples of 3 or 5,
 *    we get 3, 5, 6 and 9. The sum of these multiples is 23.
 *
 *    Find the sum of all the multiples of 3 or 5 below 1000.
 *
 *        Version:  1.0
 *        Created:  04/17/2016 09:55:57 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Seth Lienemann (sal), sethlienemann@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include	<stdlib.h>
#include    <stdint.h>
#include    <stdio.h>

#define LIMIT (1000)
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main 
    ( 
    int argc,
    char * argv[]
    )
{
uint32_t ret_val = 0;
uint32_t i;

for(i = 1; i < LIMIT; i++)
    {
    if(((i % 3) == 0)
    || ((i % 5) == 0))
        {
        ret_val += i;
        }
    }
printf("The answer is: %d\n", ret_val);
return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

