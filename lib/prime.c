/*
 * =====================================================================================
 *
 *       Filename:  prime.c
 *
 *    Description:  Provides all of the functionality for the prime numbers.
 *
 *        Version:  1.0
 *        Created:  04/17/2016 08:11:58 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Seth Lienemann (sal), sethlienemann@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include    <math.h>
#include    <stdint.h>
#include    <stdbool.h>
#include    <stdlib.h>
#include    "list.h"

bool is_prime
    (
    uint64_t num
    )
{
uint64_t i;
// Negative numbers are not prime, as are 0 and 1
if(num < 2)
    {
    return false;
    }
// 2 is the first/only even prime
if(num < 4)
    {
    return true;
    }
// if it's an even number, return now
if((num & 1) == 0)
    {
    return false;
    }
if(num < 9)
    {
    return true;
    }
if((num % 3) == 0)
    {
    return false;
    }
if(num < 25)
    {
    return true;
    }
// Start with 5 and only check odd numbers to sqrt(n)
for(i = 5; i <= (uint64_t)sqrt(num); i += 6)
    {
    if(num % i == 0)
        {
        return false;
        }
    if(num % (i + 2) == 0)
        {
        return false;
        }
    }
return true;
}

list * prime_factors
    (
    uint64_t val
    )
{
uint64_t i = 2;
uint64_t *i_ptr;
uint64_t tmp_val = val;
list *ret_val = make_new_list();
while(tmp_val > 1)
    {
    if((tmp_val % i) == 0)
        {
        i_ptr = malloc(sizeof(uint64_t));
        *i_ptr = i;
        }
    while(((tmp_val % i) == 0) 
       && (tmp_val > 1       ))
        {
        add(ret_val, i_ptr);
        tmp_val /= i;
        }
    i++;
    }

return ret_val;
}
