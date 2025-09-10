/**
 
 Finding Cabs:
 Given N cartesian points in a 2D plane each represents the location of the cab.
 You are standing at origin, you want to know the names of nearest k cars.
 Sample Input:
 N=5, k=3
 c1 1,1 --> squarroot(2)
 c2 2,1 --> squarroot(5)
 c3 3,2 --> squarroot(13)
 c4 0,1 --> squarroot(1)
 c5 2,3 --> squarroot(13)
//squareroot is not that necessary here
 output:
 c1, c2, c4

 Approach 1:
    Sort them and then print k elements O(nlog(n) + k) , k to print them
Apporach 2:
    build min heap out of the input, pop k items from it. O(N + k.log(n))
Approach 3:
    insert k items in max heap. Then iterate over n-k items in list and compare each item
    with the root, if it is < root then replace it else leave it as it is, this way largest will 
    pop out of heap and we can insert smaller one than root and when we have scanned entire array
    our max heap will contain k smallest elements.
    O(k + (n-k).log(k)), since they are sorted by default in descending order, just reverse them so , O(k + (n-k).log(k)) + O(k)

    So we will go will Approach 3 as complexity seems better.
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Car {
    string id;
    int x, y;

public:
    Car(string id, int x, int y) {
        this->id = id;
        this->x = x;
        this->y = y;
    }

    int distance() const {
        return x * x + y * y;
    }

    string getId() const {
        return id;
    }

    static void printNearestCars(const vector<Car>& cars, int k);
};

// Comparator must come **after Car is declared**
class CarCmp {
public:
    bool operator()(const Car& c1, const Car& c2) const {
        return c1.distance() < c2.distance(); // max heap
    }
};

void Car::printNearestCars(const vector<Car>& cars, int k) {
    
    priority_queue<Car, vector<Car>, CarCmp> max_heap(cars.begin(), cars.begin() + k);

    for (int i = k; i < cars.size(); i++) {
        if (cars[i].distance() < max_heap.top().distance()) {
            max_heap.pop();
            max_heap.push(cars[i]);
        }
    }

    while (!max_heap.empty()) {
        cout << max_heap.top().getId() << endl;
        max_heap.pop();
    }
    //above will print descending order since it is a max heap, if we want ascending,
    //we can store k items in vector, and outside of for loop, reverse(v.begin(), v.end())
}


 int main() {
    int N, K;
    cin>>N>>K;
    
    string id;
    int x,y;

    vector<Car>cars;
    for(int i=0;i<N;i++) {
        cin>>id>>x>>y;
        Car car(id, x,y);
        cars.push_back(car);
    }
    Car::printNearestCars(cars, K);
    return 0;

 }

