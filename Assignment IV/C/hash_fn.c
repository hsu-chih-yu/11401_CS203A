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

int myHashInt(int key, int m) {
    unsigned long digit_product = 1;
    int primitive_value = 31;
    if(key % 10 == 0){
        key += 1;
    }
    while(key){
        digit_product = digit_product * primitive_value + (key % 10);
        key /= 10;
    }
    return digit_product % m;  
}

int myHashString(const char* str, int m) {
    unsigned long weighted_sum = 0;
    int position = 1;
    int primitive_value = 31;
    while(*str){
        weighted_sum = weighted_sum * primitive_value + ((unsigned char)*str) * position; 
        str++;
        position++;
    }

    return (int)(weighted_sum % m); 
}
