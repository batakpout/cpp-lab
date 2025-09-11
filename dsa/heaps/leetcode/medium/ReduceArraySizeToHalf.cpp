/**
  LC 1338 M Reduce Array Size to Half

  You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.

Return the minimum size of the set so that at least half of the integers of the array are removed.

 

Example 1:

Input: arr = [3,3,3,3,5,5,5,2,2,7]
Output: 2
Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 (i.e equal to half of the size of the old array).
Possible sets of size 2 are {3,5},{3,2},{5,2}.
Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5] which has a size greater than half of the size of the old array.

 Approach1:
   input: arr = [3,3,3,3,5,5,5,2,2,7]
   Step 1 — Count Frequencies
   Number freq.
   3        4
   5        3
   2        2
   7        1
 Total elements = 10
 Half = 5
 Step 2 — Sort Frequencies Descending

Frequencies = [4, 3, 2, 1]

Step 3 — Pick Highest Frequencies First (Greedy)

We remove numbers based on highest frequencies, not specific values.
	•	Pick freq 4 → removed = 4
	•	Pick freq 3 → removed = 7
Now removed ≥ 5 → stop here.

So, we picked 2 numbers (doesn’t matter if they’re {3,5} or {3,7} — we only count how many numbers).

one more:
arr = [1,2,3,4,5,6]
Total = 6 → Half = 3
Sorted Freqs → [1,1,1,1,1,1]

Answer = 3
 -A greedy algorithm always makes the locally optimal choice at each step, hoping it leads to the globally optimal solution.

--> Can be solved with priority queue also
 */


/**
 Approach 1:
Complexity
	•	Frequency count: O(n)
	•	Copy to vector: O(m) → where m = number of unique elements
	•	Sort vector: O(m log m)
	•	Final loop: O(m)
	•	Total Time: O(n + m log m)
	•	Space: O(m) (map + vector)
 */
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int minSetSize1(vector<int>& arr) {
    unordered_map<int, int> freq;
    
    for(int num: arr) freq[num]++;

    vector<int> counts;
    for(auto &p: freq) counts.push_back(p.second);

    sort(counts.begin(), counts.end(), greater<int>());

    int removed=0, setSize=0,  half=arr.size()/2;
    for(int c: counts) {
      removed += c;
      setSize++;
      if(removed >= half) break;
    }
    return setSize;

}

/**
 Approach 2:
Complexity
	•	Frequency count: O(n)
	•	Push m freq items into heap: O(m log m) (each push takes O(log m))
	•	Pop from heap: O(m log m)
	•	Total Time: O(n + m log m)
	•	Space: O(m) (map + heap)
 */

 int minSetSize2(vector<int>& arr) {
    unordered_map<int, int> freq;
    
    for(int num: arr) freq[num]++;

    priority_queue<int> maxHeap;
    for(auto &p: freq){
      maxHeap.push(p.second);
    }
 

    int removed=0, setSize=0,  half=arr.size()/2;
    while(removed<half) {
      removed += maxHeap.top();
      setSize++;
      maxHeap.pop();
    }
    return setSize;

}

int main() {
  //3,3,3,3,5,5,5,2,2,7
  //7,7,7,7,7,7
  vector<int> v = {7,7,7,7,7,7};
  int res1 = minSetSize1(v);
  int res2 = minSetSize2(v);
  cout << res1 << endl << res2 << endl;
  return 0;
}
