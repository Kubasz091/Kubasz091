int solution(int A, int B, int K) {
    int A_divisable = !(bool)(A % K),
        B_divisable = !(bool)(B % K);

    return ((B-B_divisable) - (A+A_divisable)) / K + A_divisable + (B_divisable && A != B);
    // return ((B-!(bool)(B % K)) - (A+!(bool)(A % K))) / K + !(bool)(A % K) + (!(bool)(B % K) && A != B);
}