/**
LC: E: 724. Find Pivot Index

 Given an array of integers nums, calculate the pivot index of this array.
 The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum
 of all the numbers strictly to the index's right.
 If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left.
 This also applies to the right edge of the array.
 Return the leftmost pivot index. If no such index exists, return -1.

 Example 1:

 Input: nums = [1,7,3,6,5,6]
 Output: 3
 Explanation:
 The pivot index is 3.
 Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
 Right sum = nums[4] + nums[5] = 5 + 6 = 11

 Example 2:

 Input: nums = [1,2,3]
 Output: -1
 Explanation:
 There is no index that satisfies the conditions in the problem statement.

 Example 3:

 Input: nums = [2,1,-1]
 Output: 0
 Explanation:
 The pivot index is 0.
 Left sum = 0 (no elements to the left of index 0)
 Right sum = nums[1] + nums[2] = 1 + -1 = 0



 Constraints:

 1 <= nums.length <= 104
 -1000 <= nums[i] <= 1000

 */

 #include<iostream>
 using namespace std;

 // --------------------------------------------------------------------
// O(N^2) — Naive Approach
// --------------------------------------------------------------------
int naivePivotIndex(const vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n; i++) {

        int leftSum = 0;
        for (int j = 0; j < i; j++) {
            leftSum += arr[j];
        }

        int rightSum = 0;
        for (int j = i + 1; j < n; j++) {
            rightSum += arr[j];
        }

        if (leftSum == rightSum) {
            return i;
        }
    }

    return -1;  
}


    /**
     *  build prefix and suffix arrays
     *  e.g for  [3, 4,  8, -9, 9,   7] at 8 we have equilibrium point
     *  preSum = [3, 7,  15, 6, 15, 22]
     *  sufSum = [22,19, 15, 7, 16,  7]
     *
     *  for all elements except corner ones check if
     *  preSum[i-1] == sufSum[i+1]
     *  e.g for index = 2 at 8, we have 7 on both sides

     */
    
// --------------------------------------------------------------------
// O(N) — Optimized Two-Pointer
// --------------------------------------------------------------------
int pivotIndex(const vector<int>& nums) {
    int n = nums.size();

    int rightSum = 0;
    for (int num : nums) {
        rightSum += num;
    }

    int leftSum = 0;

    for (int i = 0; i < n; i++) {
        rightSum -= nums[i];

        if (leftSum == rightSum) {
            return i;
        }

        leftSum += nums[i];
    }

    return -1;
}


int main() {
    vector<int> nums = {1, 7, 3, 6, 5, 6};

    // Using optimized function
    int result = pivotIndex(nums);

    cout << "Pivot Index: " << result << endl;

    // Testing naive approach
    int naiveResult = naivePivotIndex(nums);
    cout << "Pivot Index (Naive): " << naiveResult << endl;

    return 0;
}