#include <iostream>
#include <stack>
#include <string>
using namespace std;

template <typename T>
class Node {
 public:

      T data;
      Node *next;
  //It’s a special syntax to initialize member variables before the constructor body runs.
     Node(T data): data(data), next(nullptr){}

};

template <typename T>
class StackLL {

      private:
        Node<T>* head = nullptr;
      public:
        void push(T data) {
            Node<T>* n = new Node<T>(data);
            n->next=head;
            head = n;
        }        
        bool empty() {
            return head == nullptr;
        }

        T top() {
           if(!empty()) { 
            return head->data;
           }
           throw runtime_error("Stack is empty");
        }

        void pop() {
            if(!empty()) {
                Node<T>* temp = head;
                head = head-> next;
                delete temp;
            }
        }
        ~StackLL() { // Destructor to free memory
        //	•	It is automatically called when an object goes out of scope or is deleted.

        while (!empty()) {
            pop();
        }
    }
};
int main() {
  
    StackLL<char> s;

    s.push('h');
    s.push('e');
    s.push('l');
    s.push('l');
    s.push('o');

    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}