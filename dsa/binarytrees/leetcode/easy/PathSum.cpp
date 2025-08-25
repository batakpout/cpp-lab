
/**
LC 112; easy; Path Sum


Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.
                 5
               /   \
             4       8
           /       /   \
        11      13      4
       /   \              \
     7      2              1

    targetSum = 22 output true

     1
    / \
   2  3
   targetSum = 5 output false 
 */
#include<iostream>
#include "../../tree.h"
using namespace std;

bool helper(TreeNode* root, int targetSum) {
    if(root == NULL) {
        return false;
    }

    if(root->left == NULL && root->right == NULL) {
        return targetSum == root->val;
    }

    return helper(root->left, targetSum - root->val) || //short circut operator, won't go to right branch if left branch returns true
           helper(root->right, targetSum-root->val); 
}

bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root, targetSum);
}

int main() {

     // 5,4,8,11,-1,13,4,7,2,-1,-1,-1,1
    TreeNode* root = buildLevelOrder();
     bool res = hasPathSum(root, 22);
     cout << res;
    cout << endl;
    return 0;
}
