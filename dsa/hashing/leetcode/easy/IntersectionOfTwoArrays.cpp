#include<iostream>
#include<unordered_set>
using namespace std;

//num1Size=m and num2Size=n
/*
 Time: O(n.log(n m.log(n)), Space: O(1)
*/
vector<int> approach1(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    unordered_set<int> res;
    for(int x: nums2) {
        if(binary_search(nums1.begin(), nums2.end(), x)) {
            res.insert(x);
        }
    }
    return vector<int>(res.begin(), res.end());
}

/*
 Time: O(m+n), Space: O(n)
 (Most efficient)
*/
vector<int> approach2(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> resultSet;
    for(int x: nums2) {
        if(set1.count(x)) { //s.count(item) returns 1 if found else 0
           resultSet.insert(x);
        }
    }
    return vector<int>(resultSet.begin(), resultSet.end());
}

/*
 Time:  O(n log n + m log m), Space: O(n)
*/
vector<int> approach3(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    unordered_set<int> resultSet;
    int i=0, j=0;
    
    while(i < nums1.size() && j< nums2.size()) {
        if(nums1[i] == nums2[j]) {
            resultSet.insert(nums1[i]);
            i++;
            j++;
        } else if(nums1[i] > nums2[j]) {
            j++;
        } else {
            i++;
        }
    }
    return vector<int>(resultSet.begin(), resultSet.end());
}

// Approach 4: Two Sets (Alternative)
// Time: O(n + m), Space: O(n + m)
vector<int> intersection4(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());
    vector<int> result;
    
    for (int num : set1) {
        if (set2.count(num)) {
            result.push_back(num);
        }
    }
    
    return result;
}



int main() {

    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    
    vector<int> result = approach3(nums1, nums2);
    
    for (int x: result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
