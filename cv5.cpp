#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    void heapify(int i) {
        // TODO: Implementujte metodu heapify
        int size = heap.size();
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < size && heap[left] > heap[largest]){
            largest = left;
        }
        if(right < size && heap[right] > heap[largest]){
            largest = right;
        }
        if(largest != i){
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

public:
    void insert(int key) {
        // TODO: Implementujte metodu pro vložení prvku
        heap.push_back(key);
        int c = heap.size() - 1;

        while(c != 0 && heap[(c-1)/2] < heap[c]){
            swap(heap[c], heap[(c-1)/2]);
            c = (c-1)/2;
        }
    }

    int extractMax() {
        // TODO: Implementujte metodu pro odebrání a vrácení největšího prvku
        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        
        if(heap.size() > 0){
            heapify(0);
        }

        return maxVal;
    }

    void printHeap() {
        for (int i : heap) {
            cout << i << " ";
        }
        cout << endl;
    }

    bool isEmpty() {
        return heap.empty();
    }
};

int main() {
    MaxHeap maxHeap;
    int num;

    // Načtení čísel ze stdin
    while (cin >> num) {
        maxHeap.insert(num);
    }

    // Postupné odebírání prvků a tisk haldy
    while (!maxHeap.isEmpty()) {
        cout << "(" << maxHeap.extractMax() << ") ";
        maxHeap.printHeap();
    }

    return 0;
}