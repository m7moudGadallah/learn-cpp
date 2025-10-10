#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(const vector<int>& temperatures) const {
        stack<int> temp_stack;

        vector<int> daily_temp(temperatures.size(), 0);

        for (int i = temperatures.size() - 1; i >= 0; --i) {
            while (!temp_stack.empty() and temperatures[temp_stack.top()] <= temperatures[i]) {
                temp_stack.pop();
            }

            if (!temp_stack.empty()) {
                daily_temp[i] = temp_stack.top() - i;
            }

            temp_stack.emplace(i);
        }

        return daily_temp;
    }
};