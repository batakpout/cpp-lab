#include<iostream>
using namespace std;
/*

LC 94 Easy;  Binary Tree Inorder Traversal 

keep level order build in mind
 
Given the root of a binary tree, return the inorder traversal of its nodes' values.


Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [4,2,6,5,7,1,3,9,8]
  */
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
  // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1


TreeNode* build() {
    int d;cin>>d;
    if(d==-1) {
        return NULL;
    }
    TreeNode* node = new TreeNode(d);
    node->left  = build();
    node->right = build();
    return node; 
 }

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

    TreeNode* root = build();
    vector<int> res = inorderTraversal(root);
    for(int item: res) {
        cout << item << " ";
    }
    cout << endl;
    return 0;
}
