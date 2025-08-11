/**
 Sort a queue with constant space

Given a queue with random elements, we need to sort it. We are not allowed to use extra space. The operations allowed on the queue are :

    push() : Adds an item to the rear of the queue.

    pop() : Removes an item from the front of the queue.

    empty() : Checks if the queue is empty.

    Input  : A queue with elements 
             11 5 4 21 
    Output : Modified queue with following elements
             4 5 11 21
 */

#include<iostream>
#include<sstream>
using namespace std;

int findMinIndex(queue<int> & q, int sortIndex) {
    int minIndex;
    int minValue = INT_MAX;
    int curr;
    int n = q.size();
    for(int i=0;i<n;i++) {
        curr = q.front();
        q.pop();
        if(curr < minValue && i < sortIndex) {
            minValue = curr;
            minIndex = i;
        }
        q.push(curr);
    } 
    return minIndex;
}

void insertMinToRear(queue<int> &q, int minIndex) {
    int minValue;
    int curr;
    int n = q.size();
    for(int i=0;i<n;i++) {
        curr = q.front();
        q.pop();
        if(i != minIndex) {
            q.push(curr);
        } else {
            minValue = curr;
        }
    }
    q.push(minValue);
}

void printQueue(queue<int> q) {
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
}

queue<int> sortqueue(queue<int> &q){
    int n = q.size();
    for (int i = 0; i < n; i++) {
        int minIndex = findMinIndex(q, n-i);
        insertMinToRear(q, minIndex);
       // printQueue(q);

    }
    return q;
}

int main() {

    cout << "enter queue items:\n";
    queue<int> q;
    string line;
    getline(cin, line);
    stringstream ss(line);
    int num;
    while(ss >> num) {
        q.push(num);
    }

    queue<int> res = sortqueue(q);
    queue<inttemp = res;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    return 0;
}