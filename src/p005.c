/*
 * =====================================================================================
 *
 *       Filename:  p005.c
 *
 *    Description:  Project Euler Problem 5
 *
 *    2520 is the smallest number that can be divided by each of the numbers
 *    from 1 to 10 without any remainder. 
 *    
 *    What is the smallest positive number that is evenly divisible by all of
 *    the numbers from 1 to 20?
 *
 *        Version:  1.0
 *        Created:  04/30/2016 11:36:47 AM
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

#include    "set.h"
#include    "prime.h"
#include    "list.h"

#define LIMIT (20)

int comp_uint32_t
    (
    void * valA,
    void * valB
    );

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
uint64_t answer = 1;
uint32_t i;
uint32_t j;
uint32_t num;
uint8_t num_factors[LIMIT];
uint8_t cur_num_factors[LIMIT];
list * cur_factors;
node * cur;
/* loop through all of the numbers up to the limit */
for(i = 0; i < LIMIT; i++)
    {
    num_factors[i] = 0;
    }
for(i = 2; i <= LIMIT; i++)
    {
    cur_factors = prime_factors(i);
    cur = get_head(cur_factors);
    for(j = 0; j < LIMIT; j++)
        {
        cur_num_factors[j] = 0;
        }
    /* Add each factor to the all_factors set */
    while(cur != NULL)
        {
        num = *(uint64_t *)(cur->data);
        cur_num_factors[num]++;
        cur = cur->next;
        }
    for(j = 0; j < LIMIT; j++)
        {
        if(cur_num_factors[j] > num_factors[j])
            {
            num_factors[j] = cur_num_factors[j];
            }
        }
    }
/* Now loop through all of the factors, multiplying them */
for(i = 0; i < LIMIT; i++)
    {
    while(num_factors[i] > 0)
        {
        answer *= i;
        num_factors[i]--;
        }
    }
printf("The answer is: %lu\n", answer);
return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
