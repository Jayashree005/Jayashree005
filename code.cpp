#include <queue>
#include <iostream>
#include <stdexcept>

template <typename T, typename Priority = int>
class PriorityQueue {
private:
    struct QueueNode {
        T data;
        Priority priority;

        QueueNode(const T& d, const Priority& p) : data(d), priority(p) {}

        bool operator<(const QueueNode& other) const {
            return priority < other.priority;
        }
    };

    std::priority_queue<QueueNode> pq;

public:
    void push(const T& data, const Priority& priority) {
        pq.emplace(data, priority);
    }

    void pop() {
        if (pq.empty()) {
            throw std::out_of_range("PriorityQueue is empty, cannot pop.");
        }
        pq.pop();
    }

    
const T& top() const {
        if (pq.empty()) {
            throw std::out_of_range("PriorityQueue is empty, no top element.");
        }
        return pq.top().data;
    }

    bool empty() const {
        return pq.empty();
    }

    size_t size() const {
        return pq.size();
    }
};
