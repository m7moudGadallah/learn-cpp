#include <iostream>

using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;

    int max_val = INT_MIN,
        max_val_index = -1, val;

    for (int i = 0; i < (rows * cols); ++i) {
        cin >> val;

        if (val >= max_val) {
            max_val = val;
            max_val_index = i;
        }
    }

    int r = max_val_index / cols,
        c = max_val_index % cols;

    cout << "Max value at position " << r << ' ' << c << " with value = " << max_val << '\n';

    return 0;
}