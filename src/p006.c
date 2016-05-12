/*
 * =====================================================================================
 *
 *       Filename:  p006.c
 *
 *    Description:  Project Euler Problem 6
 *
 *    The sum of the squares of the first ten natural numbers is, 
 *    1^2 + 2^2 + ... + 10^2 = 385 
 *
 *    The square of the sum of the first ten natural numbers is, 
 *    (1 + 2 + ... + 10)^2 = 55^2 = 3025 
 *
 *    Hence the difference between the sum of the squares of the first ten
 *    natural numbers and the square of the sum is 3025 − 385 = 2640.  
 *
 *    Find the difference between the sum of the squares of the first one
 *    hundred natural numbers and the square of the sum.
 *
 *        Version:  1.0
 *        Created:  05/11/2016 07:27:54 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Seth Lienemann (sal), sethlienemann@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include	<stdlib.h>
#include    <stdio.h>
#include    <stdint.h>

#define LIMIT ( 100 )
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
uint32_t i;
uint32_t sum_i;
uint64_t sum_of_squares;
uint64_t square_of_sum;
sum_i = 0;
sum_of_squares = 0;
for(i = 1; i <= LIMIT; i++)
    {
    sum_i += i;
    sum_of_squares += i * i;
    }
square_of_sum = sum_i * sum_i;
 
printf("The answer is: %lu\n", square_of_sum - sum_of_squares );
return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
