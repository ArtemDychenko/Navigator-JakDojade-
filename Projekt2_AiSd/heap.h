#ifndef HEAP_H
#define HEAP_H
#include "vector.h"
#include "graph.h"

using namespace std;

struct MinHeapNode
{
    int  v;
    int dist;

    MinHeapNode() {
        this->v = 0;
        this->dist = 0;
    }

    MinHeapNode(int v, int dist) {
        this->v = v;
        this->dist = dist;
    }

    friend ostream& operator<<(ostream& os, const MinHeapNode& obj) {

        os << obj.v << " dist: " << obj.dist;

            return os;
    }

};

class MyHeap {
private:
    vector<MinHeapNode> heap;

    void heapifyUp(int i) {
        int parent = (i - 1) / 2;
        if (heap[parent].dist > heap[i].dist) {
            swap(heap[parent], heap[i]);
            heapifyUp(parent);
        }
    }

    void heapify(int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        if (left < heap.getSize() && heap.get(left).dist < heap.get(smallest).dist) {
            smallest = left;
        }
        if (right < heap.getSize() && heap.get(right).dist < heap.get(smallest).dist) {
            smallest = right;
        }
        if (smallest != i) {
            swap(heap.get(i), heap.get(smallest));
            heapify(smallest);
        }
    }

public:

    vector<MinHeapNode> getHeap() { return heap; }

    void push(MinHeapNode x) {
        heap.push(x);
        int i = heap.getSize() - 1;
        int parent = (i - 1) / 2;
        while (i > 0 && heap[parent].dist > heap[i].dist) {
            swap(heap[parent], heap[i]);
            i = parent;
            parent = (i - 1) / 2;
        }
    }

    MinHeapNode pop() {
       /* heap.print();*/
        MinHeapNode result = heap[0];
        heap[0] = heap.back();
        heap.pop();
        heapify(0);
       /* heap.print();*/
        return result;
    }

    void decreaseKey(int i, int newDistance) {
        heap[i].dist = newDistance;
        heapifyUp(i);
    }

  /*  bool isInMinHeap(MyHeap* heap, int vert) {
        if (heap[vert])
    }*/

    bool empty() {
        if (heap.getSize() == 0) {
            return true;
       }
        return false;
    }
};




#endif