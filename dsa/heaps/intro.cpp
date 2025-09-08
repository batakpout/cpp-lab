/*
    Binary heap
        - used in heap sort.
        - used to implement priority queues
        - used in Graph algorithms (like Dijkstra's, Prim's)
        - two types:
          * Min heap(highest priority item is assigned lowest value)
          * Max heap(highest priority item is assigned highest value)
        
        - we restrict this heap as complete binary tree. Advantage: 
            * we can represent it as array without wasting any space unlike a normal binary tree when not stored in array.
            * we have items at contiguous location, random access. So also it is cache friendly.
            * It is complete binary tree, height of this tree is minimum possible as most of the operations in heap also 
              will depend on the height of the complete binary tree.

         
 * Binary Heap Implementation
 * --------------------------
 * A Binary Heap is a Complete Binary Tree stored as an array. Since a Binary Heap is a complete Binary Tree, it can be easily represented using Arrays. 
 * 
 * Properties:
 * -----------
 * 1. **Complete Binary Tree**: All levels are completely filled 
 *    except possibly the last, which is filled from left to right.
 *
 * 2. **Array Representation**:
 *    - Each node is stored in an array at index `i`.
 *    - Left child index  = 2*i + 1
 *    - Right child index = 2*i + 2
 *    - Parent index      = floor((i - 1) / 2)
 * if we start from index 1 then do -1 for everything above!
 *
 * Example:
 * --------
 *        10
 *       /  \
 *     20    30
 *    / \    /
 *  40  50  60
 *
 * Array representation: [10, 20, 30, 40, 50, 60]

 * Note:
 * -----
 * A Binary Heap can be a Min-Heap or Max-Heap depending on 
 * whether the root is the smallest or largest element.
 * 
 ======================

     Example of a NOT Complete Binary Tree:

            1
          /   \
         2     3
        / \      \
       4   5      6

    Explanation:
    - A complete binary tree must fill all levels except possibly the last,
      and all nodes in the last level should be as far left as possible (or we say it must be filled in left to right order).
    - Here, node `3` has a right child `6` but NO left child.
    - This violates the rule, so it's NOT a complete binary tree.
  Index:   0   1   2   3   4   ?   5
  Value:   1   2   3   4   5   -   6
  let's test the formula for node `3` at index `2`:

 *    Left child index  = 2*2 + 1 = **5**
 *    Right child index = 2*2 + 2 = **6**
 *
 * However, in our tree, node `3` has:
 *    Left child  = **NONE**
 *    Right child = `6`
 *
 * So according to the formula, `6` should be at index **6**, but in our level-order array,
 * it must actually sit at **index 5** (because index 5 is next in level order).
 *
 * This mismatch breaks the formula and shows why a **heap** (which depends on the formula)
 * **requires** a **complete binary tree**.
 
            1
          /   \
         2     3.  not a complete binary tree also
              / 
            6

-In a Min-Heap, the key at root must be minimum(or equal) among all keys present in the Binary Heap.
 The same property must be recursively true for all nodes in the Tree. In Max-heap parent >= children
- A heap will always be a max or min heap, so watch out for CST (complete binary trees) with such property.

            10
          /    \
        20      15
       /  \       \
     30   40      18

   array:
  Index:   0    1    2    3   4     5
  Value:   10   20   15   30  40   18

  same goes for max heap
               100
             /    \
           40      50
          /  \    /  \
        10   15  50   40


- Binary Heap: A Binary Heap is a heap where each node can have at most two children. In other words, a Binary Heap is a complete Binary Tree.
- Since a Binary Heap is a complete Binary Tree, it can be easily represented using Arrays. 
- A priority queue is a special type of queue in which elements are processed based on priority rather than insertion order. In C++ STL, priority queues are implemented under the hood using the heap data structure, which ensures efficient retrieval of the highest (or lowest) priority element.
- In priority queue: insert O(Log N), pop max or min O(Log N), get max or min O(1)
- In priority queue, creating a queue takes O(n) and we are going to pop one person each time from queue. Removing one person take O(Log N) time and removing k items takes O(k. Log(n)). So total: O(N + k.log N)

- Using simple sorting takes O(N. Log n) time but this priority queue takes O(k. log n) time

- Comparisons:

+----------------+----------------+---------------+------+-------+--------+
| Operation / DS| Array          | Sorted Array  | List |  BST  |  Heap  |
|               | (unsorted)     |               |      |       |        |
+---------------+----------------+---------------+------+-------+--------+
| Push (any)    | O(1)           | O(N)          |  ✓   | O(N)  | O(logN)|
| Pop (max)     | O(N)           | O(1)          |  ✓   | O(N)  | O(logN)|
| Get (max)     | O(N)           | O(1)          |  ✓   | O(N)  | O(1)   |
+---------------+----------------+---------------+------+-------+--------+
So looks like heap has the better complexity.

-Heaps as an Arrays (problem with binary tree memory representation)

If we represent heap as BT in memory then it takes O(N) as we go level order traversal wise to check where should
we place this new node, so will make insertion slow. Instead we want it to be O(Log N).

First, tree is needed because we need a relationship b/w parent and child as this is a hierarchical data structure. But
this is a special kind of a tree, it is a complete binary tree, it has a special property, it can be easily flattened out
in an array. So we can use the formula listed above to find for any node in array, what is the parent, left and right node.


Now if my heap is:
 
  same goes for max heap
               100
             /    \
           40      50
          /  \    /  
        20   30  15  

  Index:   0     1    2    3   4     5 
  Value:   100   40   50   20  30   15 

  Now if I want to insert 120
       
*/
