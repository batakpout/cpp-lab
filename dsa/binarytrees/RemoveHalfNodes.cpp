#include<iostream>
#include "tree.h"
using namespace std;
/*
Example:
Input tree (level order):
        1
       / \
      2   3
       \
        4
       / \
      5   6

After removal of 2:
        1
       / \
      4   3
     / \
    5   6

In-order output:
5 4 6 1 3
*/
TreeNode* removeHalfNodes(TreeNode* root) {

    if(root == NULL) {
        return NULL;
    }
    root->left = removeHalfNodes(root->left);
    root->right = removeHalfNodes(root->right);
    if(root->left == NULL && root->right != NULL) {
        TreeNode* newNode = root->right;
        delete root;
        return newNode;
    }
    if(root->right == NULL && root->left != NULL) {
        TreeNode* newNode = root->left;
        delete root;
        return newNode;
    }
    return root;
}

void inOrderDisplay(TreeNode* root) {
    if(root == NULL) {
        return;
    }
    inOrderDisplay(root->left);
    cout << root->val << " ";
    inOrderDisplay(root->right);

}
int main() {

  TreeNode* root = buildLevelOrder();
  TreeNode* newRoot = removeHalfNodes(root);
  inOrderDisplay(newRoot);  
  cout << endl;
}
