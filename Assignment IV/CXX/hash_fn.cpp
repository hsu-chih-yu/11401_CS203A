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

/*
    Uses a hybrid approach: multiplies the accumulator by a prime (31) 
    and adds the current digit. This ensures zero-digits don't zero out the hash.
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
/*
    Implements the standard Polynomial Rolling Hash algorithm using prime 31.    
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
