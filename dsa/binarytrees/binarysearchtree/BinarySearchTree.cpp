#include<iostream>
#include "../tree.h"
using namespace std;

TreeNode* insert(TreeNode* root, int val) {
    if(root == NULL) {
        return new TreeNode(val);
    }
    if(val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

void printInOrder(TreeNode* root) {
    if(root == NULL) {
        return;
    }
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

//since BST so restrict we search in one direction at each point
//time-complexity:O(h) i.e log(n) best case and o(n) worst case i.e log(n) <= h <= n
//Important: so in BST complexity depends upon the structure of the tree.
//binary tree will take O(n) for this
bool search(TreeNode * root, int target) {
    if(root == NULL) {
        return false;
    }
    if(root->val == target) {
        return true;
    }
    if(target < root->val) {
         return search(root->left, target);
    } else {
         return search(root->right, target);
    }
}

void printRange(TreeNode* root, int low, int high) {
    if(root == NULL) {
        return;
    }
    if(root->val>=low && root->val <=high) {
        printRange(root-> left, low, high);
        cout << root->val << " ";
        printRange(root->right, low, high);
     } else if(root->val > high) {
        printRange(root->left, low, high);
     } else { // (root->val<low)
        printRange(root->right, low, high);
     }

}



int main() {
    TreeNode* root = NULL;
    int arr[] = {8,3,10,1,6,14,4,7,13};
    for(int x: arr) {
        root = insert(root, x);
    }
    printInOrder(root);
    cout << endl;

    cout << "Enter item to search: \n"; int item;cin>>item;
    bool res = search(root, item);
    cout << (res ? "Item present: Yes" : "Item present: No");
    cout << endl;
    cout << "printing in range:\n";
    printRange(root, 5,12);
    cout << endl;

    return 0;
}