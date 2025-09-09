#include<iostream>
using namespace std;

//struct -> Default Access public by default, Typically used for POD (plain old data) or lightweight data holders


struct Person {
    int age;
    float height;
    Person(int a, float h) {
        age = a;
        height = h;
    }
};
struct MyCmp {
    /*
    •	operator() is the function call operator in C++.
	•	It allows you to make objects of MyCmp callable like a function.
    MyCmp cmp;
    cmp(p1, p2);  // Equivalent to cmp.operator()(p1, p2)
    */
    bool operator()(Person const& p1, Person const& p2) {
        return p1.height < p2.height; //max heap based on height
    }
};

int main() {
    //max heap
    priority_queue<int> pq1;
    pq1.push(10);
    pq1.push(15);
    pq1.push(5);
    cout << "Size of max priority queue: " << pq1.size() << endl;
    cout << "Top element: " << pq1.top() << endl;
    // Removing elements from the priority queue
    while (!pq1.empty()) {
        cout << pq1.top() << " ";
        pq1.pop();
    }
    cout << endl;
    //min heap,  here vector<int> is underlying container that stores the data
    priority_queue<int, vector<int>, greater<int>> pq2;
    pq2.push(10);
    pq2.push(15);
    pq2.push(5);

    cout << "Size of min priority queue: " << pq2.size() << endl;
    cout << "Top element: " << pq2.top() << endl;

    while (!pq2.empty()) {
        cout << pq2.top() << " ";
        pq2.pop();
    }
 
    cout << endl;

    //for min heap, if we don't want to use greater<int>, another trick is multiplying values //by -1 before inserting them.
    int arr[] = {10, 5, 15};
    // Negate elements to convert max heap into min heap
    for (int i = 0; i < 3; i++) {
        arr[i] = -arr[i];
    }

    priority_queue<int> pq3(arr, arr + 3);
    cout << "using negate:\n";
    while (!pq3.empty()) {
        cout << -pq3.top() << " "; // Negate again to get the actual values
        pq3.pop();
    }
    cout << endl;

    //priority queue with custom comparator
    priority_queue<Person, vector<Person>, MyCmp> pq4;
    pq4.push(Person(25, 5.9));
    pq4.push(Person(30, 6.1));
    pq4.push(Person(22, 5.7));

    cout << "Custom person queue:\n";
    while (!pq4.empty()) {
        cout << pq4.top().height << " ";
        pq4.pop();
    }
    //Custom comparators are useful in applications like job scheduling, AI search algorithms, etc.
    cout << endl;
    /*
     Priority Queues are used in many algorithms:
        Dijkstra’s Algorithm – To find the shortest path.
        Prim’s Algorithm – For finding the Minimum Spanning Tree.
        Huffman Coding – Used in data compression.
        Heap Sort – Sorting using priority queues.
        Task Scheduling – OS scheduling mechanisms.
    */
}