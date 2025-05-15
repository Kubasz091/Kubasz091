def solution(A):
    look_for = A[0]
    count = 0
    multiplayer = 0
    for bit in A:
        if count > 1000000000:
            return -1
        if bit is not look_for:
            count += multiplayer
        else:
            multiplayer += 1
    return count

print(solution([0, 1, 0, 1, 1]))