def solution_77_PERCENT(N, A):
    bigger = [0 if x <= N else 1 for x in A]
    numbers_split = [[]]
    numbers_unsplit = []
    ones_idxs = []

    return_counters = [0 for i in range(N)]

    for i, num in enumerate(bigger):
        if num == 0:
            numbers_unsplit.append(A[i])
            numbers_split[-1].append(A[i])
        else:
            if len(numbers_split[-1]) != 0:
                numbers_split.append([])
            ones_idxs.append(i)

    def count(split):
        split_set = list(set(split))
        counts = [split.count(x) for x in split_set]
        return split_set, counts

    biggest_count = 0
    for n, split in enumerate(numbers_split):
        if len(split) == 0:
            max_count = max(return_counters)
            return_counters = [max_count for i in range(N)]
        else:
            if n == len(numbers_split)-1:
                if len(ones_idxs) != 0 and ones_idxs[-1] == len(A)-1:
                    split_set, counts = count(split=split)
                    max_count = max(counts) + max(return_counters)
                    return_counters = [max_count for i in range(N)]
                else:
                    split_set, counts = count(split)
                    for n, i in enumerate(split_set):
                        return_counters[i-1] += counts[n]
            else:
                split_set, counts = count(split=split)
                max_count = max(counts) + max(return_counters)
                return_counters = [max_count for i in range(N)]
    return return_counters

def solution_100_PERCENT(N, A):
    bigger = [0 if x <= N else 1 for x in A]
    numbers_split = [[]]
    numbers_unsplit = []
    ones_idxs = []

    return_counters = [0] * N

    for i, num in enumerate(bigger):
        if num == 0:
            numbers_unsplit.append(A[i])
            numbers_split[-1].append(A[i])
        else:
            if len(numbers_split[-1]) != 0:
                numbers_split.append([])
            ones_idxs.append(i)

    if len(numbers_split[-1]) == 0:
        numbers_split.pop()

    def count(split):
        split_set = list(set(split))
        counts = [split.count(x) for x in split_set]
        return split_set, counts

    biggest_count = 0
    for n, split in enumerate(numbers_split):
        if len(split) == 0:
            pass
        else:
            if n == len(numbers_split)-1:
                if len(ones_idxs) != 0 and ones_idxs[-1] == len(A)-1:
                    split_set, counts = count(split=split)
                    max_count = biggest_count + max(counts)
                    return_counters = [max_count] * N
                else:
                    split_set, counts = count(split)
                    return_counters = [biggest_count] * N
                    for n, i in enumerate(split_set):
                        return_counters[i-1] += counts[n]
            else:
                split_set, counts = count(split=split)
                biggest_count += max(counts)
    return return_counters

def solution(N, A):
    bigger = [0 if x <= N else 1 for x in A]
    ones_idxs = []

    for i, num in enumerate(bigger):
        if num == 1:
            ones_idxs.append(i)
        else:
            pass

    return_counters = [0] * N
    print(return_counters)
    for i, num in enumerate(A):
        if num <= N:
            return_counters[num-1] += 1
        elif num > N and (i+1) not in ones_idxs:
            max_count = max(return_counters)
            return_counters = [max_count]*N
    return return_counters
print(solution_100_PERCENT(5, [1, 2, 3, 4, 5, 6, 6, 6, 6, 6, 6]))
