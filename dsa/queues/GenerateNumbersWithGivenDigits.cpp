#include<iostream>
using namespace std;


//BFS logic
/**
      (Start)
         |
      -------
      |     |
      5     6
      |     |
    ------ ------
   |      |      |      |
   55     56     65     66
   |      |      |      |
 ------ ------ ------ ------
|      |      |      |      |      |      |      |
555    556    565    566    655    656    665    666
 */
//O(N) ignoring concat complexity as assuming it is O(1)
void printFirstN(int n, vector<int>arr) {

     queue<string> q;
     for(int num: arr) {
        q.push(to_string(num));
     }
     for(int count=0;count<n;count++) {
        string curr = q.front();
        cout << curr << " ";
        q.pop();

        for(int num: arr) {
            q.push(curr + to_string(num));
        }
     }
     cout << endl;
}
int main() {

    int n;cin>>n;
    vector<int> arr = {1,2,3,4};
    printFirstN(n, arr);
    return 0;
}