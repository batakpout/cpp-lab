/**
LC 450 Medium Delete Node in a BST


Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.


 */

 #include<iostream>
 using namespace std;
 #include "../../../tree.h"
 #include "../../bst.h"

 /*
When we delete a node, three cases may arise:

1. Node to be deleted is leaf:
   Simply remove from the tree.

            50
           /  \
         30    70
        / \   / \
      20 40 60  80

   delete(20)  ------>

            50
           /  \
         30    70
          \   / \
          40 60 80


2. Node to be deleted has only one child:
   Copy the child to the node and delete the child.

            50
           /  \
         30    70
          \   / \
          40 60 80

   delete(30)  ------>

            50
           /  \
         40    70
              / \
             60 80


3. Node to be deleted has two children:
   Find inorder successor of the node(find the smallest node in the right subtree).
   Copy contents of the inorder successor to the node
   and delete the inorder successor.
   Note that inorder predecessor can also be used.

            50
           /  \
         40    70
               / \
             60  80

   delete(50)  ------>

            60
           /  \
         40    70
                \
                 80
*/

TreeNode* findMinNode(TreeNode* root) {
    while(root->left!=NULL) {
        root = root->left;
    }
    return root;
}

 TreeNode* deleteNode(TreeNode* root, int target) {
    if(root == NULL) {
        return NULL;
    }
   
    if(target<root->val) {
        root->left = deleteNode(root->left, target);
    }
    else if(target>root->val) {
        root->right = deleteNode(root->right, target);
    } else { //now it is equal

        // No children 
        if(root->left == NULL && root->right==NULL) {
            delete root;
            root = NULL;
        }// Single Child
       else if(root->left == NULL) {
            TreeNode* temp = root;
            root = root->right;
            delete temp;
       }
        else if(root->right == NULL) {
            TreeNode* temp = root;
            root =  root->left;
            delete temp;
       } else { //2 children
          TreeNode* temp = findMinNode(root->right);
          root->val = temp->val;
          root->right= deleteNode(root->right, temp->val);
       }
    }
    return root;

}

int main() {
    TreeNode* root = NULL;
    int arr[] = {8,3,10,1,6,14,4,7,13};
    for(int x: arr) {
        root = insert(root, x);
    }

    cout << "current tree:\n";
    levelOrderTraversal(root);
    cout << "Enter a node to delete:";
    int d; cin>>d;
    TreeNode* rootAfterDelete = deleteNode(root, d);
    levelOrderTraversal(rootAfterDelete);

    cout << endl;

    return 0;
}
