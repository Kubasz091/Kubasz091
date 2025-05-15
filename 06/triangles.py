def sort(A):
    if len(A) == 0: return A

    max_a = float('-inf')
    min_a = float('inf')

    for i in A:
        max_a = max(max_a, i)
        min_a = min(min_a, i)

    exists = [0] * (max_a - min_a + 1)
    for i in A:
        exists[i-min_a] += 1

    A = []
    for n, i in enumerate(exists):
        for _ in range(i):
            A.append(n+min_a)
    return A

def solution(A):
    A = sort(A)
    A.reverse()

    for i in range(0, len(A)-2):
        if A[i] < A[i+1] + A[i+2]:
            return 1
    return 0

A = [0, 2147483647, 2147483647]
print(solution(A))