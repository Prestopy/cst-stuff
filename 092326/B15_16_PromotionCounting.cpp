// https://usaco.org/index.php?page=viewproblem2&cpid=591
// 10/10 ALL PASS

#include <iostream>
using namespace std;

int before[4], after[4];
int ans[3];

int main() {
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);
    int participants = 0, participantsBefore = 0;;
    for (int i=0; i<4; i++) {
        cin >> before[i] >> after[i];
        participantsBefore += before[i];
        participants += after[i];
    }
    before[0] += participants - participantsBefore;

    for (int i=0; i<3; i++) {
        // go from i -> i+1
        if (before[i] > after[i]) {
            int diff = before[i] - after[i];
            ans[i] += diff;

            before[i] -= diff;
            before[i+1] += diff;
        }
    }

    cout << ans[0] << "\n" << ans[1] << "\n" << ans[2];
}