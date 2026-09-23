# Bovine Shuffle
Link: https://usaco.org/index.php?page=viewproblem2&cpid=760

Type: Simulation

Difficulty: Easy

# Solution
We want to work backwards, which may seem difficult at first. However, notice that a cow at position $i$ will move to position $a_i$. So, in order to reverse it, a cow at $a_i$ should move to position $i$.

When stepping a cow at position $i$ will move to $a_i$. We just need to move a cow at $a_i$ to $i$.

For example, given $a=\{5, 4, 3, 2, 1\}$, taking one step forward would move the cow at position 1 to position 5. To go backwards, we find that cows in position 1 will always go to position 5, so we move the cow to position 1.

```cpp
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

    // reverse 3 steps
    for (int i=0; i<3; i++) {

        // go thru each cow
        for (int k=0; k<N; k++) {
            // move cow at a_i to i
            after[k] = now[a[k]-1];
        }

        now = after;
        after = vector<int>(N);
    }

    // go thru each cow in array now
    for (int s : now) {
        cout << s << "\n";
    }
}
```