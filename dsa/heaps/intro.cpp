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
      and all nodes in the last level should be as far left as possible.
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

-In a Min-Heap, the key at root must be minimum among all keys present in the Binary Heap.
 The same property must be recursively true for all nodes in the Tree

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


 */     
