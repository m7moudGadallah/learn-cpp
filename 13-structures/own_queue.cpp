#include <iostream>

using namespace std;

struct OwnQueue {
private:
    static const int QUEUE_SIZE = 100;
    int len;
    int data[QUEUE_SIZE];
    int head = 0, tail = 0;

private:
    int increment_pointer(int p) {
        return (p + QUEUE_SIZE + 1) % QUEUE_SIZE;
    }

    int decrement_pointer(int p) {
        return (p + QUEUE_SIZE - 1) % QUEUE_SIZE;
    }
public:
    OwnQueue() {
        this->len = 0;
    }

    void add_end(int value) {
        if (is_full()) return;

        tail = increment_pointer(tail);
        if (is_empty()) head = tail;
        ++len;
        data[tail] = value;
    }

    void add_front(int value) {
        if (is_full()) return;

        head = decrement_pointer(head);
        if (is_empty()) head = tail;
        ++len;
        data[head] = value;
    }

    int remove_front() {
        if (is_empty()) {
            return INT_MIN;
        }

        int removed_val = data[head];

        head = increment_pointer(head);
        --len;

        return removed_val;
    }

    int size() {
        return len;
    }

    bool is_empty() {
        return !size();
    }

    bool is_full() {
        return len >= QUEUE_SIZE;
    }

    void print() {
        for (int i = head; !is_empty() and i <= tail; i = increment_pointer(i)) {
            cout << data[i] << ' ';
        }
        cout << '\n';
    }
};

int main() {
    OwnQueue my_queue;
    my_queue.add_end(10);
    my_queue.print();
    my_queue.add_end(20);
    my_queue.print();
    my_queue.add_end(30);
    my_queue.print();

    my_queue.add_front(1);
    my_queue.add_front(4);
    my_queue.print();

    cout << my_queue.remove_front() << '\n';

    my_queue.print();

    return 0;
}