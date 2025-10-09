#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void reverse_queue(queue<int>& q) {
    if (q.empty()) return;

    stack<int> stk;

    while (!q.empty()) {
        stk.emplace(q.front());
        q.pop();
    }

    while (!stk.empty()) {
        q.emplace(stk.top());
        stk.pop();
    }
}
