def solution(A):
    if len(A) == 2:
        return 0
    slices_2 = [(A[x] + A[x+1])/2 for x in range(len(A)-1)]
    slices_3 = [(A[x] + A[x+1] + A[x+2])/3 for x in range(len(A)-2)]

    min_2 = min(slices_2)
    min_3 = min(slices_3)

    if min_2 < min_3:
        return slices_2.index(min_2)
    elif min_3 < min_2:
        return slices_3.index(min_3)
    else:
        return min(slices_2.index(min_2), slices_3.index(min_3))