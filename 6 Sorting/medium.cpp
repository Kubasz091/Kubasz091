#include <vector>
#include <iostream>

void mergeSort(std::vector<int> &A);
void printVector(const std::vector<int> &A);
int silnia_sum(int num);

int solution(std::vector<int> &A) { // a problem with arithemitc overfloaw so 93% overall, but i cannot fix it for some reason (i suspect that the whole merge sort and solution should be in long long ints)
    std::vector<int> beginings, ends;

    for (int i = 0; i < A.size(); i++) {
        beginings.push_back(i-A[i]);
        ends.push_back(i+A[i]);
    }

    mergeSort(beginings);
    mergeSort(ends);

    int active = 0,
        result = 0,
        this_iter_val = 0,
        this_iter_change = 0;

    std::vector<int>::iterator it_begining = beginings.begin(),
                               it_end = ends.begin();


    while (true) {
        if (result > 10000000) return -1;
        if (it_begining == beginings.end()) break;

        this_iter_change = 0;

        if (*it_end >= *it_begining) {
            this_iter_val = *it_begining;

            while (it_begining != beginings.end() && *it_begining == this_iter_val) {
                this_iter_change++;
                it_begining++;
            }
            result += (active * this_iter_change) + silnia_sum(this_iter_change-1);
        }
        else if (*it_end < *it_begining) {
            this_iter_val = *it_end;

            while (it_end != ends.end() && *it_end == this_iter_val) {
                this_iter_change--;
                it_end++;
            }
        }

        active += this_iter_change;
    }
    return result;
}

int main() {
    std::vector<int> test1 = {1, 2147483647, 0}; // 11

    std::cout << "in: ";
    printVector(test1);

    std::cout << "out: " << solution(test1) << std::endl;

    // std::cout << "silnia test: silni_sum(5) = " << silnia_sum(5-1);

}



int silnia_sum(int num) {
    if (num==0) return 0;
    return num + silnia_sum(num-1);
}

void printVector(const std::vector<int> &A) {
    std::cout << "[";
    for (const int num : A){
        std::cout << num << ", ";
    }
    std::cout << "\b\b]\n";
}

void mergeSort(std::vector<int> &A) {
    if (A.size() < 2) return;

    std::vector<int> left,
                    right;

    unsigned int middle = A.size()/2;

    for (unsigned int i = 0; i < middle; i++) left.push_back(A[i]);
    for (unsigned int i = middle; i < A.size(); i++) right.push_back(A[i]);

    mergeSort(left);
    mergeSort(right);


    std::vector<int>::iterator it_l = left.begin(),
                              it_r = right.begin();

    for (unsigned int i = 0; i < A.size(); i++) {
        if (it_l == left.end() && it_r == right.end()) break;
        else if (it_l == left.end()) {
            A[i] = *it_r;
            it_r++;
        }
        else if (it_r == right.end()) {
            A[i] = *it_l;
            it_l++;
        }
        else {
            if (*it_l <= *it_r) {
                A[i] = *it_l;
                it_l++;
            }
            else {
                A[i] = *it_r;
                it_r++;
            }
        }
    }
}