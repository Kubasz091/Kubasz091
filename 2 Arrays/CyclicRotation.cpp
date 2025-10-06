#include <vector>

std::vector<int> solution(const std::vector<int> &A, int K) {
    if (A.empty()) return A;

    int vec_len = static_cast<int>(A.size());
    K %= vec_len;
    if (K == 0) return A;

    std::vector<int> result = A;

    int new_pos = 0;

    for (int i = 0; i < vec_len; i++) {
        new_pos = (i + K) % vec_len;
        result[new_pos] = A[i];
    }

    return result;
}
