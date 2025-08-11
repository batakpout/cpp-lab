/**
 * in a substring starting from 0 till n
 If ANY character has frequency = 1: Return the first occurring character among those with frequency 1
If ALL characters have frequency > 1: Return '0'

Input: "abcabc"
Index 0: "a" → {a:1} → 'a'
Index 1: "ab" → {a:1, b:1} → 'a'
Index 2: "abc" → {a:1, b:1, c:1} → 'a'
Index 3: "abca" → {a:2, b:1, c:1} → 'b'
Index 4: "abcab" → {a:2, b:2, c:1} → 'c'
Index 5: "abcabc" → {a:2, b:2, c:2} → '0'
Output: "aaabc0"
 */

#include<iostream>
using namespace std;

//Brute Force - O(n²) time, O(1) space
void naive(string s) {
    for(int i=0;i<s.size();i++) {
        unordered_map<char, int> freq;
        for(int j=0;j<=i;j++) {
            freq[s[j]]++;
        }

        char firstNonRepeating = '0';
        for(int j=0;j<=i;j++) {
            if(freq[s[j]] == 1) {
                firstNonRepeating =  s[j];
                break;
            }
        }
        cout << firstNonRepeating;
    }
    cout << endl;
}


// Alternative queue implementation with cleaner logic
vector<char> firstNonRepeatingQueueV2(vector<char>& chars) {
    vector<char> result;
    queue<char> queue;  // Store (character, index) pairs
    unordered_map<char, int> freq;

    for (char ch : chars) {
        freq[ch]++;

        if(freq[ch] == 1) {
            queue.push(ch);
        }

        while(!queue.empty() && freq[queue.front()] > 1) {
            queue.pop();
        }

        if(!queue.empty()) {
            result.push_back(queue.front());
        } else {
            result.push_back('0');
        }
        
    }
    return result;

}

int main() {

    string str;
    cout << "enter a string\n";
    getline(cin, str);

    naive(str);
    vector<char> v(str.begin(), str.end());
    vector<char> res= firstNonRepeatingQueueV2(v);
    for(char ch: res) {
        cout << ch;
    }
    cout << endl;
}