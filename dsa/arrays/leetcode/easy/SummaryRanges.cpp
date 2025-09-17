
/**
  LC: Easy: 228 Summary Ranges
  You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

    "a->b" if a != b
    "a" if a == b
Example 1:

Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"

Example 2:

Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"

 

Constraints:

    0 <= nums.length <= 20
    -231 <= nums[i] <= 231 - 1
    All the values of nums are unique.
    nums is sorted in ascending order.


Take nums = [0,1,2,4,5,7].
	1.	Start at the first number (0) – this begins a range.
	2.	Keep moving while the next number is exactly +1:
	•	0 → 1 (yes)
	•	1 → 2 (yes)
	•	2 → 4 (stop, not consecutive)
	3.	End of first range: start=0, end=2 → "0->2".
	4.	Next range starts at 4.
	•	4 → 5 (yes)
	•	5 → 7 (stop)
→ "4->5".
	5.	Next is 7 alone → "7".

Final answer: ["0->2","4->5","7"].
 */
#include<iostream>
using namespace std;

//O(N)
vector<string> summaryRanges(vector<int>& nums) {
    if (nums.empty()) return {};
    
    vector<string> result;
    int start = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        if (i == nums.size() - 1 || nums[i + 1] != nums[i] + 1) {
            cout << "came inside: " << nums[i] << "\n";
            if (start == i) {
                result.push_back(to_string(nums[start]));
            } else {
                result.push_back(to_string(nums[start]) + "->" + to_string(nums[i]));
            }
            start = i + 1; 
        }
    }
    
    return result;
}

int main() {

    vector<int> v = {0,2,3,4,6,8,9};
    vector<string> res = summaryRanges(v);
    for(string s : res) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}