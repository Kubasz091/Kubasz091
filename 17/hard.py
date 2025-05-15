def solution(A):
    S = [0] * len(A)
    sum = None
    for i, num in enumerate(A):
        if sum is None:
            S.append(1)
        else:
            if abs(sum + num) < abs(sum + (num*-1)):
                S.append(1)
            else:
                S.append(-1)
    return sum

print(solution([1, 5, 2, -2]))