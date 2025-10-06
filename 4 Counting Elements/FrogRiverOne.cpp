#include <vector>

int solution(int X, std::vector<int> &A) {
    int positions_left = X,
        vec_len = A.size(),
        curr_time = 0;

    std::vector<bool> counted(X, false); // do not use an array here because it can couse stack overflow

    for (; curr_time < vec_len; curr_time++) {
        if (!counted[A[curr_time]-1]) {
            counted[A[curr_time]-1] = true;
            positions_left--;
        }

        if (positions_left == 0) break;
    }

    if (positions_left > 0) return -1;
    else return curr_time;
}