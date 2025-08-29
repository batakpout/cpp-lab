#include <iostream>
#include <vector>
using namespace std;

class PrintPairs {
public:
    /*
       Formula: n * (n - 1) / 2 pairs
    */
    static void printPairs(const vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                cout << arr[i] << ", " << arr[j] << endl;
            }
            cout << endl;
        }
    }
};

int main() {
    vector<int> arr = {10, 20, 30, 40, 50, 60};

    PrintPairs::printPairs(arr);

    return 0;
}