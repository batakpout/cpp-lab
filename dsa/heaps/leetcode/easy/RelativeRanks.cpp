/*Exactly 👍 you spotted the two natural approaches here:

⸻

🔹 Approach 1: Sorting + O(n) iterate
	1.	Make a vector of pairs (score, index).
	•	Keep the original index so you know where to put the rank later.
	2.	Sort descending by score.
	3.	Iterate through sorted vector:
	•	If i==0 → "Gold Medal"
	•	If i==1 → "Silver Medal"
	•	If i==2 → "Bronze Medal"
	•	Else rank = to_string(i+1)
	4.	Place rank in the answer[index].

Complexity
	•	Sorting: O(n log n)
	•	Iteration: O(n)
	•	Total: O(n log n)
	•	Space: O(n) (for pairs + answer).

This is the most common solution because it’s straightforward and efficient.

⸻

🔹 Approach 2: Priority Queue
	1.	Push all (score, index) into a max-heap (priority queue).
	2.	Pop one by one:
	•	Assign “Gold Medal”, “Silver Medal”, etc., based on pop order.
	•	Since heap always gives the largest remaining score.

Complexity
	•	Heap insertions: O(n log n)
	•	Popping n elements: O(n log n)
	•	Total: O(n log n)
	•	Space: O(n)

So complexity is the same as sorting.

⸻

🔹 Which is better?
	•	Sorting is usually faster in practice (lower constant factor, optimized in STL).
	•	Priority queue is good if you need only the top k ranks instead of all n.

⸻

✅ For this problem where we need all ranks, sorting is simpler and better.

⸻

Do you want me to write out both C++ solutions side by side so you can compare sorting vs priority_queue?
*/

/**
 vector<pair<int,string>> v;
pair<int,string>> p(1, "hello");
v.push_back(p);                // copies p into v
v.push_back(make_pair(2,"hi")); // moves (since temporary)
 Here, the pair is created outside the vector, then copied/moved into the vector.

 vector<pair<int,string>> v;
v.emplace_back(1, "hello");   // constructs pair<int,string>(1,"hello") directly in vector

Here no temporary pair is made outside. The pair is built in place inside the vector.

 */

#include<iostream>
using namespace std;

//Time: O(n log n), Space: O(n)
vector<string> findRelativeRanks1(vector<int>v) {
    vector<pair<int,int>> pairs;
    pairs.reserve(v.size());  //Pre-allocates memory to avoid reallocations during push_back

    for(int i=0;i<v.size();i++) {
         pairs.emplace_back(v[i], i); //  Constructs pair in-place, slightly faster than push_back
    }
    sort(pairs.begin(), pairs.end(), greater<pair<int,int>>());
    
    vector<string> result(v.size());
    const string medals[] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
    
    for (int i = 0; i < pairs.size(); i++) {
        int originalIndex = pairs[i].second;
        if (i < 3) {
            result[originalIndex] = medals[i];
        } else {
            result[originalIndex] = to_string(i + 1);
        }
    }

    return result;
}

/*
    with priority queue
     Insert all (score, index) pairs
    for (int i = 0; i < scores.size(); i++) {
        maxHeap.push({scores[i], i});
    }
        rest will be same
*/
int main() {
    vector<int> v = {10,3,8,9,4};
    vector<string> res = findRelativeRanks1(v);
    for(string ch: res) {
        cout << ch << " ";
    }
    cout << endl;
}