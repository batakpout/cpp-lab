/**
 LC 108; E Convert Sorted Array to Binary Search Tree
Easy

Given an integer array nums where the elements are sorted in ascending order, convert it to a
height-balanced binary search tree. (A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.)

Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted
 */
#include<iostream>
#include "../../../tree.h"

using namespace std;

TreeNode* helper(vector<int>& nums, int low, int high) {
    if(low>high) {
        return NULL;
    }
    int mid = low + (high-low)/2;
    TreeNode* node = new TreeNode(nums[mid]);
    node->left = helper(nums, low, mid-1);
    node->right = helper(nums, mid+1, high);
    return node;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return helper(nums, 0, nums.size()-1); 
}


int main() {

    vector<int> arr = {-10,-3,0,5,9};

    TreeNode* root = sortedArrayToBST(arr);
    cout << "bst:\n";
    levelOrderTraversal(root);

    cout << endl;

    return 0;
}