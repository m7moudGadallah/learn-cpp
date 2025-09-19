#include <iostream>

const int MAX_DEC_DIGIT = 9;

using namespace std;

int main() {
    int n, num;
    int freq[MAX_DEC_DIGIT + 1]{ 0 };

    cin >> n;

    while (n--) {
        cin >> num;

        while (num) {
            freq[num % 10]++;
            num /= 10;
        }
    }

    for (int i = 0; i < (sizeof(freq) / sizeof(int)); ++i) {
        cout << i << ' ' << freq[i] << '\n';
    }

    return 0;
}