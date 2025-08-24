/**
 * LC: 189 : M
 * Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
 *
 *
 * Example 1:
 *
 * Input: nums = [1,2,3,4,5,6,7], k = 3
 * Output: [5,6,7,1,2,3,4]
 * Explanation:
 * rotate 1 steps to the right: [7,1,2,3,4,5,6]
 * rotate 2 steps to the right: [6,7,1,2,3,4,5]
 * rotate 3 steps to the right: [5,6,7,1,2,3,4]
 *
 * Example 2:
 *
 * Input: nums = [-1,-100,3,99], k = 2
 * Output: [3,99,-1,-100]
 * Explanation:
 * rotate 1 steps to the right: [99,-1,-100,3]
 * rotate 2 steps to the right: [3,99,-1,-100]
 */
#include<iostream>
using namespace std;

void reverse(int left, int right, vector<int>& arr) {
    while(left<right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

void rotate(std::vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0) return; // prevent divide-by-zero

    k = k % n;          
    if (k < 0) k += n;  // handles negative rotation

    reverse(0, n - k - 1, nums);
    reverse(n - k, n - 1, nums);
    reverse(0, n - 1, nums);
}
