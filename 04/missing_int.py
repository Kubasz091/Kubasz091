def solution(A):
    a_pos = [x for x in A if x > 0]
    a_sor = sorted(list(set(a_pos)))
    prev = 0
    try:
        if a_sor[0] != 1:
            return 1
    except:
        return 1
    for i in a_sor:
        if i > prev+1:
            break
        else:
            prev = i
    return prev+1

A = [1, 2, 4, 5, 6]
solution(A)