#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> a;
vector<int> now, after;

int main() {
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    cin >> N;
    a.resize(N);
    now.resize(N);
    after.resize(N);

    for (int i=0; i<N; i++) cin >> a[i];
    for (int i=0; i<N; i++) cin >> now[i];

    for (int i=0; i<3; i++) {
        for (int k=0; k<N; k++) {
            after[k] = now[a[k]-1];
        }
        now = after;
        after = vector<int>(N);
    }

    for (int s : now) {
        cout << s << "\n";
    }
}