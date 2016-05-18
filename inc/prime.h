/*
 * =====================================================================================
 *
 *       Filename:  prime.h
 *
 *    Description:  Header for the prime number functions and structures
 *
 *        Version:  1.0
 *        Created:  04/17/2016 09:18:07 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Seth Lienemann (sal), sethlienemann@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef PRIME_H
#define PRIME_H

#include    <stdint.h>
#include    <stdbool.h>
#include    "list.h"

bool is_prime
    (
    uint64_t num
    );

list * prime_factors
    (
    uint64_t val
    );

list * sieve_of_eratosthenes
    (
    uint64_t lim
    );
#endif
