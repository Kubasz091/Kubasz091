#include <stack>
int solution(vector<int> &A, vector<int> &B) {
    std::vector<int>::iterator it_A = A.begin(), it_B = B.begin();

    std::stack<int> down_swimmers;

    int survived = 0;

    while (it_A != A.end() && it_B != B.end()) {
        if (*it_B) down_swimmers.push(*it_A);
        else {
            while (!down_swimmers.empty()){
                if (down_swimmers.top() < *it_A) down_swimmers.pop();
                else break;
            }
            if (down_swimmers.empty()) survived++;
        }
        it_A++; it_B++;
    }

    return  survived + down_swimmers.size();
}