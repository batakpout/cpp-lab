/**
LC 543 Easy; Diameter of Binary Tree

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

as always keep level order in mind
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

Example 2:

Input: root = [1,2]
Output: 1

 */
#include<iostream>
using namespace std;

class TreeNode {
    public:
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};



TreeNode* buildLevelOrder() {
    int d; cin>>d;
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(d);
    q.push(root);
    while(!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        int d1,d2;
        cin>>d1>>d2;
        if(d1!=-1) {
            curr->left = new TreeNode(d1);
            q.push(curr->left);
        }
        if(d2!=-1) {
            curr->right = new TreeNode(d2);
            q.push(curr->right);
        }
    }
    return root;
}

int height(TreeNode * root) {
  if(root == NULL) {
    return 0;
  }
  int h1 = height(root->left);
  int h2 = height(root->right);
  return 1 + max(h1, h2);
}

//O(N^2)
 int naiveDiameter(TreeNode* root) {
    if(root == NULL) {
        return 0;
    }
    int D1 = height(root->left) + height(root->right);
    int D2 = naiveDiameter(root->left);
    int D3 = naiveDiameter(root->right);
    return max(D1, max(D2, D3));
 }

 class HDPair {
    public:
        int height;
        int diameter;
 };

 HDPair optimized(TreeNode* node) {
    HDPair p;
    if(node == NULL) {
        p.height = p.diameter = 0;
        return p;
    }
    HDPair left = optimized(node->left);
    HDPair right = optimized(node->right);
    p.height = max(left.height, right.height) + 1;
    int D1 = left.height + right.height;
    int D2 = left.diameter;
    int D3 = right.diameter;
    p.diameter = max(D1, max(D2, D3));
    return p;
 }
 
 /*
 1 2 3 4 5 -1 6 -1 -1 -1 7 -1 -1 -1 -1
          1
        /   \
       2     3
      / \      \
     4   5      6
          \
           7
 */
int main() {
    TreeNode* root = buildLevelOrder();
    int res1 = naiveDiameter(root);
    cout << "Diameter: " << res1;
    cout << endl;
    
    int res2 = optimized(root).diameter;
    cout << "Diameter: " << res2;
    cout << endl;
    return 0;
 }