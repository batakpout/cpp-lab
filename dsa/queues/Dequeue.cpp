/*
 * DEQUE INTERNAL STRUCTURE (based on typical implementation):
 * 
 * How deque works internally:
 * 
 *     Pointer Map        Data Blocks
 *    ┌─────────────┐    
 *    │ Pointer[0]  │ ──→ ┌─────┬─────┬─────┬─────┐
 *    │ Pointer[1]  │     │  0  │  1  │  2  │  3  │ 
 *    │ Pointer[2]  │ ──→ ┌─────┼─────┼─────┼─────┐
 *    │     ↓       │     │data(3)│data(4)│data(5)│data(6)│
 *    └─────────────┘     └─────┼─────┼─────┼─────┘
 *                        ┌─────┼─────┼─────┼─────┐
 *                        │data(7)│data(8)│    │    
 *                        └─────┴─────┴─────┴─────┘
 * 
 * Time Complexities:
 * - push_back:  O(1)    - Pop_back:   O(1)
 * - push_front: O(1)    - Pop_front:  O(1)  
 * - Random access: O(1) - Iterator ops: O(1)
 * - insert and erase: O(n)
 * Key Benefits:
 * - No reallocation of existing elements when growing
 * - Maintains pointers to block boundaries
 * - Efficient memory usage with block-based allocation
 * - Constant time operations at both ends
 */

/*
    - deque is typically implemented as a deque of blocks/chunks (not a simple circular array). It maintains an array of pointers to fixed-size blocks, where each block contains multiple elements. This hybrid approach provides O(1) operations at both ends.
    - When the deque needs to expand, it doesn't reallocate and copy all existing elements. Instead, it allocates new blocks and updates its internal pointer map. This avoids costly constructor calls and copying of existing elements, making growth operations more efficient.
    - implmented either using a doubly linked list(not singly as tail can't point to previous element and so deletion can't be O(1)) or circular array.

    --Applications of dequeue:
    1. A dequeue can be used as both Stack and Queue.
    2. Maintaining history of actions.
    3. A Steal Process Scheduling Algorithm.
    4. Implementing a priority queue with two types of priorities.
    5. Implementing Minimum/Maximum of all subarrays of size k in an array.

*/
//todo: Implementing Minimum/Maximum of all subarrays of size k in an array
/**
 Input: arr = [1,3,-1,-3,5,3,6,7], k = 3
Output: 3 3 5 5 6 7 
max element in each subarray [sliding window]
 */
#include<iostream>
#include<deque>
using namespace std;

int main() {

    deque<int> dq = {10,20,30};

    dq.push_front(5);
    dq.push_back(50);

    for(auto x: dq) {
        cout << x << " ";
    }
    cout << endl;
    cout << dq.front() << " " << dq.back();
    cout << endl;

    cout << "\n----------\n";

    deque<int> dq2 = {10,15,30,5,12};
    auto it = dq2.begin();
    it++;
    dq2.insert(it, 20);
    dq2.pop_front();
    dq2.pop_back();

    for(auto x: dq2) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}