#include <iostream>

const int MAX_NUM_RANGE = 900;
using namespace std;

int main() {
    int n, num;
    int freq[MAX_NUM_RANGE + 1]{ 0 };

    cin >> n;

    while (n--) {
        cin >> num;
        freq[num]++;
    }

    for (int i = 0; i <= MAX_NUM_RANGE; ++i) {
        for (int j = 0; j < freq[i]; ++j) {
            cout << i << ' ';
        }
    }
    cout << '\n';

    return 0;
}