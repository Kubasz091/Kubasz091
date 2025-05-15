def solution(S):
    # spike, square, round
    bracket_count = [0, 0, 0]
    val_dict = {'{': (1, 0), '}': (-1, 0), '[': (1, 1), ']': (-1, 1), '(': (1, 2), ')': (-1, 2)}
    curr_seq = []
    for char in S:
        curr_seq.append(char)
        add, place = val_dict[char]
        bracket_count[place] += add

        closed = True
        for i in bracket_count:
            if i != 0:
                closed = False
        if closed:
            if len(curr_seq) % 2 != 0:
                return 0
            split_1 = curr_seq[:int(len(curr_seq)/2)]
            split_2 = curr_seq[int(len(curr_seq)/2):]

            split_2.reverse()
            for i, char in enumerate(split_1):
                if char == '{':
                    if split_2[i] != '}':
                        return 0
                elif char == '[':
                    if split_2[i] != ']':
                        return 0
                elif char == '(':
                    if split_2[i] != ')':
                        return 0

            curr_seq = []
    for count in bracket_count:
        if count != 0:
            return 0
    return 1

print(solution('{[()()]}'))

# str1 = '([)()]'

# str2 = str1[:3]
# str3 = str1[3:]

# print(str2)
# print(str3)

print(solution('([)()]'))