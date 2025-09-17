/*

LC: 501; E; Find Mode in Binary Search Tree

Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.

If the tree has more than one mode, return them in any order.

               5
            /     \
          3         7
        /   \     /   \
       2     3   7     8
      /         /
     2         7
     output: [7]

                10
             /        \
           6            15
         /   \        /    \
        4     6     13     18
       / \         /  \
      4   5      13   14

      output: [4,6,13]

             8
          /     \
        5         12
       / \       /   \
      5   7    12    13
     /          \
    5           12
   /
  5
  output: [5]
*/

#include "../../../tree.h"
#include "../../bst.h"


/*
    Approach1:
    Total Complexity
	•	Time: O(n + k + k)
    Since k ≤ n, this simplifies to O(n) in Big-O terms.
    Auxiliary Space:
	•	Map storage: O(k)
	•	Recursion stack: O(h) (h = height of tree).
    Overall O(k + h).
*/
//O(N)
void helper(TreeNode* root, unordered_map<int, int> & freq) {
    if(!root) {
        return;
    }
    helper(root->left, freq);
    freq[root->val]++;
    helper(root->right, freq);
}

vector<int> findMode(TreeNode* root) {
   unordered_map<int,int> map;
   helper(root, map);
   vector<int> res;
   int maxFreq = 0;

    //O(k)
   for(auto& p: map) {
     if(p.second > maxFreq) {
        maxFreq = p.second;
     }
   }     
   
   //O(k)
   for(auto & p: map) {
     if(p.second == maxFreq) {
        res.push_back(p.first);
     }
   }

   /**
    one pass
       
    for(auto& p: map) {
     if(p.second > maxFreq) {
        maxFreq = p.second;
        res = {};
        res.push_back(p.first);
     } else if(p.second == maxFreq) {
        res.push_back(p.first);
     }
   } 
     For small k (which is typical—k is the number of distinct values, not nodes), the extra map scan is cheap and often faster than repeatedly clearing and reallocating a vector.
    */

   return res;

}

class Approach2 {
  int max_freq = 0;
  int curr_freq = 0;
  int curr_num=0;
  vector<int> v;
  public:
  //beats 100% on leetcode
  void dfs(TreeNode* root) {
    if(root == NULL) return;
    dfs(root->left);
    if(root->val == curr_num) {
       curr_freq++;
    } else {
      curr_num = root->val;
      curr_freq = 1;
    }

    if(curr_freq > max_freq) {
      v={};
      v.push_back(curr_num);
      max_freq = curr_freq;
    }  else if(curr_freq == max_freq) {
      v.push_back(curr_num);
    }
    dfs(root->right);
  }
  vector<int> findMode2(TreeNode* root) { 
      dfs(root);
      return v;
  }
};
//O(N) with no auxillary space


int main() {

    int arr[] = {10, 6, 15, 4, 6, 13, 18, 4, 5, 13, 14};

    TreeNode* root = NULL;
    for(int x: arr) {
        root = insert(root, x);
    }

    cout << "current tree:\n";
    levelOrderTraversal(root);
    
    cout << "\n===output===\n";
    vector<int> res = findMode(root);
    for(int n: res) {
        cout << n << " ";
    }

    cout << endl;
    cout << "\n===Approach2===\n";
    Approach2 approach2;
    vector<int> res2 = approach2.findMode2(root);
      for(int n: res2) {
          cout << n << " ";
      }
    cout << endl;
    return 0;
}
