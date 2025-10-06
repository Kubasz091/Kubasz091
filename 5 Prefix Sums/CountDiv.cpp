#include <algorithm>

int solution(int A, int B, int K) {
    return B / K - std::max(A - 1, 0) / K + (A == 0);
}