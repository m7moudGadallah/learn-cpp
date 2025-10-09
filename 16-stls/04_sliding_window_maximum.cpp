#include <iostream>
#include<vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(const vector<int>& nums, const int& k) const {
        vector<int> ans;
        deque<int> left_max;

        for (int left = 0, right = 0; right < nums.size(); ++right) {
            while (!left_max.empty() and nums[right] >= nums[left_max.back()]) {
                left_max.pop_back();
            }

            left_max.emplace_back(right);

            if ((right - left + 1) >= k) {
                ans.emplace_back(nums[left_max.front()]);
                ++left;

                while (!left_max.empty() and left_max.front() < left) {
                    left_max.pop_front();
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums{ 1,3,-1,-3,5,3,6,7 };

    auto ans = sol.maxSlidingWindow(nums, 3);

    for (const auto& val : ans) {
        cout << val << ", ";
    }
    cout << '\n';

    // sol.maxSlidingWindow({ 1 }, 1);
    return 0;
}