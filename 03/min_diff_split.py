import math
def solution_too_slow(A):
    minim = math.inf
    for i in range(1, len(A)):
        minim = min(minim, abs(sum(A[:i]) - sum(A[i:])))
        if minim == 0:
            break
    return minim

def solution(A):
    A.sort()
    A_sum = sum(A)
    A_min = A[0]
    A_max = A[-1]

A = [1, 2]
print(solution(A))