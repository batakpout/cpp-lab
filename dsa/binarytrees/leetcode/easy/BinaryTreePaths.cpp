/**
257 Easy Binary Tree Paths

Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

Example 1: 
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]

Example 2:

Input: root = [1]
Output: ["1"]

 */
#include "../../tree.h"

//O(N) uses backtracking
void helper(TreeNode* root, string path, vector<string> &res) {
    if(root == NULL) {
        return;
    }
    if(!path.empty()) {
        path += "->";
    }
    path += to_string(root->val);
    if(root->left==NULL && root->right==NULL) {
        res.push_back(path);
        return;
    }
    helper(root->left, path, res);
    helper(root->right, path, res);
 
}

//TC: O(N), SC: O(h)
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    helper(root, "", res);
    return res;
 
}

//1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1 
 int main() {

    cout << "Enter data for level order:\n";
    TreeNode * root1 = buildLevelOrder();
    cout << "level order traversal: \n";
    levelOrderTraversal(root1);
    cout << endl;
    cout << "Binary paths:\n";
    vector<string> res1 = binaryTreePaths(root1);

    for(string s: res1) {
        cout << s;
        cout << endl;
    }
    cout << endl;
    
    return 0;
 }
