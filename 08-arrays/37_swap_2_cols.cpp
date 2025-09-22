#include <iostream>

using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;

    int grid[rows][cols];

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            cin >> grid[r][c];
        }
    }

    int col1, col2;
    cin >> col1 >> col2;

    for (int r = 0; r < rows; ++r) {
        swap(grid[r][col1], grid[r][col2]);
    }

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            cout << grid[r][c] << ' ';
        }
        cout << '\n';
    }

    return 0;
}