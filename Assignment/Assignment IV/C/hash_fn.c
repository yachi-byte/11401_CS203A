/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.h

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
 */

#include "hash_fn.h"
#include <stdlib.h>

int myHashInt(int key, int m) {
    if (m <= 0) return 0;

    unsigned int k = (unsigned int)(key < 0 ? -key : key); //non negative
    const unsigned int HASH_MULTIPLIER = 31;

    unsigned int scrambled_key = k * HASH_MULTIPLIER;
   
    return scrambled_key % m;  // division method example
}

int myHashString(const char* str, int m) {

    if (m <= 0 || str == NULL || *str == '\0') {
        return 0;
    }

    unsigned long long hash = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash = (hash * 31 + (unsigned char)str[i]) % m;
    }
    return (int)(hash % m); // basic division method
}
