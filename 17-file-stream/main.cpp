#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("read.txt", "rt", stdin);
    freopen("write.txt", "wt", stdout);

    int n; cin >> n;
    vector<int> nums(n);

    for (auto& num : nums) {
        cin >> num;
    }

    for (const auto& num : nums) {
        cout << num << '\n';
    }

    return 0;
}