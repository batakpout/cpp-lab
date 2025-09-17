#include<iostream>
#include<sstream>
using namespace std;

int lowerBound(vector<int> arr, int key) {
    int low = 0;
    int high = arr.size() - 1;
    int ans;
    while(low <= high) {
        int mid = low + (high - low) /2;
        if(arr[mid] == key) {
            ans=mid;
            high=mid-1;
        } else {
            high=mid-1;
        }
    }
    return ans;
}

int upperBound(vector<int> arr, int key) {
    int low = 0;
    int high = arr.size() - 1;
    int ans;
    while(low <= high) {
        int mid = low + (high - low) /2;
        if(arr[mid] == key) {
            ans=mid;
            low=mid+1;
        } else {
            low=mid+1;
        }
    }
    return ans;
}

int main() {
    cout << "enter sorted array:\n";
    vector<int> arr;
    string input;
    getline(cin, input);

    int num;
    stringstream st(input);
    while(st >> num) {
        arr.push_back(num);
    }

    cout << "enter key:";
    int k;cin>>k;

    cout << upperBound(arr, k) - lowerBound(arr,k) + 1 << endl;
    cout << upper_bound(arr.begin(), arr.end(), k) - lower_bound(arr.begin(), arr.end(), k) << endl;
    cout << endl;
}
