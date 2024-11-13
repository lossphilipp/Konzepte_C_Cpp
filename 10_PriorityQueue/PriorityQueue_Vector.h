#include <vector>
#include <stdexcept>

template <typename T>
class PriorityQueue {
public:
    PriorityQueue() = default;

    void push(const T& value) {
        heap.push_back(value);
        siftUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) {
            throw std::out_of_range("PriorityQueue is empty");
        }
        std::swap(heap.front(), heap.back());
        heap.pop_back();
        if (!heap.empty()) {
            siftDown(0);
        }
    }

    const T& top() const {
        if (heap.empty()) {
            throw std::out_of_range("PriorityQueue is empty");
        }
        return heap.front();
    }

    bool empty() const {
        return heap.empty();
    }

    size_t size() const {
        return heap.size();
    }

private:
    std::vector<T> heap;

    void siftUp(size_t index) {
        while (index > 0) {
            size_t parent = (index - 1) / 2;
            if (heap[index] <= heap[parent]) {
                break;
            }
            std::swap(heap[index], heap[parent]);
            index = parent;
        }
    }

    void siftDown(size_t index) {
        size_t leftChild = 2 * index + 1;
        size_t rightChild = 2 * index + 2;
        size_t largest = index;

        if (leftChild < heap.size() && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }
        if (rightChild < heap.size() && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }
        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            siftDown(largest);
        }
    }
};
