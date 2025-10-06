#include <vector>

int solution(std::vector<int> &A) {
    if (A.empty()) return 1;

    int vec_len = A.size();
    int expected_len = vec_len + 1;

    int expected_cum_sum = 0;
    if (expected_len % 2) expected_cum_sum = ((1 + expected_len) / 2) * expected_len;
    else {
        expected_cum_sum = ((1 + vec_len) / 2) * vec_len;
        expected_cum_sum += expected_len;
    }

    int actual_cum_sum = 0;
    for (int i = 0; i < vec_len; i++){
        actual_cum_sum += A[i];
    }

    return expected_cum_sum - actual_cum_sum;
}