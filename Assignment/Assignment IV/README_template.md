# Homework Assignment IV: Hash Function Design & Observation (C/C++ Version)

This assignment focuses on the design and observation of hash functions using C/C++. 
Students are expected to implement and analyze the behavior of hash functions, 
evaluate their efficiency, and understand their applications in computer science.

Developer: [葉冠琪]  
Email: [ya.ykc950429@gmail.com]  
## Development Platform
- OS: Windows 11
- Toolchain: MinGW-w64 (MSYS2)
- IDE: VS Code
## My Hash Function
### Integer Keys 
- Formula / pseudocode:
  ```text
  int myHashInt(int key, int m) {
    if (m <= 0) return 0; 
    const unsigned int p = 71; //prime
    const unsigned int a = 13; 
    const unsigned int b = 27; //Offset
  
    unsigned int k = (unsigned int)key;    
    unsigned int scrambled_key = (a * k + b) % p;
    return scrambled_key % m;
  }
  ```
- Rationale: [I implemented a Universal Hashing strategy by ((ax + b) % p) % m.Since a simple key % m results in clustered linear indices.My formula uses a linear transformation (13 * k + 27) to scramble these inputs before mapping them to the table.]
  - Prime (p = 71): I chose 71 because it is a prime number a little bit larger than the maximum key value (60) in the dataset.
  - Multiplier ( a = 13): 13 is coprime with 10 and 11.
  

### Non-integer Keys
- Formula / pseudocode:
  ```text
  int myHashString(const std::string& str, int m) {
    if(m <= 0 || str.empty()) {
        return 0;
    } 
    unsigned long long hash = 0;    
    for (char c : str) {
        hash = (hash * 31 + static_cast<unsigned char>(c)) % m;
    }
    return static_cast<int>(hash % m);  // basic division method
  }
  ```
- Rationale: [I used a Polynomial Rolling Hash variant to process string keys,by the formula hash = (hash * 31 + char) % m. ]
  -   Multiplier 31 (a prime number) : to ensure the position of each character affects the final result.

## Experimental Setup
- Table sizes tested (m): 10, 11, 37
- Test dataset:
  - Integers: 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60
  - Strings: "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"
- Compiler: GCC and G++
- Standard: C23 and C++23

## Results
| Table Size (m) | Index Sequence         | Observation              |
|----------------|------------------------|--------------------------|
| 10             | 6, 9, 2, 5, 8, 0, 3, 6, 9, 2, 1, 4, 6, 9, 2, 5, 8, 0, 3, 6        |  Input keys jump by 3 positions each time (13 mod 10 = 3). Since 3 and 10 are co-prime, it visits all slots before repeating, but the pattern is predictable. |
| 11             | 5, 7, 9, 0, 2, 10, 1, 3, 5, 7, 7, 9, 6, 8, 10, 1, 3, 0, 2, 4       | effectively spreading consecutive keys.             |
| 37             | 16, 29, 5, 18, 31, 10, 23, 36, 12, 25, 14, 27, 6, 19, 32, 8, 21, 0, 13, 26    | consecutive inputs result in widely separated indices             |

## Compilation, Build, Execution, and Output

### Compilation
- The project uses a comprehensive Makefile that builds both C and C++ versions with proper flags:
  ```bash
  # Build both C and C++ versions
  make all
  
  # Build only C version
  make c
  
  # Build only C++ version
  make cxx
  ```

### Manual Compilation (if needed)
- Command for C:
  ```bash
  gcc -std=c23 -Wall -Wextra -Wpedantic -g -o C/hash_function C/main.c C/hash_fn.c
  ```
- Command for C++:
  ```bash
  g++ -std=c++23 -Wall -Wextra -Wpedantic -g -o CXX/hash_function_cpp CXX/main.cpp CXX/hash_fn.cpp
  ```

### Clean Build Files
- Remove all compiled files:
  ```bash
  make clean
  ```

### Execution
- Run the compiled binary:
  ```bash
  ./hash_function
  ```
  or
  ```bash
  ./hash_function_cpp
  ```

