#include <iostream>

using namespace std;

int main() {
    const int FROM_3D_TO_1D_OPTION = 1;
    const int FROM_1D_TO_3D_OPTION = 2;

    int r, c, d;
    cin >> r >> c >> d;

    int choice;
    cin >> choice;

    switch (choice) {
        case FROM_3D_TO_1D_OPTION: {
            int i, j, k;
            cin >> i >> j >> k;
            cout << (i * c * d) + (j * d) + k << '\n';
            break;
        }

        case FROM_1D_TO_3D_OPTION: {
            int idx;
            cin >> idx;

            int k = idx % d;
            int j = ((idx - k) / d) % c;
            int i = (idx - k) / (c * d);

            cout << i << ' ' << j << ' ' << k << '\n';
            break;
        }
    }

    return 0;
}