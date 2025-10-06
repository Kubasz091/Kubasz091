#include <cmath>

int solution(int N) {
    int curr_len = 0;
    int max_len = 0;

    unsigned int i = 1<<30;
    int n = 0;

    bool count = false;

    for (; i > 0; i/=2, n++) {
        if (N & i) {
            count = count | 1;

            max_len = (curr_len > max_len) ? curr_len : max_len;
            curr_len = 0;
        }
        else if (count) curr_len++;
    }

    return max_len;
}
