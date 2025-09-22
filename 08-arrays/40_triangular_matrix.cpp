#include <iostream>

using namespace std;

int main() {
    int rows, cols;
    cin >> rows;
    cols = rows;

    int lower_mat_sum = 0,
        upper_mat_sum = 0;

    int val;

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            cin >> val;

            // lower matrix values
            if (c <= r) {
                lower_mat_sum += val;
            }

            // upper matrix values
            if (c >= r) {
                upper_mat_sum += val;
            }
        }
    }

    cout << lower_mat_sum << ' ' << upper_mat_sum << '\n';

    return 0;
}