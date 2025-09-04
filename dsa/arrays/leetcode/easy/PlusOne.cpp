#include<iostream>
using namespace std;
/*
LC 66; Easy Plus One


You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

 

Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].

Example 3:

Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].

*/
vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    vector<int> res(n);
    res[n-1] = (digits[n-1] + 1)%10;
    int carry=((digits[n-1] + 1))/10;
    for(int i=n-2;i>=0;i--) {
        int sum = carry + digits[i];
        res[i] = sum%10;
        carry = sum/10;
    }
    if(carry>0) {
        vector<int> res2(n+1);
        res2[0] = carry;
        for(int i=0;i<n;i++) {
            res[i+1] = res[i];
        }
        return res2;
    } else {
        return res;
    }     
}

vector<int> simpleSolution(vector<int> & digits) {
    int n = digits.size();
    for(int i = n-1;i>=0;i--) {
        if(digits[i]!=9) {
            digits[i]++;
            break;
        } else {
            digits[i] = 0;
        }
    }
    if(digits[0] == 0) {
        digits.insert(digits.begin(), 1);
    }
    return digits;
}

int main() {

    vector<int> arr = {9};
    vector<int> res = plusOne(arr);
    for(int num: res) {
        cout << num;
    }
    cout << endl;
    return 0;
}