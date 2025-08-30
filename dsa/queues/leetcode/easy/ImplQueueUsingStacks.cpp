#include <iostream>
#include <stack>
using namespace std;

/* 
Amortized time complexity is the average time per operation over a sequence of operations, even if some individual operations are costly.

 * Operation   | Worst Case | Amortized
 * ----------- | ---------- | ---------
 * push        | O(1)       | O(1)
 * pop         | O(n)       | O(1)
 * peek        | O(n)       | O(1)
 * empty       | O(1)       | O(1)
 */

class MyQueue {
public:
    stack<int>input, output;
    MyQueue() {

    }
    
    void push(int x) {
        input.push(x);
    }
    
    void pop() {
        if(output.empty()) {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
         }
       output.pop();  
    }
    
    int peek() {
        if(output.empty()) {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
         }
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};

int main() {
    MyQueue q;

    //Pushing elements into the queue
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Front element: " << q.peek() << endl;  // Output: 1

     q.pop(); 
     q.pop();

    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;  // Output: No

    q.push(4);
    cout << "Front element: " << q.peek() << endl;  // Output: 3

     q.pop(); 
     q.pop(); 

    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;  // Output: Yes

    return 0;
}