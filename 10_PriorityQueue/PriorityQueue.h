#include <stdexcept>
#include <array>

template <typename T, size_t Capacity>
class PriorityQueue {
public:
    PriorityQueue() : heapSize(0) {}

    void push(const T& value) {
        if (heapSize >= Capacity) {
            throw std::overflow_error("PriorityQueue is full");
        }
        heap[heapSize + 1] = value; // Start from index 1
        siftUp(heapSize + 1);
        ++heapSize;
    }

    void pop() {
        if (heapSize == 0) {
            throw std::out_of_range("PriorityQueue is empty");
        }
        std::swap(heap[1], heap[heapSize]); // Start from index 1
        --heapSize;
        if (heapSize > 0) {
            siftDown(1);
        }
    }

    const T& top() const {
        if (heapSize == 0) {
            throw std::out_of_range("PriorityQueue is empty");
        }
        return heap[1]; // Start from index 1
    }

    bool empty() const {
        return heapSize == 0;
    }

    size_t size() const {
        return heapSize;
    }

private:
    std::array<T, Capacity + 1> heap; // +1 to accommodate 1-based indexing
    size_t heapSize;

    void siftUp(size_t index) {
        while (index > 1) { // Start from index 1
            size_t parent = index / 2;
            if (heap[index] <= heap[parent]) {
                break;
            }
            std::swap(heap[index], heap[parent]);
            index = parent;
        }
    }

    void siftDown(size_t index) {
        size_t leftChild = 2 * index;
        size_t rightChild = 2 * index + 1;
        size_t largest = index;

        if (leftChild <= heapSize && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }
        if (rightChild <= heapSize && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }
        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            siftDown(largest);
        }
    }
};
