/*
LC 938; Easy; Range Sum of BST
Easy


Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.

*/

#include "../../../tree.h"
#include "../../bst.h"
/*
            10
           /  \
          5    15
         / \     \
        3   7     18
Example Call:
    rangeSumBST(root, 7, 15);
    Total Sum = 10 + 7 + 15 = 32
*/
int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == NULL) {
            return 0;
        }
        if(root->val > high) {
            return rangeSumBST(root->left, low, high);
        } else if(root->val<low) {
            return rangeSumBST(root->right, low, high);
        } else {
            return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        }
}

int main() {
    TreeNode* root = NULL;
    int arr[] = {10,5,15,3,7,13,18,1,6};
    for(int x: arr) {
        root = insert(root, x);
    }

    cout << "current tree:\n";
    levelOrderTraversal(root);
    
    int res = rangeSumBST(root, 6,10);
    
    cout << "sum is: " << res;

    cout << endl;

    return 0;
}
