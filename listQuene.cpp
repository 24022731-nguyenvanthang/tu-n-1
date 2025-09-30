#include <iostream>
using namespace std;

const int MAX = 100;

struct QueueArray {
    int data[MAX];
    int n;  // s? ph?n t?

    QueueArray() {
        n = 0;
    }

    bool isEmpty() {
        return n == 0;
    }

    void enqueue(int item) {
        if (n >= MAX) {
            cout << "Queue day!" << endl;
            return;
        }
        data[n++] = item; // thêm vào cu?i
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue rong!" << endl;
            return -1;
        }
        int val = data[0]; // l?y ??u
        // d?ch trái các ph?n t?
        for (int i = 1; i < n; i++) {
            data[i - 1] = data[i];
        }
        n--;
        return val;
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue rong!" << endl;
            return -1;
        }
        return data[0];
    }

    int size() {
        return n;
    }
};

int main() {
    QueueArray q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front: " << q.front() << endl;  // 10
    cout << "Dequeue: " << q.dequeue() << endl; // 10
    cout << "Front: " << q.front() << endl;  // 20
    cout << "Size: " << q.size() << endl;    // 2
}
