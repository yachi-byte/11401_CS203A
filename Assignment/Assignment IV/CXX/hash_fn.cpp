/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================
   Gemini provides hash function improvements.

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/23: Refactored to use hash_fn.hpp
    - 2025/11/25: improve hashing function
    - 2025/11/30: change integer hash function to Universal Hashing method:
                  ((ax + b) % p) % m

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
 */
#include "hash_fn.hpp"
#include <cmath>


//Universal Hashing method(based on Division Method)
int myHashInt(int key, int m) {

    if (m <= 0) return 0; 

    const unsigned int p = 71; //prime
    const unsigned int a = 13; 
    const unsigned int b = 27; //Offset

    unsigned int k = (unsigned int)key; //non negative
    // step 1 : scramble consecutive inputs
    unsigned int scrambled_key = (a * k + b) % p;

    return scrambled_key % m;  // Maps the scrambled value to hash table
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
