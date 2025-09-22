#include <iostream>

using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;

    const int NUM_OF_DIR = 4;
    const int DIR[NUM_OF_DIR][2]{
        {-1, 0}, // up
        {0, 1}, // right
        {1, 0}, // down
        {0, -1} // left
    };

    int commands;
    cin >> commands;
    int r = 0, c = 0;

    while (commands--) {
        int command, steps;
        cin >> command >> steps;

        --command; // to be zero-based, to directly access from DIR

        r = (r + (DIR[command][0] * steps) + rows) % rows;
        c = (c + (DIR[command][1] * steps) + cols) % cols;

        cout << "(" << r << ", " << c << ")\n";
    }

    return 0;
}