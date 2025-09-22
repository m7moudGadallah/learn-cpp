#include <iostream>

using namespace std;

int main() {
    const int NUM_OF_DIR = 3;
    const int DIR_X_OFFSET[NUM_OF_DIR]{ 1, 0, 1 }; // {right, bottom, diagonal}
    const int DIR_Y_OFFSET[NUM_OF_DIR]{ 0, 1, 1 }; // {right, bottom, diagonal}
    int rows, cols;

    cin >> rows >> cols;

    int grid[rows][cols];

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            cin >> grid[r][c];
        }
    }

    int ans = grid[0][0];

    int r = 0, c = 0;

    while (r < rows and c < cols) {
        int best_dir = -1;

        for (int i = 0; i < NUM_OF_DIR; ++i) {
            const int new_r = r + DIR_X_OFFSET[i];
            const int new_col = c + DIR_Y_OFFSET[i];

            if (new_r >= rows or new_col >= cols) continue;

            if (best_dir < 0) {
                best_dir = i;
                continue;
            }

            const int best_val = grid[r + DIR_X_OFFSET[best_dir]][c + DIR_Y_OFFSET[best_dir]];
            const int curr_val = grid[new_r][new_col];

            if (curr_val > best_val) {
                best_dir = i;
            }
        }

        if (best_dir == -1)
            break;

        r += DIR_X_OFFSET[best_dir];
        c += DIR_Y_OFFSET[best_dir];
        ans += grid[r][c];
    }

    cout << ans << '\n';
    return 0;
}