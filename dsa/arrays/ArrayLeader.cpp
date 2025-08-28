/*
Array Leaders

You are given an array arr of positive integers. Your task is to find all the leaders in the array. An element is
considered a leader if it is greater than or equal to all elements to its right. The rightmost element is always a leader.

Examples:

Input: arr = [16, 17, 4, 3, 5, 2]
Output: [17, 5, 2]
Explanation: Note that there is nothing greater on the right side of 17, 5 and, 2.

Input: arr = [10, 4, 2, 4, 1]
Output: [10, 4, 4, 1]
Explanation: Note that both of the 4s are in output, as to be a leader an equal element is also allowed on the right. side

Input: arr = [5, 10, 20, 40]
Output: [40]
Explanation: When an array is sorted in increasing order, only the rightmost element is leader.

Input: arr = [30, 10, 10, 5]
Output: [30, 10, 10, 5]
Explanation: When an array is sorted in non-increasing order, all elements are leaders.
 */
#include<iostream>
#include<sstream>
using namespace std;

vector<int> leader(vector<int> arr) {
    vector<int>res;
    int n = arr.size();
    int maxItem = arr[n-1];
    res.push_back(maxItem);
    for(int i = n-2;i>=0;i--) {
        if(arr[i] >= maxItem) {
            maxItem = arr[i];
            res.push_back(maxItem);
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {

     cout << "enter arr as line sep. by space:\n";
     string line;
     getline(cin, line);
     istringstream sst(line);
     int num;
     vector<int> v;
     while(sst >> num) {
        v.push_back(num);
     }

     vector<int>v1 = leader(v);

    cout << endl;
    cout << "result: \n";
    for(int i: v1) {
        cout << i << " ";
    }
    cout << endl;

}