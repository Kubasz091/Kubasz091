#include <stack>

int solution(string &S) {
    std::string::iterator it = S.begin();

    std::stack<char> checker;
    char poped;

    while (it != S.end()) {
        if (*it == '(') checker.push(*it);
        else if (*it == ')') {
            if (checker.empty()) return 0;
            poped = checker.top(); checker.pop();
            if (poped != '(') return 0;
        }
        it++;
    }

    if (checker.empty()) return 1;
    else return 0;
}