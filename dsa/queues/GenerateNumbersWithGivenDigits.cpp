#include<iostream>
using namespace std;


//BFS logic
/**
      (Start)
         |
      ---------------
      |              |
      5              6
      |              |
    ------        ------
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

vector<string> generateBinaryNumbers(int n) {   
     queue<string> q;
     q.push("1");
     vector<string> result;
     vector<string> arr = {"0", "1"};


     for(int count=0;count<n;count++) {
        string curr = q.front();
        cout << "curr: " << curr << endl;
        result.push_back(curr);
        q.pop();

        for(string s: arr) {
            q.push(curr + s);
        }
     }
    return result;
}
int main() {

    int n;cin>>n;
    vector<int> arr = {5,6};
    printFirstN(n, arr);

    vector<string> res = generateBinaryNumbers(5);
    for(string s: res) {
      cout << s << " ";
    }
    cout << endl;
    return 0;
}