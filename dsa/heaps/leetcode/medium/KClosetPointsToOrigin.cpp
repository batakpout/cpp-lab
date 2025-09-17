#include<iostream>
using namespace std;
/**
  push is O(k.log(k)), then O((n-k). log(k)) second loop, last O(log(k)) for k pops
  total: O(k. log(k)) better than O(n. log(k))
 */
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<pair<long long,int>> max_heap;
    
    for(int i=0;i<k;i++) {
        long long d = 1LL * points[i][0] * points[i][0] + 
                      1LL * points[i][1] * points[i][1];
                max_heap.push({d, i});

//1LL* prevents integer overflow by converting to long long
//Uses distance-squared (avoids expensive sqrt)

    }

    for(int i=k;i<points.size();i++) {
         long long d = 1LL * points[i][0] * points[i][0] + 
                      1LL * points[i][1] * points[i][1];
          if(d < max_heap.top().first) {
            max_heap.pop();
            max_heap.push({d,i});
          }      
    }
    vector<vector<int>>ans;
    ans.reserve(k);
    while(!max_heap.empty()) {
        ans.push_back(points[max_heap.top().second]);
        max_heap.pop();
    }
    return ans;
}

int main() {
    
    vector<vector<int>> points = { {3,3}, {5,-1}, {-2,4} };
    int k = 2;

    vector<vector<int>> result = kClosest(points, k);

    cout << "The " << k << " closest points are:\n";
    for (const auto& p : result) {
        cout << "[" << p[0] << "," << p[1] << "]\n";
    }

    return 0;
}