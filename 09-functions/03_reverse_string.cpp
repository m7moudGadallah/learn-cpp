#include <iostream>

using namespace std;

string reverse_str(const string& str) {
    string ans = str;

    int left = 0, right = ans.size() - 1;

    while (left < right) {
        swap(ans[left++], ans[right--]);
    }

    return ans;
}

int main() {
    string str;
    cin >> str;

    cout << reverse_str(str) << '\n';

    return 0;
}