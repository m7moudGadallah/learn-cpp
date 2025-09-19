#include <iostream>

using namespace std;

int main() {
    int n, num;
    cin >> n;

    const int FREQ_SIZE = 151;
    int freq[FREQ_SIZE]{ 0 };

    for (int i = 0; i < n; ++i) {
        cin >> num;
        freq[num]++;
    }

    int mx_repeated = 0;

    for (int i = 0; i < FREQ_SIZE; ++i) {
        if (freq[i] > freq[mx_repeated]) {
            mx_repeated = i;
        }
    }

    cout << mx_repeated << " repeated " << freq[mx_repeated] << " times\n";

    return 0;
}