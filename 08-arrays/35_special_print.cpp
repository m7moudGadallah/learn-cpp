#include <iostream>

using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;

    int val;

    int left_diagonal_sum = 0,
        right_diagonal_sum = 0,
        last_row_sum = 0,
        last_col_sum = 0;

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            cin >> val;

            // left diagonal
            if (r == c) {
                left_diagonal_sum += val;
            }

            // right diagonal
            if ((cols - c - 1) == r) {
                right_diagonal_sum += val;
            }

            // last row
            if (r == rows - 1) {
                last_row_sum += val;
            }

            // last column
            if (c == cols - 1) {
                last_col_sum += val;
            }
        }
    }

    cout << left_diagonal_sum << ' ' << right_diagonal_sum << '\n';
    cout << last_row_sum << ' ' << last_col_sum << '\n';

    return 0;
}