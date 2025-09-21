/*
LC 98: Medium Validate Binary Search Tree

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:
The left of a node contains only nodes with keys strictly less than the node's key.
The right subtree of a node contains only nodes with keys strictly greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Input: root = [2,1,3]
Output: true

Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
*/

 #include<iostream>
 using namespace std;
 #include "../../../tree.h"
 #include "../../bst.h"

void inorder(TreeNode* root, vector<int> &values) {
    if (root == NULL) return;
    inorder(root->left, values);
    values.push_back(root->val);
    inorder(root->right, values);
}

	//Time: O(n)  In-order traversal visits every node exactly once.
	//Space: O(n) we store everything in list
bool validateBST(TreeNode* root) { 
    vector<int> values;
    inorder(root, values);

    // Check if the list is strictly increasing
    for (int i = 1; i < values.size(); i++) {
        if (values[i] <= values[i-1]) {
            return false;
        }
    }
    return true;
}
/**
 	•	Balanced BST: Height h ≈ log₂(n) Space: O(log n)
	•	Skewed Tree (worst case): Height h = n	Space: O(n) 

Complete Binary Search Tree:

                8
             /     \
           4         12
         /  \      /    \
        2    6   10     14
       / \  / \  / \   /  \
      1  3 5  7 9 11 13  15

 */
bool validate(TreeNode* root, long minVal = LONG_MIN, long maxVal = LONG_MAX) {
    if(root == NULL) {
        return true;
    }
    if(root->val <= minVal || root->val >= maxVal) {
        return false;
    }
    return validate(root->left, minVal, root->val) &&
    validate(root->right, root->val, maxVal);
}

int main() {
//4 2 7 1 3 6 9 -1 -1 -1 -1 -1 -1 -1 -
   TreeNode* root = NULL;
    //int arr[] = {40,20,52,15,25,48,55,12,16,21,26,45,50,54,60};
    int arr[] = {5,1,14,13,68};
    for(int x: arr) {
        root = insert(root, x);
    }

    cout << "current tree:\n";
    levelOrderTraversal(root);

    bool res = validate(root);
    cout << "res: " << res;
    cout << endl;

}
