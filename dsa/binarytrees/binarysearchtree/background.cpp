/*
    Time Complexities Comparison Table
    ----------------------------------

    Operation        | Array (Unsorted) | Array (Sorted) | Linked List    | Balanced BST  | Hash Table
    -----------------------------------------------------------------------------------------------
    Search           | O(n)             | O(log n)       | O(n)           | O(log n)      | O(1)
    Insert           | O(1)             | O(n)           | O(1) / O(n)*   | O(log n)      | O(1)
    Delete           | O(n)             | O(n)           | O(n)           | O(log n)      | O(1)
    Find Closest     | O(n)             | O(log n)       | O(n)           | O(log n)      | O(n)
    Sorted Traversal | O(n log n)       | O(n)           | O(n log n)**    | O(n)          | O(n log n)

    * Linked List Insert:
        - O(1) for unsorted insertion at head.
        - O(n) for inserting in sorted order.
    ** Sorted Traversal for Linked List:
        - O(n) if already sorted.
        - O(n log n) if sorting is needed.

    ==> Inorder traversal of BST gives us sorted output.
    ==> searching an item complexity is O(H) not O(Log n) becoz assume BST as 1 4 6 8 9, all nodes to left, called as skewed tree,
        worst case height is H, so complexity is O(h) not O(Log n) but when tree is perfectly split i.e best case (balanced BST) 
        then complexity will be O(Log n), so  log(n) <= height <= n
    ==> BST problems follow a recursive structure
    ==> Mostly all problems can be solved by dividing the problem into subproblems and making recursive calls on subtree.

    
*/
