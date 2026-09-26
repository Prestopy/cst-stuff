// https://usaco.org/index.php?page=viewproblem2&cpid=616
// 10/10 ALL PASS

#include <iostream>
#include <vector>
using namespace std;

int N;
int best = -1;
int total;
vector<int> r;

int test(int start) {
    int sum = 0;
    
    int curr = start;
    int ps = total;

    while (ps > 0) {
        ps -= r[curr];
        sum += ps;
        curr = (curr+1) % N;
    }

    return sum;
}

int main() {
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    cin >> N;
    r.resize(N);
    for (int i=0; i<N; i++) {
        cin >> r[i];
        total += r[i];
    }

    for (int i=0; i<N; i++) {
        if (best == -1) best = test(i);
        else best = min(test(i), best);
    }
    cout << best;
}