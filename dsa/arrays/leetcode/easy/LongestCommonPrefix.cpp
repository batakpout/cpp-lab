/*
    LC 14 Easy Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

*/
#include<iostream>
using namespace std;

 /*
 For one string, cost ≈ m + (m-1) + (m-2) + ... + 1 → O(m²) [while loop].

For n strings → O(n · m²) in the absolute worst case.
 */
 string naive(vector<string>& strs) {
     string prefix = strs[0];
     for(int i=0;i<strs.size();i++) {
        while(strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.size() - 1);
            if(prefix=="") return "";
        }
     }   
     return prefix;
}

/*
	•	Sorting ensures strings with the smallest and largest lexicographic differences end up at strs[0] and strs.back().
	•	The common prefix of the entire array will always be the prefix of these two extreme strings.
	•	Time complexity → O(N log N + M)
	•	N log N → sorting
	•	M → comparing first and last strings
	•	Space complexity → O(1).
*/

//O(n.Log(n) + m)
string optimized(vector<string> &strs) {
    if(strs.empty()) return "";

    // Sort the strings lexicographically
    sort(strs.begin(), strs.end());

    string s1 = strs.front();
    string s2 = strs.back();
    int i = 0;

    while(i < s1.size() && i < s2.size() && s1[i] == s2[i]) {
        i++;
    }
    return s1.substr(0, i);
}


int main() {
    // Example test cases
    vector<string> strs1 = {"flower", "flow", "flight"};
    vector<string> strs2 = {"dog", "racecar", "car"};
    vector<string> strs3 = {"interview", "internet", "internal", "interval"};

    cout << "Longest common prefix (Test 1): " << optimized(strs1) << endl;
    cout << "Longest common prefix (Test 2): " << optimized(strs2) << endl;
    cout << "Longest common prefix (Test 3): " << optimized(strs3) << endl;

    return 0;
}