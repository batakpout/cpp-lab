#include <iostream>
#include <vector>
using namespace std;
 //O(N^365IO ) cubic complexity
    /*
       n*(n+1) / 2 pairs
     */
class SubArrayPrinter {
public:
    static void printSubArrays(const vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                for (int k = i; k <= j; k++) {
                    cout << arr[k] << " ";
                }
                cout << endl;
            }
        }
    }
};

int main() {
     vector<int> arr = {1, 2, 3};

     SubArrayPrinter::printSubArrays(arr);

    return 0;
}