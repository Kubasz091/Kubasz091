import math

def solution_passed_but_onoptimal(N):
    def get_highest_2_pow(number):
            if number >= 2:
                pow = 2
                while pow <= number:
                    pow = pow*2
                return int(pow/2)
            else:
                if number == 1:
                    return 1
                else:
                    return 0

    binary_num = []
    biggest_pow = get_highest_2_pow(N)
    last_pow = get_highest_2_pow(N)

    vec_len = int(math.log(get_highest_2_pow(N), 2))

    iteration = 1
    while len(binary_num) < vec_len:
        if N == 0:
            break

        if len(binary_num) != (int(math.log(biggest_pow, 2)) - int(math.log(get_highest_2_pow(N), 2))):
            binary_num.append(0)
        else:
            binary_num.append(1)
            last_pow = get_highest_2_pow(N)
            N = N - last_pow

        iteration = iteration + 1
    binary_num.append(int(N))

    for i in range(vec_len - len(binary_num) + 1):
        binary_num.append(0)

    possible = []
    detected = False

    bin_len = len(binary_num)

    for n, i in enumerate(binary_num):

        if n == bin_len-1 and i == 0:
            possible.remove(possible[-1])
            break

        if i == 1 and len(possible) == 0 and detected is False:
            possible.append([])
            detected = True
        elif i == 1 and detected is True:
            possible.append([])
        elif i == 0 and detected is True:
            possible[-1].append(0)

    numbers = []
    for item in possible:
        numbers.append(len(item))

    if len(possible) != 0:
        return max(numbers)
    else:
        return 0

def solution(N):
    binary_str = bin(N)[2:]
    print("binary_str1: ", binary_str)

    binary_str = binary_str.strip('0')
    print("binary_str2: ", binary_str)

    gaps = binary_str.split('1')
    print("gaps: ", gaps)
    return max(map(len, gaps)) if gaps else 0