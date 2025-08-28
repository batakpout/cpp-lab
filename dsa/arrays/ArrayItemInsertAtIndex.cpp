#include<iostream>
#include<sstream>
using namespace std;

vector<int> method1(const vector<int>& arr, int idx, int item) {
    vector<int> res(arr.size() + 1);

    for (int i = 0; i < idx; i++) {
        res[i] = arr[i];
    }

    res[idx] = item;

    for (int i = idx; i < arr.size(); i++) {
        res[i + 1] = arr[i];
    }

    return res;
}

void method2(vector<int>& arr, int idx, int item) {

    arr.push_back(0); //const vector means we can't modify it inside the f, calling arr.push_back(0), which modifies the vector → compilation error.

    
    for (int i = arr.size() - 1; i>idx; i--) {
        arr[i] = arr[i-1];
    }

    arr[idx] = item;

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

     cout << "enter index to insert item:";
     int idx;cin>>idx;
     cout << "enter item to insert at index " << idx << ": ";
     int item;cin>>item;
     //vector<int>v1 = method1(v, idx, item);
     method2(v, idx, item);

    cout << endl;
    cout << "result: \n";
    for(int i: v) {
        cout << i << " ";
    }
    cout << endl;

}