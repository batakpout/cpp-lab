
/*
LC 1337; E The K Weakest Rows in a Matrix


You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.

A row i is weaker than a row j if one of the following is true:

    The number of soldiers in row i is less than the number of soldiers in row j.
    Both rows have the same number of soldiers and i < j.

Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.

Input: mat = 
[[1,1,0,0,0],
 [1,1,1,1,0],
 [1,0,0,0,0],
 [1,1,0,0,0],
 [1,1,1,1,1]], 
k = 3
Output: [2,0,3]
Explanation: 
The number of soldiers in each row is: 
- Row 0: 2 
- Row 1: 4 
- Row 2: 1 
- Row 3: 2 
- Row 4: 5 
The rows ordered from weakest to strongest are [2,0,3,1,4].
*/
#include<iostream>
using namespace std;

//complexity time: O(m·n + m .log m + k) == O(m.n + m.log(m))
vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    vector<pair<int,int>> strength;
    
    for (int i = 0; i < mat.size(); i++) {
        int left = 0, right = mat[i].size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mat[i][mid] == 1) {
                left = mid + 1;  // Look in right half
            } else {
                right = mid;     // Look in left half (including mid)
            }
        }
        strength.push_back({left, i});
    }

    /*
     step1 in O(m.n)
     for(int i=0;i<mat.size();i++) {
        int count=0;
        for(int j=0;j<mat[0].size();j++) {
            if(mat[i][j] == 1) count++; else break;  
        }
        strength.push_back({count, i}); 
     }
    */
   sort(strength.begin(), strength.end());

   vector<int>res;
   for(int i=0;i<k;i++) {
     res.push_back(strength[i].second); //strength[i] gets the i-th pair from vector
   }
   return res;
}


int countSoldiers(vector<int>& row) {
    int l = 0, r = row.size();
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (row[mid] == 1) l = mid + 1;
        else r = mid;
    }
    return l;
}

//bad complexity with priority queue
vector<int> kWeakestRows2(vector<vector<int>>& mat, int k) {
    // Max-heap: strongest among k weakest rows on top
    priority_queue<pair<int,int>> pq;  

    for (int i = 0; i < mat.size(); i++) {
        int soldiers = countSoldiers(mat[i]);

        if (pq.size() < k) {
            // First k elements - just add
            pq.push({soldiers, i});//For priority_queue<pair<int,int>>, the ordering is based on the first element of the pair by default.
        } else if (soldiers < pq.top().first) {
            // Current row is weaker than strongest in heap
            pq.pop();           // Remove strongest
            pq.push({soldiers, i}); // Add weaker one
        }
    }

    vector<int> res;
    while (!pq.empty()) {
        res.push_back(pq.top().second);
        pq.pop();
    }
    reverse(res.begin(), res.end()); // strongest to weakest -> weakest to strongest
    return res;
}


int main() {
   vector<vector<int>> matrix = {
       {1,1,0,0,0},
       {1,1,1,1,0},
       {1,0,0,0,0},
       {1,1,0,0,0},
       {1,1,1,1,1}
   };
   
   vector<int> res1 = kWeakestRows2(matrix, 3);
   for(int num: res1) {
    cout << num << " ";
   }
   cout << endl;
   return 0;

}