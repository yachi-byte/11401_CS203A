/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/23: Refactored to use hash_fn.hpp
    - 2025/11/25: improve hashing function

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
 */
#include "hash_fn.hpp"
#include <cmath>


//multiplication Method
int myHashInt(int key, int m) {

    if (m <= 0) return 0; 
    
    unsigned int k = (unsigned int)std::abs(key); //non negative
    const unsigned int HASH_MULTIPLIER = 31;  // to decentralize data
    unsigned int scrambled_key = k * HASH_MULTIPLIER; //multiplicative mixing

    return scrambled_key % m;  // basic division method
}

//basic covert each character to  ASCII code and combine them
int myHashString(const std::string& str, int m) {

    if(m <= 0 || str.empty()) {
        return 0;
    } 
    unsigned long long hash = 0;  //reduce unpredictble collisions
    
    for (char c : str) {
        hash = (hash * 31 + static_cast<unsigned char>(c)) % m; //31 is a prime number ,allow data spread evenly
    }

    return static_cast<int>(hash % m);  // basic division method
}
