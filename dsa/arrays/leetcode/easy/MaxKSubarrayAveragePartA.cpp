#include <iostream>
#include <vector>
#include <climits> // for INT_MIN
using namespace std;

// Optimized sliding window approach
double slidingWindow(const vector<int>& arr, int k) {
    int windowSum = 0;
    int maxSum = 0;

    // Initial window sum
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }
    maxSum = windowSum;

    // Slide the window
    for (int i = k; i < arr.size(); i++) {
        windowSum += arr[i] - arr[i - k];
        maxSum = max(maxSum, windowSum);
    }
//This explicitly converts maxSum (an int) to a double before performing the division by k, 
  //so that the result is floating-point division, not integer division
    return static_cast<double>(maxSum) / k;
  //todo try this program in new machine
}

int main() {
    vector<int> arr = {5};
    int k = 1;

    double result = slidingWindow(arr, k);
    cout << fixed;
    cout.precision(5); // To match required precision
    cout << result << endl;

    return 0;
}
