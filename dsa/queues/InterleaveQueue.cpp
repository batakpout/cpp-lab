/**
 Interleave two halves of a queue

Given a queue of integers of even length, rearrange the elements by interleaving the first half of the queue with the second half of the queue.

Input Format

In the function an integer queue passed.

Output Format

Return the interleaved queue .


Sample Input

    11 12 13 14 15 16 17 18 19 20

Sample Output

    11 16 12 17 13 18 14 19 15 20
 */

#include<iostream>
using namespace std;

queue<int> interleave(queue<int> q) {

    if (q.empty() || q.size() % 2 != 0) {
        throw runtime_error("Queue must have even number of elements");
    }

    int half = q.size() / 2;
    queue<int> firstHalf;
    queue<int> result;

    // Step 1: Split the queue into firstHalf and remaining
    for (int i = 0; i < half; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    // Step 2: Interleave
    while (!firstHalf.empty()) {
        result.push(firstHalf.front());
        firstHalf.pop();

        result.push(q.front());
        q.pop();
    }

    return result;
  
}

int main() {

      queue<int> q;
    for (int i = 11; i <= 20; i++) {
        q.push(i);
    }

    try {
        queue<int> ans = interleave(q);

        while (!ans.empty()) {
            cout << ans.front() << " ";
            ans.pop();
        }
        cout << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}