#include <iostream>

using namespace std;

int main() {
    const string SUCCESS_MSG = "YES";
    const string FAIL_MSG = "NO";

    int rows, cols;
    cin >> rows >> cols;

    int grid[rows][cols];

    // input + preprocessing
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            cin >> grid[r][c];
        }
    }

    int queries;
    cin >> queries;
    int r1, r2;

    while (queries--) {
        cin >> r1 >> r2;

        bool is_smaller = true;
        for (int c = 0; c < cols; ++c) {
            if (grid[r1 - 1][c] >= grid[r2 - 1][c]) {
                is_smaller = false;
                break;
            }
        }

        cout << (is_smaller ? SUCCESS_MSG : FAIL_MSG) << '\n';
    }

    return 0;
}