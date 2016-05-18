/*
 * =====================================================================================
 *
 *       Filename:  string.c
 *
 *    Description:  String operations
 *
 *        Version:  1.0
 *        Created:  04/30/2016 10:39:03 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Seth Lienemann (sal), sethlienemann@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include    <stdint.h>
#include    <stdio.h>
#include    <stdbool.h>
#include    <stdlib.h>
#include    "str_utl.h"

bool is_palindrome
    (
    uint64_t val
    )
{
    char * front;
    char * back;
    char * string_val = malloc(26 * sizeof(char));
    //stringify the value
    snprintf(string_val, 25, "%lu", val);
    front = string_val;
    back = string_val;
    //Take the back to the end of the array
    while(*back != '\0')
        {
        back++;
        }
    //Back up once to be at last element
    back--;
    //Then walk from both front and back comparing characters
    while(back > front)
        {
        if(*back != *front)
            {
            return false;
            }
        back--;
        front++;
        }
    return true;
}
