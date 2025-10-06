#include <vector>

int solution(std::vector<int> &A) {
    int result = 0x7FFFFFFF,
        vec_len = A.size(),
        vec_sum_left = 0,
        vec_sum_right = 0,
        current_diff,
        i = 1;

    if (vec_len < 3) return 0;

    for (; i < vec_len; i++){
        vec_sum_right += A[i];
    }

    vec_sum_left += A[0];
    for (i = 1; i < vec_len; i++) {
        current_diff = (vec_sum_right - vec_sum_left > 0) ? vec_sum_right - vec_sum_left : vec_sum_left - vec_sum_right;

        if (current_diff < result) result = current_diff;

        vec_sum_left += A[i];
        vec_sum_right -= A[i];
    }
    return result;
}
