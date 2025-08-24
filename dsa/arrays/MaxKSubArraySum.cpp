#include <iostream>
#include <vector>
#include <climits> // for INT_MIN
using namespace std;

// Naive approach: O(n * k)
int naive(const vector<int>& arr, int k) {
    int maxSum = INT_MIN;
    int n = arr.size();
    for (int i = 0; i <= n - k; i++) {
        int currSum = 0;
        for (int j = i; j < i + k; j++) {
            currSum += arr[j];
        }
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

// Sliding window: O(n)
int slidingWindow(const vector<int>& arr, int k) {
    if (arr.size() < k) return INT_MIN; // Edge case

    int windowSum = 0;
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }

    int maxSum = windowSum;

    for (int i = k; i < arr.size(); i++) {
        windowSum += arr[i] - arr[i - k];
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}

int main() {
    vector<int> arr = {5, -10, 6, 90, 3};
    int k = 2;

    int s1 = naive(arr, k);
    int s2 = slidingWindow(arr, k);

    cout << "Naive: " << s1 << endl;
    cout << "Sliding Window: " << s2 << endl;

    return 0;
}
