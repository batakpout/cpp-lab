#include<iostream>
#include<vector>
#include <stdexcept> // for runtime_error
using namespace std;

template<typename T>
class StackList {
    private:
        vector<T> arr;
    public:
        void push(const T & data) { //pass by reference, & then it must be const also
       // data = 10;
            arr.push_back(data);
        }

        bool empty() const {
            return arr.empty();
        }

        void pop() {
            if(!empty()) {
                arr.pop_back();
            } else {
                throw runtime_error("empty stack");
            }
        }
 /**
  const here means that this member function does not modify the state of the object (its member variables)

  */
        int top() const {
            if(!empty()) {
                return arr.back();
            } else {
                throw runtime_error("empty stack");
            }
        } 
};

int main() {

     StackList<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(5);
    s.push(10);

    try {
        while (!s.empty()) {
            cout << s.top() << endl;
            s.pop();
        }

        // This will throw because stack is empty
        cout << s.top() << endl;

/*
 & --> catch by reference
 Avoid copying — exception objects can be large, and copying them is unnecessary overhead.
*/
    } catch (const runtime_error& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    cout << "Program continues normally here..." << endl;

    return 0;
}