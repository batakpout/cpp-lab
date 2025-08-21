#include<iostream>
using namespace std;
/*

LC 94 Easy;  Binary Tree Inorder Traversal 

//keep level order build in mind
 
Given the root of a binary tree, return the inorder traversal of its nodes' values.


Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [4,2,6,5,7,1,3,9,8]
  */
 void inorderHelper(TreeNode* root, vector<int>& res) {
    if(root == NULL) return;
    inorderHelper(root->left, res);
    res.push_back(root->data);
    inorderHelper(root->right, res);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    inorderHelper(root, res);
    return res;
}



int main() {
    return 0;
}
