/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.hpp
    - 2025/11/23: Implemented hash functions for integer and string.
    - 2025/11/30: Improved hash functions to reduce collision rate and prevent overflow.
   
    Developer: 許芷瑜 <s1131456@mail.yzu.edu.tw>
 */
#include "hash_fn.hpp"

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
    unsigned long digitProduct = 1;
    int privitiveValue = 31;

    while(key){
        // Logic: Accumulate hash by mixing current value with prime and adding the digit
        digitProduct = digitProduct * privitiveValue + (key % 10);
        key /= 10;
    }

    return digitProduct % m;
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
int myHashString(const std::string& str, int m) {
    unsigned long weightedSum = 0;
    int position = 1;
    int privitiveValue = 31;

    for(char c : str){
        // Formula: hash = (hash * 31) + (char * position)
        // 31 is an odd prime that reduces collisions and works well for strings
        weightedSum = weightedSum * privitiveValue + ((unsigned char)c) * position;
        position++;
    }

    return static_cast<int>(weightedSum % m);
}
