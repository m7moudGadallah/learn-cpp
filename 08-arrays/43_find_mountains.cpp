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

    const int NUM_OF_NEIGHBOURS = 8;
    const int NEIGHBOURS_DIR[NUM_OF_NEIGHBOURS][2] = {
        {-1, 0}, // top
        {-1, 1}, // top-right
        {0, 1}, // right
        {1, 1}, // bottom-right
        {1, 0}, // bottom
        {1, -1}, // bottom-left,
        {0, -1}, // left
        {-1, -1} // top-left
    };

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            bool is_mountain = true;

            for (int dir = 0; dir < NUM_OF_NEIGHBOURS; ++dir) {
                int dr = r + NEIGHBOURS_DIR[dir][0];
                int dc = c + NEIGHBOURS_DIR[dir][1];

                if (dr < 0 or dr >= rows or dc < 0 or dc >= cols) continue;

                if (grid[r][c] <= grid[dr][dc]) {
                    is_mountain = false;
                    break;
                }
            }

            if (is_mountain) {
                cout << r << ' ' << c << '\n';
            }
        }
    }
    return 0;
}