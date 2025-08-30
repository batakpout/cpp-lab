/**
  LC: 225; easy Implement Stack using Queues


Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

    void push(int x) Pushes element x to the top of the stack.
    int pop() Removes the element on the top of the stack and returns it.
    int top() Returns the element on the top of the stack.
    boolean empty() Returns true if the stack is empty, false otherwise.

    //todo: Follow-up: Can you implement the stack using only one queue?
 */
#include<iostream>
using namespace std;

class MyStack {
    queue<int> q1, q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
         if(!q1.empty()) {
            q1.push(x);    
        } else {
            q2.push(x);
        }
    }
    
    int pop() {
        if(q1.empty()) {
               while(!q2.empty()) {
                 int front = q2.front();
                 q2.pop();
                 if(q2.empty()) {
                    return front;
                 }
                 q1.push(front);
               } 
        } else {
            while(!q1.empty()) {
                 int front = q1.front();
                 q1.pop();
                 if(q1.empty()) {
                    return front; 
                 }
                 q2.push(front);
               } 
        }  
        return -1;
    }
    
    int peek() {
        if(q1.empty()) {
               while(!q2.empty()) {
                 int front = q2.front();
                 q2.pop();
                 q1.push(front);
                 if(q2.empty()) {
                    return front;
                 }
               } 
        } else {
            while(!q1.empty()) {
                 int front = q1.front();
                 q1.pop();
                 q2.push(front);
                 if(q1.empty()) {
                    return front;
                 }
            } 
        }
        return -1;
    }
    
    bool empty() {
        return q1.empty() && q2.empty();

    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

 int main() {

    MyStack stk;
    stk.push(1);
    stk.push(2);
    stk.pop();
    stk.push(3);
    stk.push(4);
    stk.push(5);
    stk.push(6);
    stk.push(7);
    stk.pop();
    stk.pop();

    while(!stk.empty()) {
        cout << "Peek: " << stk.peek() << endl;
        stk.pop();
    }
    cout << "Empty stack: " << stk.empty();
    return 0;
}