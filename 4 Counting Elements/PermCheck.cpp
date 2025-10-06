#include <vector>

int solution(std::vector<int> &A) {
    int vec_len, ints_missing;
    vec_len = ints_missing = A.size();

    if (vec_len == 1) return (A[0] == 1);

    std::vector<bool> int_observed(vec_len, false);

    for (int i = 0; i < vec_len; i++) {
        if (A[i] > vec_len || int_observed[A[i] - 1]) break;
        else {
            int_observed[A[i] - 1] = true;
            ints_missing--;
        }
    }

    return !(bool) ints_missing;
}