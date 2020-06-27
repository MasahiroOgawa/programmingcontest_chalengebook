#include <iostream>
#include <queue>  //for priority_queue
#include <vector>

using namespace std;

int main() {
    // inputs
    int L = 25;
    int P = 10;
    vector<int> A{10, 14, 20, 21};
    vector<int> B{10, 5, 2, 4};

    // solve
    int num_supply = 0;
    int current_pos = 0;
    int tank = P;

    // add goal
    A.push_back(L);
    B.push_back(0);

    priority_queue<int> que;

    for (unsigned int i = 0; i < A.size(); ++i) {
        int trip = A[i] - current_pos;

        // supply
        while (tank - trip < 0) {
            if (que.empty()) {
                num_supply = -1;
                return -1;
            }

            tank += que.top();
            que.pop();
            ++num_supply;
        }

        // after reached Ai
        tank -= trip;
        current_pos = A[i];
        que.push(B[i]);
    }

    cout << "minimum number of supply = " << num_supply << endl;
    return 0;
}
