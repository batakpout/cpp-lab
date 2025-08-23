// tree.h
#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <queue>
#include <climits>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Implementation directly in header
TreeNode* buildLevelOrder() {    
    int val;
    cin >> val;
    
    if (val == -1) return nullptr;
    
    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        
        // Left child
        cin >> val;
        if (val != -1) {
            curr->left = new TreeNode(val);
            q.push(curr->left);
        }
        
        // Right child  
        cin >> val;
        if (val != -1) {
            curr->right = new TreeNode(val);
            q.push(curr->right);
        }
    }
    
    return root;
}

#endif // TREE_H