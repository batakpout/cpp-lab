/*
LC 101 Easy Symmetric Tree

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

        1
       / \
      2   2
     / \ / \
    3  4 4  3

    Mirror image check:
	•	Root left = Root right ✅ (2 = 2)
	•	Left subtree’s left child (3) = Right subtree’s right child (3) ✅
	•	Left subtree’s right child (4) = Right subtree’s left child (4) ✅
    above tree is symmetrix

        1
       / \
      2   2
       \    \
        3    3
    •	Root left = Root right ✅ (2 = 2)
	•	Left subtree’s left child = NULL, but right subtree’s right child = 3 ❌
    not symmetric

                1
             /     \
           2         2
         /   \     /   \
       3      4   4      3
      / \    / \ / \    / \
     5  6   7  8 8  7  6  5
*/
#include "tree.h"

bool isMirror(TreeNode* left, TreeNode* right) {
    if(left == NULL && right == NULL) {
        return true;
    }
    if(left == NULL || right == NULL) {
        return false;
    }
    return left->val == right->val &&
    isMirror(left->left, right-> right) &&
    isMirror(left->right, right->left);
}

bool isSymmetrical(TreeNode* root) {
    if(root == NULL) {
        return true;
    }
    return isMirror(root->left, root->right);
}

int main() {
    TreeNode* root = buildLevelOrder();
    return 0;
}