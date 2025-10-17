#include <algorithm>
#include <iostream>

vector<int> quickSort(vector<int> &A, vector<int> indexes);
vector<int> applyIndexes(vector<int> &input, vector<int> &indexes);

int solution(vector<int> &A) {
    vector<int> indexes, sorted_idx;

    for (unsigned int i = 0; i < A.size(); i++) {
        indexes.push_back(i);
    }

    sorted_idx = quickSort(A, indexes);

    std::cout << "[";
    for (const int idx : sorted_idx) {
        std::cout << idx << ", ";
    }
    std::cout << "\b]";
}

vector<int> quickSort(vector<int> &A, vector<int> indexes) {
    vector<int>::iterator i = indexes.begin() - 1, j = indexes.begin(), pivot = indexes.end()-1;

    int temp = 0;

    for (; j != pivot; j++) {
        if (A[*j] < A[*pivot]) {
            i++;
            temp = *i;
            *i = *j;
            *j = temp;
        }
    }
    i++;
    temp = *i;
    *i = *j;
    *j = temp;

    if (indexes.size() > 2) {
        pivot = i;

        if (pivot - 2 >= indexes.begin()) {
            vector<int> indexes_left(indexes.begin(), pivot-1);
            indexes_left = quickSort(A, indexes_left);

            std::swap_ranges(indexes_left.begin(), indexes_left.end(), indexes.begin());
        }
        if (pivot + 2 < indexes.end()) {
            vector<int> indexes_right(pivot+1, indexes.end());
            indexes_right = quickSort(A, indexes_right);

            std::swap_ranges(indexes_right.begin(), indexes_right.end(), pivot+1);
        }
    }

    return indexes;
}

vector<int> applyIndexes(vector<int> &input, vector<int> &indexes) {
    vector<int> result;

    for (const int idx : indexes) {
        result.push_back(input[idx]);
    }

    return result;
}