/*
 * =====================================================================================
 *
 *       Filename:  p004.c
 *
 *    Description:  Project Euler Problem 4
 *     
 *    A palindromic number reads the same both ways. The largest palindrome
 *    made from the product of two 2-digit numbers is 9009 = 91 x 99.
 *
 *    Find the largest palindrome made from the product of two 3-digit numbers.
 *
 *        Version:  1.0
 *        Created:  04/24/2016 03:11:22 PM
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
#include    "string.h"

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
    uint32_t a, b;
//    uint64_t c;
    uint64_t largest = 0;

    for(a = 999; a >= 100; a--)
    for(b = a; b >= 100; b--)
        {
        if(is_palindrome(a * b))
            {
            if(a * b > largest)
                {
                largest = a * b;
                }
            }
        }
    printf("The answer is: %lu\n", largest);
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

