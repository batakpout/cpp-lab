/** =================================Intro==============================
-- Hashing: O(1) search,insert, delete on average and o(n) for worst case if all items hash to the 
    same bucket
-- Hash table by general is an unordered data strucutre
-- Array has great cache locality(cache friendly) (CPU loads nearby memory together), Hash table has poor cache
    locality(jumping around random memory locations)
-- CPU cache is "spatial locality" based - it assumes if you access one memory location, you will 
    likely access nearby locations soon.
-- Hash table is used in  most of the algorithms: arrays, linkedlist, graph , dp algorithms
-- Restaurant menu look up for an item is O(N), ask waiter it will become O(1), add new item or delete
   out of order item, that should be O(1)

-- A direct address table can be implemented using boolean array. With index as numbers from let's
   say 1 to 100,values as boolean T or F with default 0->false. So insert op. will do insert(1) at index 1;
   delete it change status at delete(i) i.e at index i from 1 to 0 and search will just return arr(i) which will return 
   boolean value. If we want to insert in range let's say 1000 to 1600 we can just use insert(i-1000) to store 
   them from 0 to 600.
   So direct address table works for keys with smaller index values and problem with this approach is what if key 
   are long like phone numbers with 10 digits, keys are addresses which are large integers or say keys are floating
   point numbers so we can't store them in the arrays as indexes. Also if key is string, we can't use it as index.
   So this is where the idea of hasing comes in.

 */

 /**
   =====Hash Function======
   - We use a hash function that maps large or complex keys—such as phone numbers, employee IDs, or names—into a fixed-size integer value. This integer, known as the hash code, serves as the index in an underlying array called the hash table. Array elements are indexed by a key, which is mapped to an
   array index(0 to table_size - 1).Mapping from key to array index is done by has function. This array can grow , rehasing.
   - Insert: arr[f(key)] = value, search arr[f(key)], delete arr[f(key)] = NULL

   - Addresses are stored in pointers(int * p) not plain ints. On a 32-bit program, pointer are typically 4 bytes(can represent 2^32 addresses),
   and in 64-bit, they are 8 bytes long(can represent 2^64 address)
   -  If we say “keys are 10-digit phone numbers”, the possible key values range from 0000000000 to 9999999999, that’s 10¹⁰ distinct values—about ten billion possible keys. This number (10¹⁰) is sometimes called the key universe.

HASHING SOLUTION:
• Take large universe of keys (phone numbers, strings, employee IDs)
• Use hash function to convert large keys → small values
• Use small values as indices in hash table (small array)

HASH FUNCTION REQUIREMENTS:
1. DETERMINISTIC: Same key → same index every time
2. RANGE: Must generate values 0 to (m-1) where m = hash table size
3. FAST: O(1) for integers, O(length) for strings
4. UNIFORM DISTRIBUTION: Spread keys evenly across table (hardest to achieve)

HASH FUNCTIONS:

1. MODULAR DIVISION (for integers):
   hash(key) = key % m
   • Example: phone_number % 13 gives values 0-12
   • Choose m as prime number (better distribution)
   • Avoid powers of 2 or 10 (bad distribution)
   
   WHY AVOID POWERS OF 2/10:
   • key % (10^3) = considers only last 3 digits
   • key % (2^3) = considers only last 3 bits
   • Ignores most of the key information

2. STRING HASHING:
   BAD: hash = (sum of ASCII values) % m
   • Problem: All permutations or anagrams get same hash
   • "abc", "bca", "cab" → same sum
   
   BETTER: Weighted sum
   hash = (char[0]*x^0 + char[1]*x^1 + char[2]*x^2 + ...) % m
   • x = some constant like 33
   • Different positions get different weights
   • Avoids permutation collision problem

3. UNIVERSAL HASHING:
   • Have a family/set of hash functions
   • Randomly pick one hash function for each hash table
   • Guarantees O(1) expected time
   • No specific input pattern can cause bad performance

COLLISION:
• When two different keys map to same index
• Example: key1 % 13 = 5, key2 % 13 = 5
• Collision is inevitable (pigeonhole principle)
• Need collision handling strategies

HASH TABLE SIZE:
• Size proportional to number of keys to insert (not universe size)
• If inserting n keys → table size ≈ n, 2n, or 4n
• Example: 100 employees → table size ≈ 200, not 10^10

KEY INSIGHT:
• Universe size: 10^10 possible phone numbers
• Actual keys: 100 phone numbers
• Hash table size: ~200 (proportional to actual keys, not universe)
• Hash function: Maps 100 phone numbers to indices 0-199
*/


 /**
WHY PRIME NUMBERS FOR HASH TABLE SIZE:

CORE PROBLEM:
If hash table size 'm' shares common factors with your data patterns, 
keys cluster in few buckets instead of spreading evenly.

EXAMPLE:
Keys: 100, 200, 300, 400... (multiples of 10)
- If m = 100: All keys map to bucket 0 
  (100%100 = 0, 200%100 = 0, 300%100 = 0, etc.)
- If m = 97 (prime): Keys spread across many buckets 
  (100%97 = 3, 200%97 = 6, 300%97 = 9, etc.)

WHY PRIMES WORK:
Prime numbers have no common factors with most data patterns, 
so modulo operation produces uniform distribution across all buckets.

AVOID:
- Powers of 2 (considers only last few bits)
- Powers of 10 (considers only last few digits)  
- Multiples of common numbers

CHOOSE:
Prime numbers close to desired table size but not near powers of 2 or 10.
 */

 /*
POWERS OF 2 vs POWERS OF 10 - WHY THEY'RE BAD:

POWERS OF 10 EXAMPLE:
Key: 123456789
If m = 1000 (10^3):
  hash = 123456789 % 1000 = 789
  Only considers last 3 digits (789), ignores first 6 digits (123456)
  
Keys: 111789, 222789, 333789, 999789
All map to same bucket 789 because they have same last 3 digits!

POWERS OF 2 EXAMPLE:  
Key: 123 (binary: 1111011)
If m = 8 (2^3):
  hash = 123 % 8 = 3
  In binary: 1111011 % 1000 = 011 (last 3 bits)
  Only considers last 3 bits, ignores all other bits

Keys: 11 (1011), 19 (10011), 123 (1111011) 
All have same last 3 bits (011), so all map to bucket 3!

THE PROBLEM:
- Modulo with powers ignores most of the key information
- Creates artificial clustering based on patterns in last few digits/bits
- Real data often has patterns that align with these powers
- Result: Poor distribution, many collisions

SOLUTION:
Use prime numbers that don't have these common factors with data patterns.
*/

