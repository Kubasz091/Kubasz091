#include <vector>

const int MAXCOUNT = 1e9;

int solution(std::vector<int> &A) {
    int counted_zeros = 0, result = 0;

    for (const int car : A) {
        if (car) result += counted_zeros;
        else counted_zeros++;

        if (result > MAXCOUNT){
            result = -1;
            break;
        }
    }

    return result;
}