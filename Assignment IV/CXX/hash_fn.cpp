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

int myHashInt(int key, int m) {
    unsigned long digitProduct = 1;
    int privitiveValue = 31;

    if(key % 10 == 0){
        key += 1;
    }

    while(key){
        digitProduct = digitProduct * privitiveValue + (key % 10);
        key /= 10;
    }

    return digitProduct % m;
}

int myHashString(const std::string& str, int m) {
    unsigned long weightedSum = 0;
    int position = 1;
    int privitiveValue = 31;

    for(char c : str){
        weightedSum = weightedSum * privitiveValue + ((unsigned char)c) * position;
        position++;
    }

    return static_cast<int>(weightedSum % m);
}
