  #include<iostream>
  using namespace std;

  /*
  - Max no. of nodes at level i = 2^(i-1) e.g at level 2 ==> 2 
  - Max possible height of binary tree with N nodes = log(N+1) with base 2
*/
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

 /*
        1
       / \
      2   3
     / \  / \
    4  5 6   7

Traversal Outputs:

Pre-order (Root → Left → Right):
1 2 4 5 3 6 7

In-order (Left → Root → Right):
4 2 5 1 6 3 7

Post-order (Left → Right → Root):
4 5 2 6 7 3 1

Level-order
1 2 3 4 5 6 7
 */
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

 Node* buildLevelOrderTree() {
   int c;cin>>c;
   Node* root = new Node(c);
   queue<Node*> q;
   q.push(root);

   while(!q.empty()) {
      Node* current = q.front();
      q.pop();

      int c1, c2;
      cin>>c1>>c2;

      if(c1!=-1) {
        current->left=new Node(c1);
        q.push(current->left);
      }
      if(c2!=-1) {
        current->right=new Node(c2);;
        q.push(current->right);
      }
   }
   return root;
 }

 //BFS: I’ll visit all nodes at the current level before going to the next level.
  void levelOrderTraversal(Node* root) {
      queue<Node*> q;
      q.push(root);
      q.push(NULL);

      while(!q.empty()) {
         Node* temp = q.front();
         if(temp == NULL) {
           q.pop();
           cout << endl;
           if(!q.empty()) {
              q.push(NULL);
           }
         } else {
            cout << temp->data;
            q.pop();
            if(temp->left) { //temp->left != NULL
               q.push(temp->left);
            }
            if(temp->right) {
              q.push(temp->right);
            }
         }
      }
  }

  //post-order traversal
  void printKthLevelNodes(Node * root, int level, int k) {
    if(root == NULL) {
        return;
    }

    printKthLevelNodes(root -> left, level+1, k);
    printKthLevelNodes(root -> right, level+1, k);
    if(level == k) {
       cout << root->data << " ";
    }
}

int height(Node * root) {
  if(root == NULL) {
    return 0;
  }
  int h1 = height(root->left);
  int h2 = height(root->right);
  return 1 + max(h1, h2);
}



int sumBT(Node * root) {
  if(root == NULL) {
    return 0;
  }

  int leftSum = sumBT(root -> left);
  int rightSum = sumBT(root -> right);
  return root -> data + leftSum + rightSum;
}

//TC: O(N), auxillary space[recursive stack]: O(h+1); h = height of tree +1 for NULL value
int sizeBT(Node * root) {
  if(root == NULL) {
    return 0;
  }

  return 1 + sizeBT(root -> left) + sizeBT(root -> right);
}


  //1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1 

  int main() {
   /*
      cout << "Enter a line of input:\n";
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
    */

  
    cout << "Enter data for level order:\n";
    Node * root1 = buildLevelOrderTree();
    cout << "level order traversal: \n";
    levelOrderTraversal(root1);
    cout << endl;
 
    cout << "enter kth level to display:";
    int k;cin>>k;
    printKthLevelNodes(root1,1,k);

    cout << endl;
    int h = height(root1);
    cout << "height of this tree: " << h;
    cout << endl;

    cout << endl;
    int s = sumBT(root1);
    cout << "sum of this tree: " << s;
    cout << endl;

    int size = sizeBT(root1);
    cout << "size of this tree: " << size;
    cout << endl;
    return 0;
  }