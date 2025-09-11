/**
 LC 404. E; Sum of Left Leaves

 Given the root of a binary tree, return the sum of all left leaves.
A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.

Input: root = [1]
Output: 0
 */

#include<iostream>
#include "../../tree.h"
using namespace std;

int sumOfLeftLeaves(TreeNode* root) {
    if(!root) return 0;
    int sum =0;
    if(root->left && !root->left->left && !root->left->right) {
        sum = root->left->val;
    }
    sum = sum + sumOfLeftLeaves(root->left);
    sum = sum + sumOfLeftLeaves(root->right);
   return sum;
}

//3 9 20 -1 -1 15 7 -1 -1 -1 -1
 int main() {
    
    TreeNode* root = buildLevelOrder();
    int res = sumOfLeftLeaves(root);
    cout << res;
    cout << endl;

    return 0;

}