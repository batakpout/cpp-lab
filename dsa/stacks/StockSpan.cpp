#include <iostream>
#include <stack>
#include <vector>
/*
 The stock span problem is a financial problem where we have a series of daily price quotes for a stock and we need to
  calculate the span of stock price for all days. The span arr[i] of the stocks price on a given day i is defined as
   the maximum number of consecutive days just before the given day, for which the price of the stock on the given
   day is less than or equal to its price on the current day.

Examples:

Input: arr[] = [100, 80, 60, 70, 60, 75, 85]
Output: [1, 1, 1, 2, 1, 4, 6]
 */
using namespace std;

// Naive O(N^2) approach
void naive(const vector<int> & arr) {
    int n = arr.size();
    for(int i=0;i<n;i++) {
        int span=1;
        for(int j=i-1;j>=0 && arr[j] <= arr[i];j--) {
            span++;
        }
        cout << span << " ";
    }
    cout << endl;
}

// Optimized O(N) approach using stack
vector<int> optimized(const vector<int>& arr) {
    stack<int> stk;
    vector<int> res(arr.size());
    res[0] = 1;
    stk.push(0);
    for(int i=1;i<arr.size();i++) {
        while(!stk.empty() && arr[i] >= arr[stk.top()]) { //.top
            stk.pop();
        }
        if(stk.empty()) {
            res[i] = i+1;
        } else {
            res[i] = i-stk.top();
        }
        stk.push(i);
    }
    return res;
}
int main() {

    vector<int> arr = {100, 80, 60, 70, 60, 75, 85};
    naive(arr);
    cout << endl;
    vector<int> res = optimized(arr);
    for (int val : res) {
        cout << val << " ";
    }
    cout << endl;

    return 0;

}
