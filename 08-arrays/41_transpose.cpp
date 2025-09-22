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

    // Transpose
    for (int c = 0; c < cols; ++c) {
        for (int r = 0; r < rows; ++r) {
            cout << grid[r][c] << ' ';
        }
        cout << '\n';
    }

    return 0;
}