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

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  sieve_of_eratosthenes
 *  Description:  Performs the Sieve of Eratosthenes to find and return the
 *                list of primes below the given limit
 * =====================================================================================
 */
list * sieve_of_eratosthenes
    (
    uint64_t lim
    )
{
list * prime_list = make_new_list();
uint8_t lst[lim + 1];
uint64_t i, j;

for(i = 0; i <= lim; i++)
    {
    lst[i] = 1;
    }
lst[0] = 0;
lst[1] = 0;
/* perform the sieve */
for(i = 2; i <= (uint64_t)sqrt(lim); i++)
    {
    if(lst[i] == 1)
        {
        for(j = 2 * i; j <= lim; j += i)
            {
            if(lst[j] == 1)
                {
                lst[j] = 0;
                }
            }
        }
    }
/* add the value to the prime list */
for(i = 2; i <= lim; i++)
    {
    if(lst[i] == 1)
        {
        add(prime_list, &i, sizeof(i));
        }
    }
return prime_list;
}		/* -----  end of function sieve_of_eratosthenes  ----- */

list * prime_factors
    (
    uint64_t val
    )
{
uint64_t i = 2;
uint64_t tmp_val = val;
list *ret_val = make_new_list();
while(tmp_val > 1)
    {
    if((tmp_val % i) == 0)
        {
        while(((tmp_val % i) == 0) 
           && (tmp_val > 1       ))
            {
            add(ret_val, &i, sizeof(i));
            tmp_val /= i;
            }
        }
    i++;
    }

return ret_val;
}
