/*
LC 217 Easy Contains Duplicate
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
Example 1:

Input: nums = [1,2,3,1]

Output: true

Explanation:

The element 1 occurs at the indices 0 and 3.

Example 2:

Input: nums = [1,2,3,4]

Output: false

Explanation:

All elements are distinct.

*/
#include<iostream>
#include<unordered_set>
using namespace std;

bool containsDuplicates(vector<int>& nums) {
    unordered_set<int> seen;
    for (int num : nums) {
        if (seen.find(num) != seen.end()) {
            return true; 
        }
        seen.insert(num);
    }
    return false; 
}

bool containsDuplicates(vector<int>& nums) {

    sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) return true;
        }
        return false;
}
/**
 
/*
Approach            Time       Space    LeetCode beats
--------------------------------------------------------
unordered_set       O(n)       O(n)     ~30-40% ✅
Sorting + Scan      O(n log n) O(1)     ~95%+ 🚀

unordered_set uses hashing, which internally:
	•	Computes a hash for every number.
	•	Handles collisions using linked lists or buckets.
	•	This causes extra memory allocations and makes it slower for small inputs.

Sorting is highly optimized in C++ (std::sort uses introsort — a hybrid of quicksort, heapsort, and insertion sort).
	•	No hashing overhead.
	•	Better CPU cache locality.
 */


int main() {
    vector<int> nums1 = {1, 2, 3, 4, 5};         // No duplicates
    vector<int> nums2 = {1, 2, 3, 2, 5};         // Duplicate '2'
    vector<int> nums3 = {10, 20, 30, 40, 10};    // Duplicate '10'

    cout << "Test 1: " << (containsDuplicates(nums1) ? "Yes" : "No") << endl;
    cout << "Test 2: " << (containsDuplicates(nums2) ? "Yes" : "No") << endl;
    cout << "Test 3: " << (containsDuplicates(nums3) ? "Yes" : "No") << endl;

    return 0;
}