#include <iostream>
#include <queue>

using namespace std;

struct OurStack {
private:
    queue<int> q;
public:
    void push(int val) {
        queue<int> tmp_q{ q };
        q = queue<int>{};

        q.emplace(val);
        while (!tmp_q.empty()) {
            q.emplace(tmp_q.front());
            tmp_q.pop();
        }
    }
    void pop() {
        if (!q.empty()) {
            q.pop();
        }
    }
    int top() {
        return q.front();
    }
    bool empty() {
        return q.empty();
    }
};

int main() {
    OurStack s;

    for (int i = 1; i <= 3; ++i) {
        s.push(i);
    }

    while (!s.empty()) {
        cout << s.top() << " ", s.pop();
    }
    return 0;
}