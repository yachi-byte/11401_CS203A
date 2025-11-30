/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.h
    - 2025/11/25: improve hashing function
    - 2025/11/30: change integer hash function to Universal Hashing method:
                  ((ax + b) % p) % m

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
 */

#include "hash_fn.h"
#include <stdlib.h>

// Universal Hashing method (based on Division Method)
int myHashInt(int key, int m) {
    if (m <= 0) return 0;

    const unsigned int p = 97;
    const unsigned int a = 31;
    const unsigned int b = 15;

    unsigned int k = (unsigned int) key; //non negative
    
    unsigned int scrambled_key = (a * k + b) % p;
   
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
