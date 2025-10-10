#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeDuplicates(const string& s) const {
        string ans{};

        for (int i = 0; i < s.size(); ++i) {
            if (!ans.empty() and ans.back() == s[i]) {
                ans.pop_back();
            }
            else {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};
