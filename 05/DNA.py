def solution(S, P, Q):
    S = list(S)
    vals = {'A': 1, 'C': 2, 'G': 3, 'T': 4}
    S = [vals[x] for x in S]

    occurence_list_1 = []
    occurence_list_2 = []
    occurence_list_3 = []
    occurence_list_4 = []

    occurence_1 = 0
    occurence_2 = 0
    occurence_3 = 0
    occurence_4 = 0

    for number in S:
        if number == 1:
            occurence_1 += 1
        elif number == 2:
            occurence_2 += 1
        elif number == 3:
            occurence_3 += 1
        elif number == 4:
            occurence_4 += 1
        occurence_list_1.append(occurence_1)
        occurence_list_2.append(occurence_2)
        occurence_list_3.append(occurence_3)
        occurence_list_4.append(occurence_4)

    occurence_list_1.insert(0, 0)
    occurence_list_2.insert(0, 0)
    occurence_list_3.insert(0, 0)
    occurence_list_4.insert(0, 0)

    print("occurence_list_1: ", occurence_list_1)
    print("occurence_list_2: ", occurence_list_2)
    print("occurence_list_3: ", occurence_list_3)
    print("occurence_list_4: ", occurence_list_4)

    M = len(P)
    ret_list = []
    for i in range(M):
        ixQ = Q[i] + 1
        ixP = P[i]
        if occurence_list_1[ixQ] != occurence_list_1[ixP]:
            ret_list.append(1)
        elif occurence_list_2[ixQ] != occurence_list_2[ixP]:
            ret_list.append(2)
        elif occurence_list_3[ixQ] != occurence_list_3[ixP]:
            ret_list.append(3)
        elif occurence_list_4[ixQ] != occurence_list_4[ixP]:
            ret_list.append(4)
    return ret_list

print(solution('CAGCCTA', [2, 5, 0], [4, 5, 6]))
