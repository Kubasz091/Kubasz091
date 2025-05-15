def solution(A):
    i_D = 0
    count_space = [0] * len(A)
    for J in range(len(A)):
        if A[J] == 0:
            count_space[J] += 1
        else:
            for i in range(max(J-A[J]+1, 0), min(J+A[J]-1, len(A)-1)+1):
                print('pos: ', J, " insterting at: ", i)
                # i_D += 1
                # if (i_D > 10000000):
                #     return -1
                count_space[i] += 1
        print("----------")

    for i in range(len(count_space)):
        count_space[i] -= 1
    return count_space

ret = solution([1, 5, 2, 1, 4, 0])
print(ret, sum(ret))

# buffor = 0
# sum_test = 0
# for n, i in enumerate(ret):
#     if buffor > 0:
#         sum_test += 1
#         buffor -= 1
#     sum_test += i - buffor
#     buffor += i-1
#     print(n, "  :  ", sum_test)


