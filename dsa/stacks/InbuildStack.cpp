#include <iostream>
#include <stack>
#include <string>
using namespace std;

/* LIFO
 underflow happens when peek or pop called on empty stack
 overflow happens when push called on full stack. [hardly happens because of dynamic sized collection under the hood or linked list]
 Some real world applications:
 1. Function calls
 2. balanced parenthesis by compilers
 3. Reversing items
 4. Infix to Postfix/Prefix
 5. Evaluation of Postfix/Prefix
 6. Stock span problem and its variants
 7. undo/redo or forward/backward in editor and browser.
 */
int main() {
    stack<string> stk;

    stk.push("Can't hurt me");
    stk.push("Atomic habits");
    stk.push("Ikigai");

    while (!stk.empty()) {
        cout << stk.top() << endl; // Peek
        stk.pop(); // Remove top element
    }

    return 0;
}