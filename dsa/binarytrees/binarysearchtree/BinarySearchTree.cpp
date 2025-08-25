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

//O(n) worst case, log(n) best case
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

//O(h) Time and O(1) Space
int findFloor(TreeNode* root, int x, int floor=-1) {
    
    if(root == NULL) {
        return floor;
    }

    if(x == root->val) {
        return root->val;
    }
    
    if(x < root->val) { // means we have to go left as we have to find item less than x
        return findFloor(root->left, x, floor);
    } else { // means closest less than x will be on right side
        return findFloor(root->right, x , root->val);
    } 
    
}

//O(N) time and O(h) space, post order version
int findFloorNaive(TreeNode* root, int x) {
    if(root == NULL) {
        return -1;
    }
    int left = findFloorNaive(root->left, x);
    int right = findFloorNaive(root->right, x);

    if(root->val > x) {
        return max(left, right);
    }
    return max({left, right, root->val});
}

//O(h) Time and O(1) Space
int findCeil(TreeNode* root, int x, int ceil=-1) {
    
    if(root == NULL) {
        return ceil;
    }

    if(x == root->val) {
        return root->val;
    }
    
    if(x > root->val) { // means root->val is less than x mean I have to find nearest greater than x so I have to go right side
        return findCeil(root->right, x, ceil);
    } else { // means root->val is a potential candidate, on right there will  be values more than root->val so can't go right
        return findCeil(root->left, x , root->val);
    } 
    
}



int main() {
    TreeNode* root = NULL;
    int arr[] = {10,5,11,4,7,8};
    for(int x: arr) {
        root = insert(root, x);
    }
   // printInOrder(root);
   // cout << endl;

    //cout << "Enter item to search: \n"; int item;cin>>item;
    //bool res = search(root, item);
    //cout << (res ? "Item present: Yes" : "Item present: No");
    //cout << endl;

   // cout << "printing in range:\n";
   // printRange(root, 5,12);
   // cout << endl;

     levelOrderTraversal(root);
     cout << "enter x for floor calculation:";
     int x; cin>>x;
     int r1  = findFloor(root, x);
     int r  = findFloorNaive(root, x);
     cout << "floor1: " << r1;
     cout << "floor2: " << r;
     cout << endl;
     
     cout << "enter x for ceil calculation:";
     int y; cin>>y;
     int r2  = findCeil(root, y);
     cout << "ceil: " << r2;
     cout << endl;
     
    return 0;
}