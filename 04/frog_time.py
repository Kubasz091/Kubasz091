def solution_too_slow(X, A):
    need_leaf = list(range(1, X+1))
    time = None
    for n, i in enumerate(A):
        try:
            need_leaf.remove(i)
        except:
            pass
        if len(need_leaf) == 0:
            time = n
            break
    print(need_leaf)
    return time

def solution(X, A):
    A_set = list(dict.fromkeys(A.copy()))
    A_sorted_set = list(set(sorted(A.copy())))
    if A_sorted_set[-1] < X:
        return -1
    else:
        idx_A_set = A_sorted_set.index(X)
        if idx_A_set == X-1:
            num = [x for x in A_set if x <= X][-1]
            return A.index(num)
        else:
            return -1

# nie skumałem że w A nie może być wiecej niż X, wtedy to lepsze:
def solution_chat(X, A):
    positions = set()
    for t, pos in enumerate(A):
        if pos <= X:
            positions.add(pos)
            if len(positions) == X:
                return t
    return -1

# print(solution(5, [1, 3, 1, 4, 2, 3, 5, 4]))
print(solution(3, [1, 3, 1, 3, 2, 1, 3]))