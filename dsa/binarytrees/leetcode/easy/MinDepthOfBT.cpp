/**

LC 111 Easy Minimum Depth of Binary Tree

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children

Input: root = [3,9,20,null,null,15,7]
Output: 2

Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5

🔍 When to Use BFS?

When we hear "shortest path" or "closest" in the context of trees or graphs, Breadth-First Search (BFS) is an excellent choice.
BFS explores the tree level by level. The first time we encounter a leaf node, we’re guaranteed it's at the minimum possible depth.


This program finds the minimum depth of a binary tree
(the number of nodes on the shortest path from root to the nearest leaf).

Example 1
Input (level order):
3 9 20 -1 -1 15 7 -1 -1 -1 -1

Tree:
        3
       / \
      9   20
          / \
         15  7

Minimum depth path: 3 -> 9
Expected output:
Min Depth: 2


Example 2
Input (level order):
2 -1 3 -1 4 -1 5 -1 6 -1 -1

Tree:
    2
     \
      3
       \
        4
         \
          5
           \
            6

Minimum depth path: 2 -> 3 -> 4 -> 5 -> 6
Expected output:
Min Depth: 5
*/
#include "../../tree.h"

int minDepthBFS(TreeNode* root) {
    if(root == NULL) {
        return 0;
    }
    queue<TreeNode*> q;
    q.push(root);

    int depth=1;
    while(!q.empty()) {
        int n = q.size();
        while(n--) {
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left == NULL && curr->right == NULL) {
                return depth;
            }
            if(curr->left != NULL) {
                q.push(curr->left);
            }
            if(curr->right != NULL) {
                q.push(curr->right);
            }
        }
        depth++;
    }
    return -1;

}

int minDepthDFS(TreeNode* root) {
    if(root == NULL) {
        return 0;
    }
    if(root->left == NULL && root->right == NULL) {
        return 1;
    }
   
    int leftH = root->left != NULL ? minDepthDFS(root->left) : INT_MAX;
    int rightH = root->right != NULL ? minDepthDFS(root->right): INT_MAX;

    return 1 + min(leftH, rightH);
}



//3 9 20 -1 -1 15 7 -1 -1 -1 -1 ==> 2
//2 -1 3 -1 4 -1 5 -1 6 -1 -1 ==> 5
int main() {
    TreeNode* root = buildLevelOrder();
    int res1 = minDepthBFS(root);
    cout << "Min Depth: " << res1;
    cout << endl;

    int res2 = minDepthDFS(root);
    cout << "Min Depth: " << res2;
    cout << endl;

    return 0;

}
