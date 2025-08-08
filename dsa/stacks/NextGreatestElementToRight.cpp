#include <iostream>
#include <stack>
#include <vector>
/*

Next Greater Element

Given an array, return the Next Greater Element for every element. The Next greater Element for an element x is the
 first greater element on the right side of x in the array. Elements for which no greater element exist,
 consider the next greater element as -1.

Input:
{2, 7, 3, 5, 4, 6, 8, 1}

Output:
{7, 8, 5, 6, 6, 8, -1, -1}

Return an integer vector containing the next greater element for each element
 */

using namespace std;
// Naive O(N^2) approach
vector<int> naive(const vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n);
    int j;
    for (int i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                res[i] = arr[j];
                break;
            }
        }
        if (j == n) {
            res[i] = -1;
        }
    }
    return res;
}

// Optimized O(N) approach using stack
vector<int> optimized(const vector<int>& arr) {
    stack<int> stk;
    vector<int> res(arr.size());

    for(int i=arr.size()-1;i>=0;i--) {

        while(!stk.empty() && arr[i] > stk.top()) { //.top
            stk.pop();
        }
        if(stk.empty()) {
            res[i] = -1;
        } else {
            res[i] = stk.top();
        }
        stk.push(arr[i]);
    }
    return res;
}


int main() {

  vector<int> arr = {2, 7, 3, 5, 4, 6, 8, 1};

    vector<int> res1 = naive(arr);
    vector<int> res2 = optimized(arr);

    for (int num : res1) {
        cout << num << " ";
    }
    cout << endl;
    for (int num : res2) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}