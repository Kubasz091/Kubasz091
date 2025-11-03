#include <stack>
#include <vector>

int solution(vector<int> &H) {
    std::stack<int> checker;
    int no_blocks = 0;

    for (auto it = H.begin(); it != H.end(); it++) {
        while (!checker.empty()) {
            if (checker.top() > *it) checker.pop();
            else break;
        }

        if (checker.empty() || checker.top() != *it){
            no_blocks++;
            checker.push(*it);
        }

    }

    return no_blocks;
}