### Result Snapshot
- Example output for integers:
  ```
  === Hash Function Observation (C Version) ===

  === Table Size m = 10 ===
  Key     Index
  -----------------
  21      6
  22      9
  23      2
  24      5
  25      8
  26      0
  27      3
  28      6
  29      9
  30      2
  51      1
  52      4
  53      6
  54      9
  55      2
  56      5
  57      8
  58      0
  59      3
  60      6
  
  === Table Size m = 11 ===
  Key     Index
  -----------------
  21      5
  22      7
  23      9
  24      0
  25      2
  26      10
  27      1
  28      3
  29      5
  30      7
  51      7
  52      9
  53      6
  54      8
  55      10
  56      1
  57      3
  58      0
  59      2
  60      4
  
  === Table Size m = 37 ===
  Key     Index
  -----------------
  21      16
  22      29
  23      5
  24      18
  25      31
  26      10
  27      23
  28      36
  29      12
  30      25
  51      14
  52      27
  53      6
  54      19
  55      32
  56      8
  57      21
  58      0
  59      13
  60      26
  
  === String Hash (m = 10) ===
  Key     Index
  -----------------
  cat     2
  dog     4
  bat     1
  cow     9
  ant     3
  owl     8
  bee     0
  hen     5
  pig     0
  fox     3
  
  === String Hash (m = 11) ===
  Key     Index
  -----------------
  cat     10
  dog     6
  bat     6
  cow     7
  ant     9
  owl     6
  bee     5
  hen     5
  pig     0
  fox     9
  
  === String Hash (m = 37) ===
  Key     Index
  -----------------
  cat     27
  dog     3
  bat     28
  cow     20
  ant     25
  owl     23
  bee     26
  hen     29
  pig     27
  fox     18

  === Hash Function Observation (C++ Version) ===

  === Table Size m = 10 ===
  Key     Index
  -----------------
  21      6
  22      9
  23      2
  24      5
  25      8
  26      0
  27      3
  28      6
  29      9
  30      2
  51      1
  52      4
  53      6
  54      9
  55      2
  56      5
  57      8
  58      0
  59      3
  60      6
  
  === Table Size m = 11 ===
  Key     Index
  -----------------
  21      5
  22      7
  23      9
  24      0
  25      2
  26      10
  27      1
  28      3
  29      5
  30      7
  51      7
  52      9
  53      6
  54      8
  55      10
  56      1
  57      3
  58      0
  59      2
  60      4
  
  === Table Size m = 37 ===
  Key     Index
  -----------------
  21      16
  22      29
  23      5
  24      18
  25      31
  26      10
  27      23
  28      36
  29      12
  30      25
  51      14
  52      27
  53      6
  54      19
  55      32
  56      8
  57      21
  58      0
  59      13
  60      26
  
  === String Hash (m = 10) ===
  Key     Index
  -----------------
  cat     2
  dog     4
  bat     1
  cow     9
  ant     3
  owl     8
  bee     0
  hen     5
  pig     0
  fox     3
  
  === String Hash (m = 11) ===
  Key     Index
  -----------------
  cat     10
  dog     6
  bat     6
  cow     7
  ant     9
  owl     6
  bee     5
  hen     5
  pig     0
  fox     9
  
  === String Hash (m = 37) ===
  Key     Index
  -----------------
  cat     27
  dog     3
  bat     28
  cow     20
  ant     25
  owl     23
  bee     26
  hen     29
  pig     27
  fox     18
  ```

- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.
- Example output for integers:
  ```
  Hash table (m=10): [6, 9, 2, 5, 8, 0, 3, 6, 9, 2, 1, 4, 6, 9, 2, 5, 8, 0, 3, 6]
  Hash table (m=11): [5, 7, 9, 0, 2, 10, 1, 3, 5, 7, 7, 9, 6, 8, 10, 1, 3, 0, 2, 4]
  Hash table (m=37): [16, 29, 5, 18, 31, 10, 23, 36, 12, 25, 14, 27, 6, 19, 32, 8, 21, 0, 13, 26]
  ```
- Example output for strings:
  ```
  Hash table (m=10): [2, 4, 1, 9, 3, 8, 0, 5, 0, 3 ]
  Hash table (m=11): [10, 6, 6, 7, 9, 6, 5, 5, 0, 9]
  Hash table (m=37): [27, 3, 28, 20, 25, 23, 26, 29, 27, 18]
  ```
- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.

## Analysis
- Prime vs non-prime `m`: Prime table sizes generally result in better distribution and fewer collisions.
- Patterns or collisions: Non-prime table sizes tend to produce repetitive patterns, leading to more collisions.
- Improvements: Use a prime table size and a well-designed hash function to enhance distribution.

## Reflection
1. Designing hash functions requires balancing simplicity and effectiveness to minimize collisions.
2. Table size significantly impacts the uniformity of the hash distribution, with prime sizes performing better.
3. The design using a prime table size and a linear transformation formula produced the most uniform index sequence.
