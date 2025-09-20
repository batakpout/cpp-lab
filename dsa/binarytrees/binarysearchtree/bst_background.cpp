/*
    Time Complexities Comparison Table
    ----------------------------------

    Operation        | Array (Unsorted) | Array (Sorted) | Linked List    | Balanced BST  | Hash Table
    -----------------------------------------------------------------------------------------------
    Search           | O(n)             | O(log n)       | O(n)           | O(log n)      | O(1)
    Insert           | O(1)             | O(n)           | O(1) / O(n)*   | O(log n)      | O(1)
    Delete           | O(1)             | O(n)           | O(n)           | O(log n)      | O(1)
    Find Closest     | O(n)             | O(log n)       | O(n)           | O(log n)      | O(n)
    Sorted Traversal | O(n log n)       | O(n)           | O(n log n)**   | O(n)          | O(n log n)

    * From table, hashing is not good for finding closest value, sorting data[we use AVL tree or red black tree: self balancing binary search trees] and  prefix searching[all keys which match with a particular search: Trie data strucutre is best for it, provides quick prefix searching]
    * Linked List Insert:
        - O(1) for unsorted insertion at head.
        - O(n) for inserting in sorted order.
    ** Sorted Traversal for Linked List:
        - O(n) if already sorted.
        - O(n log n) if sorting is needed.

    ==> Inorder traversal of BST gives us sorted output.
    ==> searching an item complexity is O(H) not O(Log n) becoz assume BST as 1 4 6 8 9, all nodes to right, called as skewed tree,
        worst case height is H, so complexity is O(h) not O(Log n) but when tree is perfectly split i.e best case (balanced BST) 
        then complexity will be O(Log n), so  log(n) <= height <= n
    ==> BST problems follow a recursive structure
    ==> Mostly all problems can be solved by dividing the problem into subproblems and making recursive calls on subtree.

    
Difference between Complete Binary Tree and Balanced Binary Tree:

1. Complete Binary Tree (CBT)
   - Definition: All levels are fully filled except possibly the last, 
     which is filled from left to right.
   - Key Points:
     * Last level may not be full.
     * Nodes at last level are filled left-to-right.
     * Focus is on node placement, not heights or values.
   - Example:
            1
           / \
          2   3
         / \  /
        4  5 6

2. Balanced Binary Tree (Height-Balanced, e.g., AVL)
   - Definition: Height difference between left and right subtrees 
     of every node is at most 1.
   - Key Points:
     * Focus is on height balance.
     * Nodes do not need to be filled left-to-right.
     * Ensures operations like search/insert/delete are O(log n).
   - Example:
            1
           / \
          2   3
         /
        4

Summary Table:

| Property           | Complete Binary Tree        | Balanced Binary Tree          |
|-------------------|----------------------------|-------------------------------|
| Node placement     | Left-to-right fill         | Any, as long as height balanced |
| Last level         | May be partially filled    | Not relevant                  |
| Height difference  | Not considered             | ≤ 1 at every node             |
| Purpose            | Efficient storage in array | Efficient operations (O(log n)) |
*/
