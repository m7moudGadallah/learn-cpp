#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;

    bool is_prime[rows][cols];

    // input and preprocessing
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            int val; cin >> val;

            is_prime[r][c] = !(val < 2);

            for (int n = 2; n * n <= val; ++n) {
                if (val % n == 0) {
                    is_prime[r][c] = false;
                    break;
                }
            }
        }
    }

    int queries;
    cin >> queries;

    while (queries--) {
        int r1, c1, r2, c2;  // assuming (r1,c1) top-left, (r2,c2) bottom-right
        cin >> r1 >> c1 >> r2 >> c2;

        int ans = 0;

        for (int r = r1; r <= r2; ++r) {
            for (int c = c1; c <= c2; ++c) {
                ans += is_prime[r][c];
            }
        }

        cout << ans << '\n';
    }

    return 0;
}