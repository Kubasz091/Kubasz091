def solution_old(A, K):
    # if type(K) != int or K < -1000 or K > 1000:
    #     raise Exception("Invalid K given!")

    # for num in A:
    #     if type(num) != int or num < 0 or num > 100:
    #         raise Exception("Invalid A given!")

    if len(A) == 0: return A
    else:
        for _ in range(K):
            A_ = A.copy()
            element_rotated = A[-1]
            A_.pop(-1)
            A__ = [element_rotated]
            A__.extend(A_)
            A = A__

            del A__
            del A_
        return A

def solution(A, K):
    if len(A) == 0: return A
    else:
        for _ in range(K):
            A.insert(0, A.pop(-1))
        return A

A = [1, 2, 3, 4]
K = 2

print(solution(A, K))