/*
 ====COLLISION handling--1 =====


WHY COLLISIONS ARE INEVITABLE:
- Large universe of keys (10^10 phone numbers) mapped to small hash table
- Example: 10 phone numbers in table size 10, using last digit as hash
- Even with good hash function, different keys can map to same index
- Birthday Paradox: 23 people = 50% chance of same birthday
                    70 people = 99.9% chance of collision

PERFECT HASHING (Advanced):
- Works only when keys are known in advance
- Can guarantee zero collisions through preprocessing
- Useful for dictionaries, fixed datasets
- Not practical for dynamic data insertion

COLLISION HANDLING METHODS:
1. CHAINING: Create linked lists at each hash table slot
   • Multiple keys with same hash stored in chain
   
2. OPEN ADDRESSING: Use same array, find alternative positions
   • If slot occupied, probe for next available slot
   • Keep everything in single array

KEY INSIGHT:
Collisions are unavoidable in practical hash tables - the focus should be
on efficient collision handling rather than collision prevention.
*/

/*
==========COLLISION HANDLING 2==========:

COLLISION INEVITABILITY:
• Two different keys can generate same hash value after modulo operation
• Example: Keys 50,60,80,100 with table size 10 all map to bucket 0
• Cannot avoid collisions completely, but can reduce and handle them

HASH TABLE DESIGN REQUIREMENTS:
1. Good hash function to reduce collision chance
2. Collision handling strategy when collisions occur

GOOD HASH FUNCTION PROPERTIES:
• Uniform distribution across all buckets (equal probability for each bucket)
• Fast computation (O(1) for fixed-length strings/integers)
• Minimize clustering of similar keys

COLLISION HANDLING - SEPARATE CHAINING (OPEN HASHING):
• Create linked list at each hash table bucket
• When collision occurs, add new key to the chain
• Used by C++ STL unordered_map
• Example: Keys 0,1,16,36,81 with table size 10:
  Bucket 0: [0] -> NULL
  Bucket 1: [1] -> [81] -> NULL  
  Bucket 6: [16] -> [36] -> NULL

DATA STRUCTURES TO STORE CHAINS:
• Linked List; if chain length = l then, search/insert/delete O(l); bad not cache friendly
• Dynamic sized arrays(vectors in c++); O(l) for insert/delete/search; but it is cache friendly
• Self Balancing BST(AVL tree, Red Black tree); O(log(l)) all insert/search/delete; not cache friendly

TIME COMPLEXITY FOR HASHTABLE:
• Average case: O(1) for search/insert/delete
• Worst case: O(n) if all keys hash to same bucket
• Good hash function + rehashing keeps average case performance of O(1)

OTHER COLLISION HANDLING METHODS (Advanced):
• Closed Hashing: Linear probing, Quadratic probing
• Double hashing
*/
