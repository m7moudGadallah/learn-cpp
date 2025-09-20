#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int prefix_ones[n + 1]{ 0 };

    for (int i = 1; i <= n; ++i) {
        int num; cin >> num;
        prefix_ones[i] += prefix_ones[i - 1] + num;
    }


    for (int sz = n; sz > 0; --sz) {
        for (int i = sz; i <= n; i++) {
            const int ones = prefix_ones[i] - prefix_ones[i - sz];

            if (2 * ones == sz) {
                cout << sz << '\n';
                return 0;
            }
        }
    }

    return 0;
}