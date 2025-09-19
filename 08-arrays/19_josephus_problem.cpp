#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    bool is_removed[n]{ false };
    int curr_pos = 0;

    for (int t = 0; t < n; ++t) {
        int live_cnt = n - t;
        int curr_k = (k % live_cnt) ? k : live_cnt;

        int step = 0;

        while (true) {
            if (is_removed[curr_pos]) {
                curr_pos = (curr_pos + 1) % n;
                continue;
            }

            ++step;

            if (step >= k) break;
            curr_pos = (curr_pos + 1) % n;
        }

        cout << curr_pos + 1 << ' ';
        is_removed[curr_pos] = true;
        curr_pos = (curr_pos + 1) % n;
    }

    cout << '\n';

    return 0;
}