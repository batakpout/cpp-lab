

#include <iostream>
#include <vector>
#include <climits> // for INT_MIN
using namespace std;

class MaxSubarraySum {
public:
    // O(N^2) approach using prefix sum
    static int maxSubArraySumPrefixArray(const vector<int> & arr) {
        int n = arr.size();
        vector<int> prefixSum(n);
        prefixSum[0] = arr[0];
        for(int i=0;i<n;i++) {
            prefixSum[i] = prefixSum[i-1] + arr[i];
        }
        int maxSum = INT_MIN;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                int currSum = (i==0) ? prefixSum[i] : prefixSum[j] - prefixSum[i-1];
                maxSum = max(maxSum, currSum);
            }
        }
        return maxSum;
    }

     // O(N) approach using Kadane's Algorithm
    static int kadanesAlgorithm(const vector<int>& nums) {
        int maxSum = INT_MIN;
        int n = nums.size();
        int cs = 0;
        for(int num: nums) {
            cs += num;
            maxSum = max(maxSum, cs);
            if(cs<0) {
                cs=0;
            }
        }
        return maxSum;
    }
};

int main() {
     vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

     cout << "Maximum Subarray Sum (Prefix Array Method): "
         << MaxSubarraySum::maxSubArraySumPrefixArray(arr) << endl;

     cout << "Maximum Subarray Sum (Kadane's Algorithm): "
         << MaxSubarraySum::kadanesAlgorithm(arr) << endl;

    return 0;
}