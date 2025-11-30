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
  
- === Hash Function Observation (C Version) ===

<img width="600" height="569" alt="Image" src="https://github.com/user-attachments/assets/52c3ced1-bf33-4e25-8422-478e24a8cefc" />

<img width="600" height="514" alt="Image" src="https://github.com/user-attachments/assets/4c3da14d-5e69-4188-b945-b53d572d421a" />

<img width="600" height="529" alt="Image" src="https://github.com/user-attachments/assets/91c0c900-8df7-4878-9558-85e4375e571b" />

<img width="600" height="299" alt="Image" src="https://github.com/user-attachments/assets/63f83c27-61db-495c-b64c-4eef48eaaa48" />

<img width="600" height="305" alt="Image" src="https://github.com/user-attachments/assets/e0190155-8af9-4202-af92-53d65c5b771d" />

<img width="600" height="301" alt="Image" src="https://github.com/user-attachments/assets/aaf3daf9-d914-4468-9c45-717a3b66c0d1" />

- === Hash Function Observation (C++ Version) ===
  
<img width="600" height="560" alt="Image" src="https://github.com/user-attachments/assets/be210a2b-6395-4a39-96bd-f61195651490" />

<img width="600" height="520" alt="Image" src="https://github.com/user-attachments/assets/972c0f6a-ad2f-4240-939d-250cfc03e302" />

<img width="600" height="517" alt="Image" src="https://github.com/user-attachments/assets/03b0b57b-aa3f-4e63-a1da-e540a323233b" />

<img width="600" height="318" alt="Image" src="https://github.com/user-attachments/assets/36c2f815-0402-4382-849d-ac6b1bf2fd0a" />

<img width="600" height="307" alt="Image" src="https://github.com/user-attachments/assets/6a79114f-c9f2-4c93-a0ff-b1a6e7a19ab4" />

<img width="600" height="296" alt="Image" src="https://github.com/user-attachments/assets/6997b7b2-1900-4988-8933-cbc5a7336c72" />

 
  

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
- Prime vs non-prime `m`:
  - Prime(m=10):The predictability of the sequence ( 6, 9, 2...) is obvious.
  - non-prime(m=11, 37):showed better randomness.And m=37 spread more evenly than m=11.
- Patterns or collisions: prime table sizes (m=11, 37) demonstrated higher uniformity, while the non-prime size (m=10) is functional but displays a strong, exploitable pattern.
- Improvements: Use a prime table size and a well-designed hash function to enhance distribution.I think 

## Reflection
1. Designing hash functions requires balancing simplicity and effectiveness to minimize collisions.In the design of the integer hash function, I experimented with the basic Division Method and Multiplication Method, but the results were unsatisfactory. When trying the Universal Hashing strategy, collisions were reduced simply by fine-tuning parameters a and p.
2. Table size significantly impacts the uniformity of the hash distribution, with prime sizes performing better.
3. The Universal Hashing design, utilizing a prime $p$ and a carefully chosen multiplier $a$, can transform linear input sequences into non-linear output sequences. I also found that adjusting parameters can resolve consecutive integer collision issues, leading to more uniform distribution.
