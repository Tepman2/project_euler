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

