
    #include<iostream>
    #include<unordered_set>
    using namespace std;
    /**
     * TC: O(n²), for using two nested loops
     * AS: O(1)
     */
    vector<int> usingNestedLoop(const vector<int>& arr, int target) {
        for(int i=0;i<arr.size();i++) {
            for(int j=i+1;j<arr.size();j++) {
                if(arr[i] + arr[j] == target) {
                    return {i,j};
                }
            }
        }
        return {-1,-1};
    }
    
    bool binarySearch(const vector<int>& arr, int low, int high, int target) {
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(arr[mid] == target) return true;
            else if(arr[mid] > target) high = mid-1;
            else low = mid + 1; 
        }
        return false;
    }
    /**
     * TC: sort-> O(n log n), binary search -> O(Log N), arr traverse -> O(n)
     * total: O(N log N) + O(N log N)
     * AS: O(1)
     */
    bool usingBinarySearch(vector<int> arr, int target) {
        sort(arr.begin(), arr.end());
        for(int i=0;i<arr.size();i++) {
            int complement = target - arr[i];
            if(binarySearch(arr, i+1, arr.size()-1, complement)) {
                return true;
            }
        }
        return false;
    }
    /**
     * TC: sort -> O(N Log N), no traverse complexity because we don't traverse the whole array
     * AS: O(1)
     * Best for sorted arrays.
     */
    bool usingTwoPointers(std::vector<int> arr, int target) {
        sort(arr.begin(), arr.end());
        int left = 0;
        int right = arr.size()-1;
        int sum;
        while(left<right) {
            int sum = arr[left] + arr[right];
            if(sum == target) {
                return true;
            }
            if(sum>target) {
                right--;
            } else {
                left++;
            }
        }
        return false;
    }

     /**
     * TC: O(n)
     * AS: O(n)
     */
    vector<int> usingMap(const vector<int>& arr, int target) {
        unordered_map<int,int> map;
        for(int i=0;i<arr.size();i++) {
            int complement = target-arr[i];
            if(map.find(complement) != map.end()) {
                return {map[complement], i};
            } else {
                map[arr[i]] = i;
            }
        }
        return {-1,-1};
    }

    bool usingHashSet(vector<int>& arr, int target) {
        unordered_set<int> s;
        for(int i=0;i<arr.size();i++) {
            if(s.find(target - arr[i]) != s.end()) {
                return true;
            } else {
                s.insert(arr[i]);
            }
        }
    }

int main() {
    return 0;
}
