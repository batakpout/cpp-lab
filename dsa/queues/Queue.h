class Queue {
    int *arr;
    int cs;
    int ms;
    int front;
    int rear;

public:
    Queue(int defaultSize = 5) {
        arr = new int[defaultSize];
        ms = defaultSize;
        cs = 0;
        front = 0;
        rear = ms - 1;
    }

    bool empty() {
        return cs == 0;
    }

    bool full() {
        return cs == ms;
    }

    void push(int item) {
        if (!full()) {
            rear = (rear + 1) % ms;
            arr[rear] = item;
            cs++;
        }
    }

    void pop() {
        if (!empty()) {
            front = (front + 1) % ms;
            cs--;
        }
    }

    int getFront() {
        return arr[front];
    }
};
