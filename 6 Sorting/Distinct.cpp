#include <iostream>
#include <vector>

void mergeSort(std::vector<int> &A);

void mergeSortChatImproved(std::vector<int> &A, std::vector<int> &buffer, std::size_t left, std::size_t right);


int solution(std::vector<int> &A) {
    // std::cout << '[';
    // for (const int num : A) std::cout << num << ", ";
    // std::cout << ']' << '\n';

    // mergeSort(A);

    // std::cout << '[';
    // for (const int num : A) std::cout << num << ", ";
    // std::cout << ']' << '\n';

    mergeSort(A);

    int distinct_val = (int) (A.size() != 0), curr_val = (A.size() != 0) ? A[0] : 0;

    for (const int num : A) {
        if (num != curr_val) {
            distinct_val++;
            curr_val = num;
        }
    }

    return distinct_val;
}

int solutionChat(std::vector<int> &A) {
    // Change: handle empty input early and drop C-style cast.
    if (A.empty()) return 0;

    std::vector<int> buffer(A.size());
    mergeSortChatImproved(A, buffer, 0, A.size());

    int distinct_val = 1;
    int curr_val = A[0];

    for (const int num : A) {
        if (num != curr_val) {
            ++distinct_val;
            curr_val = num;
        }
    }

    return distinct_val;
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

// Change: recursive helper works on index range to avoid copying subvectors.
void mergeSortChatImproved(std::vector<int> &A, std::vector<int> &buffer, std::size_t left, std::size_t right) {
    if (right - left < 2) return;                     // Range of size 0 or 1 is already sorted.

    const std::size_t mid = left + (right - left) / 2; // Split current range in half.
    mergeSortChatImproved(A, buffer, left, mid);       // Recursively sort left half [left, mid).
    mergeSortChatImproved(A, buffer, mid, right);      // Recursively sort right half [mid, right).

    // Copy left half into buffer so we can overwrite A without losing the left values.
    std::copy(A.begin() + left, A.begin() + mid, buffer.begin() + left);

    std::size_t i = left; // Reads from buffer (left half).
    std::size_t j = mid;  // Reads from A (right half).
    std::size_t k = left; // Writes merged results back into A.

    // Merge while there are elements in the combined range.
    while (k < right) {
        // Take from left if it still has elements and either right is exhausted or left value <= right value.
        if (i < mid && (j >= right || buffer[i] <= A[j])) {
            A[k++] = buffer[i++]; // Copy from buffer and advance left reader & writer.
        } else {
            A[k++] = A[j++];      // Copy from right half and advance right reader & writer.
        }
    }
}