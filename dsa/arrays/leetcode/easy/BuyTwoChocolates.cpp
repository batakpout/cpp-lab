/**
 * LC: E: 2706. Buy Two Chocolates
 * You are given an integer array prices representing the prices of various chocolates in a store. You are also given a single integer money,
 * which represents your initial amount of money.
 * You must buy exactly two chocolates in such a way that you still have some non-negative leftover money.
 * You would like to minimize the sum of the prices of the two chocolates you buy.
 * Return the amount of money you will have leftover after buying the two chocolates. If there is no way for you to buy two chocolates without ending up in debt,
 * return money. Note that the leftover must be non-negative.
 * <p>
 * Example 1: Input: prices = [1,2,2], money = 3 Output: 0
 * Explanation: Purchase the chocolates priced at 1 and 2 units respectively. You will have 3 - 3 = 0 units of money afterwards. Thus, we return 0.
 * Example 2: bInput: prices = [3,2,3], money = 3 Output: 3
 * Explanation: You cannot buy 2 chocolates without going in debt, so we return 3.
 * its greedy
 */

#include<iostream>
#include<sstream>
using namespace std;

    // TC: O(n log n)
int usingSorting(const vector<int> & arr, int money) {
    sort(arr.begin(), arr.end());
    int sum = arr[0] + arr[1];
    return (sum > money) ? money : (money - sum);
}
 // TC: O(n)
int buyChoco(const vector<int>& prices, int money) { 
     int smallest = INT_MAX, secondSmallest = INT_MAX;
        for (int price : prices) {
            if (price < smallest) {
                secondSmallest = smallest;
                smallest = price;
            } else {
                secondSmallest = min(secondSmallest, price);
            }
        }
        int sum = smallest + secondSmallest;
        return (sum > money) ? money : (money - sum);
}

int main() {
    string line;
    vector<int> prices;
    int money;

    cout << "Enter prices (space-separated): ";
    getline(cin, line);
    istringstream iss(line);
    int num;
    while (iss >> num) {
        prices.push_back(num);
    }

    cout << "Enter money: ";
    cin >> money;

    int res1 = buyChoco(prices, money);

    cout << "res1: " << res1 << endl;

    return 0;
}
