/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/23: Refactored to use hash_fn.hpp

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
 */
#include "hash_fn.hpp"

//h(k) = k mod m(table size(m))
//Division Method
int myHashInt(int key, int m) {

    if (m <= 0) return 0; 
    
    return key % m;  // basic division method
}

//basic covert each character to  ASCII code and combine them
int myHashString(const std::string& str, int m) {

    if (m <= 0)  return 0; 
    unsigned long hash = 0;
    
    for (char c : str) {
        hash += static_cast<unsigned char>(c);
    }

    return static_cast<int>(hash % m);  // basic division method
}
