
/**
  LC 110. E; Balanced Binary Tree
  Given a binary tree, determine if it is height balanced. A height balanced binary tree is a
  binary tree in which the depth/height of the two sub-trees of every node never differes by
  more than 1.
Input: root = [3,9,20,null,null,15,7]
Output: true

Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

This program checks if a binary tree is height-balanced:
for every node, the heights of left and right subtrees differ by at most 1.

Example 1 (Balanced) - Input:
3 9 20 -1 -1 15 7 -1 -1 -1 -1

        3
       / \
      9   20
         /  \
        15   7

Expected output:
IsHeightBalanced: Yes


Example 2 (Not Balanced) - Input:
1 2 2 3 3 -1 -1 -1 -1 4 4 -1 -1 -1 -1 -1 -1

            1
          /   \
         2     2
        / \
       3   3
      / \
     4   4

Expected output:
IsHeightBalanced: No


 */
#include<iostream>
#include "../../tree.h"
using namespace std;

//O(N)
 int dfs(TreeNode* root) {
   
    if (!root) return 0; // !root memory efficient

    int left = dfs(root->left);
    if (left == -1) return -1;
    
    int right = dfs(root->right);
    if (right == -1) return -1;
    
    if (abs(left - right) > 1) return -1;
    
    return 1 + (left > right ? left : right); //memory efficient
 }

 bool isHeightBalanced(TreeNode* root) {
     return dfs(root) != -1;
}


//3 9 20 -1 -1 15 7 -1 -1 -1 -1 ==> yes
// 1 2 2 3 3 -1 -1 -1 -1 4 4 -1 -1 -1 -1 -1 -1 ==> no
int main() {
    TreeNode* root = buildLevelOrder();
    levelOrderTraversal(root);
    cout << endl;
    bool res = isHeightBalanced(root);
    cout << "IsHeightBalanced: " << ((res == 1) ? "Yes" : "No");
    cout << endl;

    return 0;

}
