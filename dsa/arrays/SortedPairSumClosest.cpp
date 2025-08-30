/*
 Given a sorted array and a number x, find a pair in array whose sum is closest to x.

Input Format

In the function an integer vector and number x is passed.

Output Format

Return a pair of integers.
Sample Input

    {10, 22, 28, 29, 30, 40}, x = 54

Sample Output

    22 and 30
 */

#include <iostream>
#include <vector>
#include <cmath> //for abs
#include <climits> //  for INT_MAX
using namespace std;

vector<int> findSortedPair(const vector<int>& arr, int k) {
    int left = 0;
    int right = arr.size() - 1;
    int diff = INT_MAX;
    int leftIndex = -1, rightIndex = -1;

    while (left < right) {
        int cs = arr[left] + arr[right];
        int currDiff = abs(cs - k);

        if (currDiff < diff) {
            diff = currDiff;
            leftIndex = left;
            rightIndex = right;
        }

        if (cs > k) {
            right--;
        } else {
            left++;
        }
    }

    return {arr[leftIndex], arr[rightIndex]};
}

int main() {
    vector<int> arr = {10, 22, 28, 29, 30, 40};
    int k = 54;

    vector<int> res = findSortedPair(arr, k);

    for (int num : res) {
        cout << num << ", ";
    }

    return 0;
}