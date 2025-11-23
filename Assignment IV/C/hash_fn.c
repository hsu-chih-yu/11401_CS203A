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
   
    Developer: 許芷瑜 <s1131456@mail.yzu.edu.tw>
 */

#include "hash_fn.h"

int myHashInt(int key, int m) {
    int digit_product = 1;
    if(key % 10 == 0){
        key += 1;
    }
    while(key){
        digit_product *=  (key % 10);
        key /= 10;
    }
    return digit_product % m;  
}

int myHashString(const char* str, int m) {
    unsigned long weighted_sum = 0;
    int position = 1;
    while(*str){
        weighted_sum += ((unsigned char)(*str) - 'a' + 1) * position; 
        str++;
        position++;
    }

    return (int)(weighted_sum % m); 
}
