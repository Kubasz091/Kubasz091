def solution(A):
    sum_A = sum(A)
    max_A = len(A) + 1
    exp_sum = int(((1 + max_A)/2)*max_A)
    return exp_sum-sum_A