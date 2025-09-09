/**
LC 1464 Easy Maximum Product of Two Elements in an Array

Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).

 

Example 1:

Input: nums = [3,4,5,2]
Output: 12 
Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12. 

Example 2:

Input: nums = [1,5,4,5]
Output: 16
Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get the maximum value of (5-1)*(5-1) = 16.

Example 3:

Input: nums = [3,7]
Output: 12

 

Constraints:

    2 <= nums.length <= 500
    1 <= nums[i] <= 10^3


 */
#include<iostream>
using namespace std;

/*
 assume k items in vector, so insert complexity O(k. Log(N)) and top() is O(1), pop is O(Log(n))

 so total O(k.Log(n)) + O(log(n)) ==> O(k.log(n))
 if we sort it first instead of pq, then O(N. Log N)
*/
int maxProduct(vector<int>& nums) {
        priority_queue<int> p;
        for(int n: nums) {
            p.push(n);
        }
        int f = p.top();
        p.pop();
        int s = p.top();
        return (f-1) * (s-1);
}
