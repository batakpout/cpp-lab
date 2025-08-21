/**
LC 104 Easy; Maximum Depth of Binary Tree


Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
keep level order build in mind
Input: root = [3,9,20,null,null,15,7]
Output: 3
 */
#include<iostream>
using namespace std;

class TreeNode {
  public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int d) {
        data = d;
        left=right=NULL;
    }

 };
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
