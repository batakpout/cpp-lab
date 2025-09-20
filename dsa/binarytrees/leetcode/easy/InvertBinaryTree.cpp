/*
LC 226 Easy Invert Binary Tree

Given the root of a binary tree, invert the tree, and return its root.

 

Example 1:

Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]


Original tree:
        4
       / \
      2   7
     / \ / \
    1  3 6  9

After inverting:
        4
       / \
      7   2
     / \ / \
    9  6 3  1

Level-order output after inversion:
4 7 2 9 6 3 1

*/

#include<iostream>
#include "../../tree.h"
using namespace std;


TreeNode* invert(TreeNode* root) {
    if(root == NULL) {
        return NULL;
    }
    if(root->left == NULL && root->right == NULL) {
        return root;
    }
    swap(root->left, root->right);

    root->left = invert(root->left);
    root->right = invert(root->right);
    return root;
    
}

int main() {
//4 2 7 1 3 6 9 -1 -1 -1 -1 -1 -1 -1 -1
   cout << "Enter data for level order\n"; 
   TreeNode* root = buildLevelOrder();
   cout << "Level order tree";
   levelOrderTraversal(root);
   cout << endl;

   TreeNode* invertedRoot = invert(root); 
   cout << "After inverting tree:\n";
   levelOrderTraversal(invertedRoot);
   cout << endl;

}
