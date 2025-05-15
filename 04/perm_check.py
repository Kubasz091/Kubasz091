def solution(A):
    A_set = list(set(A.copy()))
    len_A = len(A)
    len_A_set = len(A_set)
    max_A = max(A)
    isIt = (len_A == max_A and max_A == len_A_set)
    return int(isIt)

A = [4, 1, 3, 2, 2]
print(solution(A))