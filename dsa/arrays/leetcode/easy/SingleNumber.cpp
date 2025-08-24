
/**
 * LC: E: 136. Single Number
 * Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
 * Example 1:Input: nums = [2,2,1] Output: 1
 * Example 2:Input: nums = [4,1,2,1,2] Output: 4
 * Example 3: Input: nums = [1] Output: 1

 */
#include<iostream>
using namespace std;

int usingXOR(const vector<int> & arr) {
    int xor_result = 0;
    for (int num : arr) {
        xor_result ^= num;
    }
    return xor_result;
}

int singleNumberUsingMap(const vector<int>& arr) { 
    unordered_map<int,int> m;
    for(int num: arr) {
        m[num]++;
    }
    for(int num: arr) {
        if(m[num] == 1) {
            return num;
        }
    }
    return 0;
}

int main() {

    return 0;

}