/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.h
    - 2025/11/23: Implemented hash functions for integer and string.
    - 2025/11/30: Improved hash functions to reduce collision rate and prevent overflow.
   
    Developer: 許芷瑜 <s1131456@mail.yzu.edu.tw>
 */

#include "hash_fn.h"

/**
 * @brief Computes the hash index for an integer key.
 *
 * Implements a robust hashing logic that mixes multiplication (by prime 31)
 * and addition. This design prevents the "zero-multiplication" bug where
 * digits like 0 would otherwise zero out the entire hash value.
 *
 * @param key The integer key.
 * @param m The hash table size.
 * @return int The computed index (0 to m-1).
 */
int myHashInt(int key, int m) {
    unsigned long digit_product = 1;
    int primitive_value = 31;
    // Logic: Accumulate hash by mixing current value with prime and adding the digit
    while(key){
        digit_product = digit_product * primitive_value + (key % 10);
        key /= 10;
    }
    return digit_product % m;  
}

/**
 * @brief Computes the hash index for a std::string.
 *
 * Uses a Position-Weighted Polynomial Rolling Hash.
 * By combining the character value, a prime multiplier (31), and the
 * character's position, this function effectively distributes similar
 * strings (like "cat", "act", "tac") to different indices.
 *
 * @param str The string object to hash.
 * @param m The hash table size.
 * @return int The computed index (0 to m-1).
 */
int myHashString(const char* str, int m) {
    unsigned long weighted_sum = 0;
    int position = 1;
    int primitive_value = 31;
    // Formula: hash = (hash * 31) + (char * position)
    // 31 is an odd prime that reduces collisions and works well for strings
    while(*str){
        weighted_sum = weighted_sum * primitive_value + ((unsigned char)*str) * position; 
        str++;
        position++;
    }

    return (int)(weighted_sum % m); 
}
