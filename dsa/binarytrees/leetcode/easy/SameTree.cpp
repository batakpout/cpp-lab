/**
LC: 100; Easy Same Tree

Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Example 1:
Input: p = [1,2,3], q = [1,2,3]
Output: true

 */
#include<iostream>
#include "../../tree.h"
using namespace std;

 bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) {
            return true;
        }
        if (p == NULL || q == NULL) {
            return false; // one is empty, the other isn't, imp. check for uneven tree 
        }
        return (p->val == q->val) &&
        isSameTree(p->left, q->left) &&
        isSameTree(p->right, q->right);
    }

int main() {

    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
   // 1 2 3 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    TreeNode* root1 = buildLevelOrder();
    TreeNode* root2 = buildLevelOrder();
    cout << "checking is same tree:\n";
    bool res = isSameTree(root1, root2);
   cout << res;
    cout << endl;
    return 0;
    return 0;
}
