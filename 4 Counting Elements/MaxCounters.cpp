#include <vector>

std::vector<int> solution(int N, std::vector<int> &A) { // passed for 100% but the second option is more optimal (does not require sorting)
    std::vector<int> counters(N, 0), last_updated(N, 0);

    int max_counter_val = 0,
        bring_up_val = 0,
        vector_len = A.size(),
        operation = 0,
        non_max_operations = 0,
        action_num = 0;

    for (; action_num < vector_len; action_num++) {
        operation = A[action_num];

        if (operation == N+1) {
            non_max_operations=0;
            bring_up_val = max_counter_val;
        }
        else if (operation <= N) {
            counters[operation-1] = (last_updated[operation-1] < action_num - 1 - non_max_operations) ? bring_up_val+1 : counters[operation-1]+1;
            last_updated[operation-1] = action_num;

            non_max_operations++;

            if (counters[operation-1] > max_counter_val) max_counter_val = counters[operation-1];
        }
        // else there was an error
    }

    for (int i = 0; i < N; i++) {
        if (last_updated[i] < action_num - 1 - non_max_operations) counters[i] = bring_up_val;
    }

    return counters;
}

