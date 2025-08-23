#include<iostream>
#include "tree.h"
using namespace std;

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