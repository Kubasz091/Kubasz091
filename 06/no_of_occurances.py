def solution(A):
    min_a = 1000001
    max_a = -1000001
    for i in A:
        if i < min_a:
            min_a = i
        if i > max_a:
            max_a = i

    counts = [0] * (max_a - min_a + 1)
    for i in A:
        counts[i-min_a] = 1

    count = 0
    for i in counts:
        if i == 1:
            count += 1

    return count

# print(solution([2, 1, 1, 2, 3, 1]))