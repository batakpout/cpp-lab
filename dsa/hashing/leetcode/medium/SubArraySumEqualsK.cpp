
/**
 
    LC: Medium
    560. Subarray Sum Equals K
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2

Example 2:

Input: nums = [1,2,3], k = 3
Output: 2

 */
#include<iostream>
using namespace std;

//O(N^2)
int countSubarraysWithSumK(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> prefix(n);
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + arr[i];

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = (i == 0) ? prefix[j] : prefix[j] - prefix[i - 1];
            if (sum == k)
                ++count;
        }
    }
    return count;
}

/*
    sum(l..r) = prefix[r] - prefix[l-1]
    prefix[r] - prefix[l-1] = k
    ⇒ prefix[l-1] = prefix[r] - k

    If at some right-end r we know how many earlier prefix sums equal (prefix[r] – k), that’s exactly how many subarrays ending at r have sum k.

    nums = [1,2,3,4,5]
    prefix = [1,3,6,10,15]
    k = 5
    •	r = 2 (value 3)
    prefix[2] = 6
    We need a prefix[l-1] = 6 - 5 = 1.
    Is there an earlier prefix of 1? Yes, prefix[0] = 1.
    → subarray (l=1, r=2) → [2,3].
    •	r = 4 (value 5)
    prefix[4] = 15
    Need prefix[l-1] = 15 - 5 = 10.
    prefix[3] = 10.
    → subarray (l=4, r=4) → [5].

    That’s exactly what the map tracks:
    it stores counts of every prefix[x] we’ve seen (those are all potential l-1 positions).
    When we’re at r and have prefix[r], we look up prefix[r] - k to find how many valid l-1 indices exist.

*/

//TC: O(N) space: O(N)
int optimized(vector<int>arr, int k) {
    unordered_map<int,int>freq;
    freq[0] = 1;
    int prefix=0,count=0;
    for(int num: arr) {
        prefix += num;
        if(freq.count(prefix-k)) { // count check if this key exists
            count += freq[prefix-k];
        }
        ++freq[prefix];
    }
    return count;
}

int main() {
    vector<int> arr = { 1, -1, 1, -1, 1 };
    int res = optimized(arr, 0);
    cout << res << endl;
    return 0;
}
