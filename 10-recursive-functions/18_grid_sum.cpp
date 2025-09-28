#include <iostream>

using namespace std;

int grid[100][100];
const int NUM_OF_DIRECTIONS = 3;
const int X_DIR[]{ 0, 1, 1 };
const int Y_DIR[]{ 1, 1, 0 };

int calc_grid_sum(const int& rows, const int& cols, int r = 0, int c = 0) {
    if (r == rows - 1 and c == cols - 1) {
        return grid[r][c];
    }

    int path = -1, best_val = INT_MIN;

    for (int i = 0; i < NUM_OF_DIRECTIONS; ++i) {
        int new_r = r + X_DIR[i];
        int new_c = c + Y_DIR[i];

        if (new_r >= rows or new_c >= cols) continue;

        if (best_val < grid[new_r][new_c]) {
            path = i;
            best_val = grid[new_r][new_c];
        }
    }

    return grid[r][c] + calc_grid_sum(rows, cols, r + X_DIR[path], c + Y_DIR[path]);
}

int main() {
    int rows, cols;

    cin >> rows >> cols;

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            cin >> grid[r][c];
        }
    }

    cout << calc_grid_sum(rows, cols) << '\n';
    return 0;
}