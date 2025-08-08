/**
 * O(1) push, O(N) for pop and peek
 */
#include<iostream>
using namespace std;

class StackUsingQueue {

    queue<int> q1, q2;
    public:
    void push(int item) {
        if(!q1.empty()) {
            q1.push(item);    
        } else {
            q2.push(item);
        }
    }

    void pop() {
        if(q1.empty()) {
               while(!q2.empty()) {
                 int front = q2.front();
                 q2.pop();
                 if(q2.empty()) {
                    break;    
                 }
                 q1.push(front);
               } 
        } else {
            while(!q1.empty()) {
                 int front = q1.front();
                 q1.pop();
                 if(q1.empty()) {
                    break;    
                 }
                 q2.push(front);
               } 
        } 
    }

    int peek() { //top
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

int main() {

    StackUsingQueue stk;
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