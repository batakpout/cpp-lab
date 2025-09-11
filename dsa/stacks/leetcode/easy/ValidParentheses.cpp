/*
    LC: 20; E Valid Parentheses
    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.

 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false

*/
#include<iostream>
using namespace std;

bool isMatching(char c1, char c2) {
    return (c1 == '{' && c2 == '}') ||
           (c1 == '[' && c2 == ']') ||
           (c1 == '(' && c2 == ')');
}

/*
 Inside loop all ops are O(1)
 so TC: O(N) and SC: O(N)
*/

bool isBalanced(string str) {
    stack<char> stk;
    for(char ch: str) {
        if(ch == '{' || ch == '[' || ch == '(') {
            stk.push(ch);
        } else {
         if(stk.empty()) return false;
        else if(!isMatching(stk.top(), ch)) return false;
        else stk.pop();
      }
    }
    return stk.empty();
}

int main() {
    string input;
    getline(cin, input);
    bool res = isBalanced(input);
    cout << (res ? "true" : "false") << endl;
    return 0;
}
