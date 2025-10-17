#include <execution>
#include <iostream>
#include <map>

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) { // entirely mine solution, but unoptimal 0% for performance
    const std::map<char, int> mapping = {
        {'A', 1},
        {'C', 2},
        {'G', 3},
        {'T', 4}
    };

    vector<char> sequence;
    vector<int> result;
    int vec_len = P.size(), curr_lowest = 5, int_map;

    std::cout << S << '\n';

    for (char &ch : S) {
        int_map = mapping.at(ch);
        sequence.push_back(int_map);
    }

    std::cout << '[';
    for (const int &num : sequence) std::cout << num << ", ";
    std::cout << ']' << '\n';

    for (int i = 0; i < vec_len; i++) {
        std::cout << "Searching for the " << i+1 << " pair\n";

        for (int j = P[i]; j <= Q[i]; j++) {
            curr_lowest = (sequence[j] < curr_lowest) ? sequence[j] : curr_lowest;
            std::cout << "\tjust checked the " << j << " index = " << (int)sequence[j] << '\n';
        }

        result.push_back(curr_lowest);

        curr_lowest = 5;
    }

    return result;
}

vector<int> solution2(string &S, vector<int> &P, vector<int> &Q) { // zmienione przezemnie po przeczytaniu pdf z codility
    const std::map<char, int> mapping = {
        {'A', 1},
        {'C', 2},
        {'G', 3},
        {'T', 4}
    };

    vector<int> occurances[4], result;

    int vec_len = P.size(),
        int_map = 0,
        occurances_counts[] = {0, 0, 0, 0};

    std::cout << S << '\n';

    for (char &ch : S) {
        for (int i = 0; i < 4; i++) occurances[i].push_back(occurances_counts[i]);

        int_map = mapping.at(ch);
        occurances_counts[int_map-1]++;
    }
    for (int i = 0; i < 4; i++) occurances[i].push_back(occurances_counts[i]);

    for (const auto &occurance : occurances){
        std::cout << '[';
        for (const int &num : occurance) std::cout << num << ", ";
        std::cout << ']' << '\n';
    }

    for (int i = 0; i < vec_len; i++) {
        for (int j = 0; j < 4; j++) {
            if (occurances[j][Q[i]+1] > occurances[j][P[i]]) {
                result.push_back(j+1);
                break;
            }
        }
    }

    return result;
}
