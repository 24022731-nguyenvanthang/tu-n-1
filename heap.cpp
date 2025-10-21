#include <iostream>
#include <vector>
using namespace std;

class Heap {
private:
    vector<int> heap;

    void swap(int i, int j) {
        swap(heap[i], heap[j]); 
    }

    void swim(int k) {
        for (;k > 1 && heap[k / 2] < heap[k];)
        {
            swap(k, k / 2);
            k = k / 2; 
        }
    }

    void sink(int k) {
        int n = heap.size() - 1;
        while (2 * k <= n) {
            int j = 2 * k;
            if (j < n && heap[j] < heap[j + 1]) j++;
            if (heap[k] >= heap[j]) break;
            swap(k, j);
            k = j;
        }
    }

public:
    Heap() {
        heap.push_back(-1);
    }


    void insert(int value) {
        heap.push_back(value);
        swim(heap.size() - 1);
    }

    
    int delMax() {
        if (isEmpty()) {
            return -1;
        }
        int maxValue = heap[1];
        swap(1, heap.size() - 1);
        heap.pop_back();
        sink(1);
        return maxValue;
    }

    
    int max() {
        if (isEmpty()) {
            return -1;
        }
        return heap[1];
    }

   
    bool isEmpty() {
        return heap.size() <= 1;
    }

    
    int size() {
        return heap.size() - 1;
    }

};
