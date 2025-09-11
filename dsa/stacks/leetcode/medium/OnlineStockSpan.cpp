/**
  LC 901 M Online Stock Span
  Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.

    For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
    Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.

Implement the StockSpanner class:

    StockSpanner() Initializes the object of the class.
    int next(int price) Returns the span of the stock's price given that today's price is price.

 

Example 1:

Input
["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
[[], [100], [80], [60], [70], [60], [75], [85]]
Output
[null, 1, 1, 1, 2, 1, 4, 6]

Explanation
StockSpanner stockSpanner = new StockSpanner();
stockSpanner.next(100); // return 1
stockSpanner.next(80);  // return 1
stockSpanner.next(60);  // return 1
stockSpanner.next(70);  // return 2
stockSpanner.next(60);  // return 1
stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
stockSpanner.next(85);  // return 6

 

Constraints:

    1 <= price <= 105
    At most 104 calls will be made to next.


 */

 #include<iostream>
 using namespace std;

 //variant-1 when input is vector
 // Naive O(N^2) approach
void naive(const vector<int> & arr) {
    int n = arr.size();
    for(int i=0;i<n;i++) {
        int span=1;
        for(int j=i-1;j>=0 && arr[j] <= arr[i];j--) {
            span++;
        }
        cout << span << " ";
    }
    cout << endl;
}

// Optimized O(N) approach using stack
vector<int> optimized(const vector<int>& arr) {
    stack<int> stk; //stores arr indicies/indexes and will store max items only when any new max item comes in iterations of arr
    vector<int> res(arr.size());
    res[0] = 1;
    stk.push(0);
    for(int i=1;i<arr.size();i++) {
        while(!stk.empty() && arr[i] >= arr[stk.top()]) { //.top
            stk.pop();
        }
        if(stk.empty()) {
            res[i] = i+1;
        } else {
            res[i] = i-stk.top();
        }
        stk.push(i);
    }
    return res;
}

//variant-2 leetcode O(N) for n calls

class StockSpanner {
private:
    stack<pair<int, int>> stk;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span=1;
        while(!stk.empty() && stk.top().first <= price) {
            span += stk.top().second;
            stk.pop();
        }

        stk.push({price, span});
        return span;
    }
};

int main() {

    vector<int> arr = {100, 80, 60, 70, 60, 75, 85};
    naive(arr);
    cout << endl;
    vector<int> res = optimized(arr);
    for (int val : res) {
        cout << val << " ";
    }
    cout << endl;

    return 0;

}
