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

/*
    Uses a hybrid approach: multiplies the accumulator by a prime (31) 
    and adds the current digit. This ensures zero-digits don't zero out the hash.
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

/*
    Implements the standard Polynomial Rolling Hash algorithm using prime 31.    
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
