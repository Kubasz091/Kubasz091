#include <cstdlib>
#include <iostream>

int solution(vector<int> &A) {
    int min = 1000,
        max = -1000,
        pos_2_sel = 3,
        neg_2_sel = 3,
        result_w_neg = 1,
        result_from_back = 1;

    for (const int num : A) {
        min = (num < min) ? num : min;
        max = (num > max) ? num : max;
    }

    vector<int> counts(max - min + 1, 0);

    for (const int num : A) counts[num - min]++;

    // delete this section
    // std::cout << "counts.size() = " << counts.size() << '\n';

    // vector<int>::iterator it_out = counts.begin();
    // for (int i = min; it_out != counts.end(); i++, it_out++) {
    //     if (*it_out > 0) std::cout << "Counted " << i << " [" << *it_out << " times]\n";
    // }


    vector<int>::iterator it = counts.begin();
    for (int i = min; i < 0 && it != counts.end() && neg_2_sel > 1; i++, it++) {
        for (int j = 0; j < 2 && j < *it && neg_2_sel > 1; j++) {
            neg_2_sel--;
            result_w_neg *= i;
        }
    }

    vector<int>::reverse_iterator rit = counts.rbegin();
    for (int i = max; rit != counts.rend() && pos_2_sel > 0; i--, rit++) {
        for (int j = 0; j < 3 && j < *rit && pos_2_sel > 0; j++) {
            if (neg_2_sel > 0) {
                neg_2_sel--;
                result_w_neg *= i;
            }

            pos_2_sel--;
            result_from_back *= i;
        }
    }

    if ((neg_2_sel == 0 && pos_2_sel == 0) || (neg_2_sel != 0 && pos_2_sel != 0)) return (result_w_neg > result_from_back) ? result_w_neg : result_from_back;
    else if (neg_2_sel == 0) return result_from_back;
    else if (pos_2_sel == 0) return result_w_neg;

    return 0;
}