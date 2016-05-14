/*
 * =====================================================================================
 *
 *       Filename:  p009.c
 *
 *    Description:  Project Euler Problem 9 
 *
 *    A Pythagorean triplet is a set of three natural numbers, a < b < c, for
 *    which, a^2 + b^2 = c^2 
 *    For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.  
 *
 *    There exists exactly one Pythagorean triplet for which a + b + c = 1000. 
 *    Find the product abc.
 *
 *        Version:  1.0
 *        Created:  05/13/2016 09:01:56 PM
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
    char *argv[] 
    )
{
uint32_t a, b, c;

for(c = 5; c < LIMIT; c++)
for(b = 1; b < c; b++)
for(a = 1; a < b; a++)
    {
    if((a + b + c == LIMIT            )
    && (((a * a) + (b * b)) == (c * c)))
        {
        printf("The answer is: %d\n", a * b * c);
        }
    }
return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
