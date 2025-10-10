#include<iostream>
#include<stack>

using namespace std;

class Solution {
private:
    static const int OPEN_BRACKET_CODE = -100; // '('
    static const int CLOSE_BRACKET_CODE = -101; // ')'
    static int map_bracket(const char& c) {
        return (c == '(' ? OPEN_BRACKET_CODE : CLOSE_BRACKET_CODE);
    }
public:
    int scoreOfParentheses(const string& s) const {
        stack<int> scoreStack;

        for (const auto& ch : s) {
            if (map_bracket(ch) == OPEN_BRACKET_CODE) {
                scoreStack.emplace(map_bracket(ch));
                continue;
            }

            int running_score = 0;

            while (!scoreStack.empty() and scoreStack.top() != OPEN_BRACKET_CODE) {
                running_score += scoreStack.top();
                scoreStack.pop();
            }

            if (scoreStack.top() != OPEN_BRACKET_CODE) return -1;
            scoreStack.pop();
            scoreStack.push(max(2 * running_score, 1));
        }

        int tot_score = 0;

        while (!scoreStack.empty()) {
            tot_score += scoreStack.top();
            scoreStack.pop();
        }

        return tot_score;
    }
};
