#include <iostream>
#include <vector>
using namespace std;

class LargestElement {
public:
    static int largestElement(const vector<int>& arr) {
        int max = arr[0];
        for (int j : arr) {
            if (j > max) {
                max = j;
            }
        }
        return max;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    /**
     	A static member function in C++ or java	belongs to the class, not any object.
        we don't need to create an object of the class to call
     */
    int largest = LargestElement::largestElement(arr);
    cout << "Largest element: " << largest << endl;

    return 0;
}