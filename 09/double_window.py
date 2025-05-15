def solution(A):
    highest_sum = 0

    no_into_curr_sum = 0
    curr_sum = 0

    curr_min_num = None

    for number in A:
        if no_into_curr_sum > 2:
            highest_sum = max(highest_sum, curr_sum-curr_min_num)

        if curr_sum < 0:
            no_into_curr_sum = 0
            curr_min_num = None
            curr_sum = 0

        if no_into_curr_sum > 0:
            curr_sum += number
            if curr_min_num is None or curr_min_num > number:
                curr_min_num = number
        no_into_curr_sum += 1

    return highest_sum