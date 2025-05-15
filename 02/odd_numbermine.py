from random import randint as rint
def solution_too_slow(A):
    odd_number = None
    while len(A) != 1 and odd_number is None:
        idx = rint(0, len(A)-1)
        nb = A.pop(idx)
        try:
            A.remove(nb)
        except:
            odd_number = nb
    if len(A) == 1:
        odd_number = A[0]
    return odd_number

def solution_also_too_slow(A):
    for x in set(A):
        if A.count(x) % 2 == 1:
            return x


def solution(A):
    result = 0
    for num in A:
        result ^= num
    return result

A = [9, 3, 9, 3, 9, 7, 9]
print(solution(A))