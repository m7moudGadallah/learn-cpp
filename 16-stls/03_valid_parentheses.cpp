#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(const string& s) const {
        stack<char> bracket_stack;

        for (const auto& ch : s) {
            char opening_bracket = get_opening_bracket(ch);

            if (opening_bracket and (bracket_stack.empty() or bracket_stack.top() != opening_bracket)) {
                return false;
            }

            if (!opening_bracket)
                bracket_stack.emplace(ch);
            else bracket_stack.pop();
        }

        return bracket_stack.empty();
    }
private:
    char get_opening_bracket(const char& ch) const {
        switch (ch) {
            case '}':
                return '{';
            case ']':
                return '[';
            case ')':
                return '(';
            default:
                return '\0';
        }
        return '\0';
    }
};