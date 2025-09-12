/*
    -For insert in worst case we have to compare new node with each root, so O(H) in worst case but in CBT
        height is O(Log(N)) so complexity will be O(Log(n))

    -Also as we are going to parent using floor(n-1)/2 in each step , next N/4....till we reach ....1 so that is also the reason for O(Log(N)) to base 2

    - Using reserve(n) in C++ pre-allocates memory for at least n elements in advance.
        This means the vector won’t need to reallocate memory until you exceed n, which avoids repeatedly copying existing elements and freeing old memory.
        
        Without reserve(), every time the vector’s capacity is exceeded, it must allocate new memory (often doubling the capacity), copy or move all existing elements into the new space, and then free the old memory, which can be slower and less efficient.
*/
#include<iostream>
using namespace std;

class Heap {
    public:
    vector<int>v;
    void heapify(int i) {
        int left = 2*i;
        int right = 2*i+1;
        int minIdx = i;
        if(left < v.size() && v[left] < v[i]) {
            minIdx = left;
        }
        if(right < v.size() && v[right] < v[minIdx]) {
            minIdx = right;
        }
        if(minIdx != i) {
            swap(v[i], v[minIdx]);
            heapify(minIdx);
        }
    }

        Heap(int default_size=10) {
            v.reserve(default_size);
            v.push_back(-1);
        }

        //add item to the min heap
        void push(int data) {
            v.push_back(data);
            int idx = v.size() - 1;
            int parent = idx/2;
            while(idx > 1 && v[idx] < v[parent]) {
                swap(v[idx], v[parent]);
                idx = parent;
                parent = parent/2;
            }
        }

        //returns min element
        int top() {
            return v[1];
        }

        //remove min element
        //O(log(n)) as heapify takes that much time
        void pop() {
            swap(v[1], v[v.size()-1]);
            v.pop_back();
            heapify(1);
        }
        //todo use compare function to make this class as min or max heap
};

int main() {

    vector<int> items = {120,140,150,160,170,180};
    Heap heap;
    for(int num: items) {
        heap.push(num);
    }
    cout << "Heap:\n";
    vector<int> heapVector = heap.v;
    for(int n:heapVector) {
        cout << n << " ";
    }
    cout << endl;
    heap.push(80);
    heapVector = heap.v;
    for(int n:heapVector) {
        cout << n << " ";
    }
    cout << endl;
    cout << heap.top();
    cout << endl;
    
    heap.pop();

    heapVector = heap.v;
    for(int n:heapVector) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}