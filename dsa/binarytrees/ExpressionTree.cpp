#include <iostream>
using namespace std;

//todo: Construct expression tree
struct Node {
    string key;    
    Node* left;
    Node* right;
    Node(string v) : key(v), left(NULL), right(NULL) {}
};

//TC: O(N), maximum recursion depth O(N), post order
int evalTree(Node* root) {

    if (root == NULL) {
        return 0;
    }

    if (root->left ==NULL && root->right == NULL) {
        return stoi(root->key);
    }

    int leftVal = evalTree(root->left);
    int rightVal = evalTree(root->right);

    if (root->key == "+") {
        return leftVal + rightVal;
    } else if (root->key == "-") {
        return leftVal - rightVal;
    } else if (root->key == "*") {
        return leftVal * rightVal;
    } else if (root->key == "/") {
        if (rightVal == 0) {
            throw runtime_error("Division by zero");
        }
        return leftVal / rightVal;
    } else {
        throw runtime_error("Invalid operator: " + root->key);
    }
}

int main() {
    /*
          +
         / \
        *   3
       / \
      +   2
     / \
    5   9
    */

    Node* root = new Node("+");
    root->left = new Node("*");
    root->right = new Node("3");
    root->left->left = new Node("+");
    root->left->right = new Node("2");
    root->left->left->left = new Node("5");
    root->left->left->right = new Node("9");

    cout << evalTree(root) << endl; // Output: 31
    return 0;
}