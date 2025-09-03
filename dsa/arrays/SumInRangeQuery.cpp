#include<iostream>
using namespace std;

//Sum in range, O(N)
int sumInRangeLinear(vector<int> arr, int l, int r) {
        int res = 0;
        for (int i = l; i <= r; i++) {
            res += arr[i];
        }
        return res;
}

//sum in range, in O(1)
int sumInRange(vector<int> arr, int l, int r) {
    int n = arr.size();
    vector<int> prefix(n);
    prefix[0] = arr[0];
    for(int i=1;i<n;i++) {
        prefix[i] = prefix[i-1] + arr[i];
    }
    if(l == 0) {
        return prefix[r];
    } else {
        return prefix[r]-prefix[l-1];
    }
}

 /*
      Weighted prefix sum
      arr = [1,2,3,4,5,6]
     l=2, r=4 == 1*arr[2] + 2*arr[3] + 3*arr[4]
              == 1*3 + 2*4 + 3*5
              == 26

          
 programmatically compute the weighted sum:

    getWSum(2,4) = 1 * arr[2] + 2*arr[3] + 3 * arr[4];
                 = 1 * arr[l] + 2*arr[l+1] + ... + (r-l+1) * arr[r]
                 = ∑ from i=l to r of (i−l+1)⋅arr[i]
                 = ∑ from i=l to r of i⋅arr[i] − (l−1)⋅∑ from i=l to r of arr[i]

means
1. Build two prefix sum arrays:
   - preSum[i] = arr[0] + arr[1] + ... + arr[i]
   - preWSum[i] = 0⋅arr[0] + 1⋅arr[1] + ... + (i)⋅arr[i]

2. Then we can compute:
    getWSum(l, r) = (preWSum[r] − preWSum[l−1]) − (l−1)⋅(preSum[r] − preSum[l−1])

This reduces each query to O(1) time after O(n) preprocessing.
 */

// Build simple prefix sum array
vector<int> buildPrefixSumArr(const vector<int>& arr) {
    vector<int> prefix(arr.size());
    prefix[0] = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    return prefix;
}

// Build weighted prefix sum array
vector<int> buildWeightedPrefixSumArr(const vector<int>& arr) {
    vector<int> prefix(arr.size());
    prefix[0] = 0; // 0 * arr[0] = 0
    for (int i = 1; i < arr.size(); i++) {
        prefix[i] = prefix[i - 1] + (i * arr[i]);
    }
    return prefix;
}

// Get weighted sum between indices l and r
int getWeightedSum(const vector<int>& arr, int l, int r) {
    vector<int> prefixSumArr = buildPrefixSumArr(arr);
    vector<int> weightedPrefixSumArr = buildWeightedPrefixSumArr(arr);

    int weightedSum = weightedPrefixSumArr[r] - ((l > 0) ? weightedPrefixSumArr[l - 1] : 0);
    int prefixSum = prefixSumArr[r] - ((l > 0) ? prefixSumArr[l - 1] : 0);

    return weightedSum - (l - 1) * prefixSum;
}


int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int res = getWeightedSum(arr, 2, 4);
    cout << res << endl;  // Output: 26
    return 0;
}