def solution(A, B, K):
    if B % K == 0:
        divisable_after_B = B
    else:
        divisable_after_B = (B + K - (B % K))

    divisable_before_A = (A - (A % K))

    print("[", divisable_before_A, "  ", divisable_after_B, "]")

    num = divisable_after_B - divisable_before_A

    num = int(num / K) - 1

    if A == divisable_before_A:
        num += 1
    if B == divisable_after_B:
        num += 1

    return num

print(solution(1, 1, 11))