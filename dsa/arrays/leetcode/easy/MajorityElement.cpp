#include<iostream>
using namespace std;

//time: O(n) + O(n), space:o(n) but this is slow 
int majorityElement(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int & num: nums) {
            freq[num]++;
        }
        int size = nums.size()/2;
        for(auto& p: freq) {
            if(p.second > size) {
                return p.first;
            }
        }
        return -1;
}
/*
 Boyer-Moore Majority Vote Algorithm:
    Example: Rally Line
Supporters: [Trump, Trump, Biden, Biden, Biden, Trump, Trump]
Let's see what happens:
Step-by-step cancellation:

Start: candidate=Trump, count=1
[Trump] Biden, Biden, Biden, Trump, Trump

Next Trump: count=2 (same candidate)
[Trump, Trump] Biden, Biden, Biden, Trump, Trump

Biden appears: count=1 (different → cancel one Trump)
[Trump] Biden, Biden, Trump, Trump

Another Biden: count=0 (cancel the last Trump)
[] Biden, Biden, Trump, Trump
Switch candidate to Biden, count=1

Another Biden: count=2 (same as current candidate)
[Biden, Biden] Trump, Trump

Trump appears: count=1 (different → cancel one Biden)
[Biden] Trump

Another Trump: count=0 (cancel the last Biden)
[]
Switch candidate to Trump, count=1


Result: Trump survives as the candidate
*/

int boyerMoore(vector<int>v) {
    int candidate=v[0];
    int count=1;
    for(int i=1;i<v.size();i++) {
        if(v[i] == candidate) {
            count++;
        } else {
            count--;
            if(count == 0) {
                candidate=v[i];
                count = 1;
            }
        }
    }
    return candidate;
}

int main() {
    vector<int> v = {3,2,3};
    int res1 = majorityElement(v);
    int res2 = boyerMoore(v);
    cout << res1 << endl;
    cout << res2 << endl;
    return 0;
}