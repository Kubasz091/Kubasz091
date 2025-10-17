#include <cmath>
#include <iostream>

int solution(vector<int> &A) {
    vector<int> prefix_sums;

    int best_start = 0, curr_sum = 0, vec_len = A.size();

    for (const int &num : A) {
        prefix_sums.push_back(curr_sum);
        curr_sum += num;
    }
    prefix_sums.push_back(curr_sum);

    std::cout << '[';
    for (const int &num : prefix_sums) std::cout << num << ", ";
    std::cout << ']' << '\n';

    std::cout << "vec_len: " << vec_len << '\n';

    double min_avg = MAXFLOAT, curr_avg;
    for (int i = 0; i < vec_len; i++){
        for (int j = vec_len-1; j > 1 && j > i+1; j--) {
            curr_avg = (double) (prefix_sums[j+1]-prefix_sums[i])/(j+1-i);
            if ( curr_avg < min_avg) {
                min_avg = curr_avg;
                best_start = i;
            }
        }
    }

    return best_start;
}
