/**
 * 283. Move Zeroes
 
 * Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 * Note that you must do this in-place without making a copy of the array.
 
 * Example 1:
 * Input: nums = [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * Example 2:
 * Input: nums = [0]
 * Output: [0]

 */

 #include <iostream>
using namespace std;

// O(N*N) brute force approach
void bruteForce(int nums[], int n) {
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] != 0) {
                    swap(nums[i], nums[j]);// swap(a, b) exchanges the values in O(1) time.
                }
            }
        }
    }
}

// O(N) optimal approach
void moveZeroes(int nums[], int n) {
    int j = 0; // index to place non-zero elements
    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}

int main() {
    int arr[] = {0, 1, 0, 3, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    moveZeroes(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}