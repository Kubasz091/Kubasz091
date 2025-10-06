#include <vector>
#include <algorithm>

int solution(std::vector<int> &A) { // takie wymyśliłem sam z pomocą w postaci podpowiedzi co trzeba zastosować, wykożystuje dodatkową przestrzeń, ale algorytm jest nie skomplikowany i złożoność czasowa to O(k*N)
    int i = 0, vec_len = A.size();
    std::vector<int> marks = A;

    for (i = 0; i < vec_len; i++) if (A[i] > 0 && A[i] <= vec_len) marks[A[i]-1] = A[i];

    for (i = 0; marks[i]-1 == i; i++);

    return i+1;
}


int solution2(std::vector<int> &A) { // takie rozwiazanie miałem totalnie bez podpowiedzi żadnej, ale tutaj jest sortowanie czyli złożoność o(Nlog(N))
    int smallest = 1, vec_len = A.size();

    if (A.size() > 1) std::sort(A.begin(), A.end());

    for (int i = 0; i < vec_len; i++) if (A[i] == smallest) smallest++;

    return smallest;
}

int solutionChat(std::vector<int> &A) { // takie rozwiazanie proponuje czat, one nie wykożystuje ani przestrzeni ani sortowania, ale złożoność algorytmu najwieksza. Teoretycznie najlepsze rozwiazanie ale nie wydaje mi sie że te wykożystanie pamieci jest aż tak ważne
    int n = static_cast<int>(A.size());
    if (n == 0) return 1;

    // 1) Check if 1 exists
    bool hasOne = false;
    for (int x : A) {
        if (x == 1) { hasOne = true; break; }
    }
    if (!hasOne) return 1;

    // 2) Normalize: collapse non-useful values to 1
    for (int i = 0; i < n; ++i) {
        if (A[i] <= 0 || A[i] > n) A[i] = 1;
    }

    // 3) Mark presence using index and sign
    for (int i = 0; i < n; ++i) {
        int v = std::abs(A[i]);      // value in [1..n]
        int idx = v - 1;             // target index
        if (A[idx] > 0) A[idx] = -A[idx]; // flip to negative (mark present)
        // if already negative, leave it
    }

    // 4) First positive index indicates missing number
    for (int i = 0; i < n; ++i) {
        if (A[i] > 0) return i + 1;
    }

    // 5) All present
    return n + 1;
}
