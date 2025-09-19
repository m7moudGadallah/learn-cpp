#include <iostream>

#define MIN_NUM_RANGE -500
#define MAX_NUM_RANGE 270

using namespace std;


inline int normalize(int num) {
    return num + abs(MIN_NUM_RANGE);
}

inline int denormalize(int num) {
    return num - abs(MIN_NUM_RANGE);
}

int main() {
    int n, num;
    int freq[abs(MIN_NUM_RANGE) + abs(MAX_NUM_RANGE) + 1]{ 0 };
    cin >> n;

    int most_freq = 0;

    while (n--) {
        cin >> num;

        int normalized_num = normalize(num);

        freq[normalized_num]++;

        if (freq[most_freq] < freq[normalized_num]) {
            most_freq = normalized_num;
        }
    }

    cout << denormalize(most_freq) << " repeated " << freq[most_freq] << " times\n";

    return 0;
}