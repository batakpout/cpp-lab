  #include<iostream>
  using namespace std;

 class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        data = d;
        left=right=NULL;
    }

 };
  // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
 Node* build() {
    int d;cin>>d;
    if(d==-1) {
        return NULL;
    }
    Node* node = new Node(d);
    node->left  = build();
    node->right = build();
    return node; 
 }

 //DFS: pre,post,in order traversal
 //DFS:I’ll go as deep as possible in one direction before I backtrack

 void preOrderTraversal(Node* root) {
    if(root == NULL) {
      return;
    }
    cout << root -> data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root-> right);

 }

  void inOrderTraversal(Node* root) {
    if(root == NULL) {
      return;
    }
    inOrderTraversal(root->left);
    cout << root -> data << " ";
    inOrderTraversal(root-> right);

 }

  //bottom-up traversal
   void postOrderTraversal(Node* root) {
    if(root == NULL) {
      return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root-> right);
    cout << root -> data << " ";

 }

 //BFS: I’ll visit all nodes at the current level before going to the next level.
  void levelOrderTraversal(Node* root) {

  }

  int main() {
    Node* root = build();
    cout << "pre order traversal: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "in order traversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "post order traversal: ";
    postOrderTraversal(root);
    cout << endl;
    return 0;
  }
