#include <iostream>
#include <deque>

using namespace std;

struct last_k_numbers_sum_stream {
private:
    int k;
    deque<int> stream;
    int running_sum;
public:
    last_k_numbers_sum_stream(int _k) {
        k = _k;
        running_sum = 0;
    }

    int next(int new_num) {
        stream.push_back(new_num);

        if (stream.size() > k) {
            running_sum -= stream.front();
            stream.pop_back();
        }

        running_sum += new_num;

        return running_sum;
    }
};

int main() {
    last_k_numbers_sum_stream processor(4);

    int num;
    while (cin >> num)
        cout << processor.next(num) << "\n";

    return 0;
}