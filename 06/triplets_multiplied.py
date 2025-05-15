def solution(A):
    max_minus = [float('inf'), float('inf'), float('inf')]
    max_plus = [float('-inf'), float('-inf'), float('-inf')]

    for num in A:
        if num < max_minus[0]:
            max_minus[2] = max_minus[1]
            max_minus[1] = max_minus[0]
            max_minus[0] = num
        elif num < max_minus[1]:
            max_minus[2] = max_minus[1]
            max_minus[1] = num
        elif num < max_minus[2]:
            max_minus[2] = num

        if num > max_plus[0]:
            max_plus[2] = max_plus[1]
            max_plus[1] = max_plus[0]
            max_plus[0] = num
        elif num > max_plus[1]:
            max_plus[2] = max_plus[1]
            max_plus[1] = num
        elif num > max_plus[2]:
            max_plus[2] = num

    results = [
        max_plus[0] * max_plus[1] * max_plus[2],
        max_minus[0] * max_minus[1] * max_plus[0],
        max_minus[0] * max_plus[0] * max_plus[1],
        max_minus[0] * max_minus[1] * max_minus[2]
    ]
    max_mult = float('-inf')
    for i in results:
        if i > max_mult:
            max_mult = i

    # max_minus.extend(max_plus)
    # biggest_nums = max_minus
    # biggest_nums = [x for x in biggest_nums if x is not None]

    # def return_count(list_in):
    #     min_n = 1001
    #     max_n = -1001
    #     for i in list_in:
    #         min_n = min(min_n, i)
    #         max_n = max(max_n, i)

    #     counts = [0] * (max_n - min_n + 1)
    #     for i in list_in:
    #         counts[i-min_n] += 1
    #     return min_n, max_n, counts

    # min_a, _, counts_a = return_count(A)
    # min_bn, _, counts_bn = return_count(biggest_nums)

    # for i in biggest_nums:
    #     if counts_bn[i-min_bn] != counts_a[i-min_a]:
    #         biggest_nums.remove(i)
    #         min_bn, _, counts_bn = return_count(biggest_nums)

    # results = []
    # for i in range(len(biggest_nums)):
    #     for n in range(min(i+1, len(biggest_nums)), len(biggest_nums)):
    #         for l in range(min(n+1, len(biggest_nums)), len(biggest_nums)):
    #             results.append(biggest_nums[i]*biggest_nums[n]*biggest_nums[l])
    return max_mult

print(solution([-2, -2, 1, -1, 2, 2]))