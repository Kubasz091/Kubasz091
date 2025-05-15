def solution(A):
    highest_sum = A[0]
    curr_sum = 0

    for number in A:
        curr_sum += number

        highest_sum = max(highest_sum, curr_sum)

        if curr_sum < number:
            curr_sum = number

    return highest_sum

print(solution([-2, 1]))